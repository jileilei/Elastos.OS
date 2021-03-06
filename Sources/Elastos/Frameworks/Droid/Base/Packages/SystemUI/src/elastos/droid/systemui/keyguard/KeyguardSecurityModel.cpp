//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#include "elastos/droid/systemui/keyguard/KeyguardSecurityModel.h"
#include "elastos/droid/systemui/keyguard/KeyguardUpdateMonitor.h"
#include <Elastos.Droid.App.h>
#include <Elastos.Droid.Telephony.h>
#include <Elastos.Droid.Internal.h>
#include <elastos/utility/logging/Logger.h>
#include <elastos/droid/ext/frameworkext.h>

using Elastos::Droid::App::Admin::IDevicePolicyManager;
using Elastos::Droid::App::IProfileLockMode;
using Elastos::Droid::Telephony::ITelephonyManager;
using Elastos::Droid::Internal::Widget::CLockPatternUtils;
using Elastos::Droid::Internal::Telephony::IccCardConstantsState;
using Elastos::Droid::Internal::Telephony::IccCardConstantsState_UNKNOWN;
using Elastos::Droid::Internal::Telephony::IccCardConstantsState_PIN_REQUIRED;
using Elastos::Droid::Internal::Telephony::IccCardConstantsState_PUK_REQUIRED;
using Elastos::Utility::Logging::Logger;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace Keyguard {

static const String TAG("KeyguardSecurityModel");

CAR_INTERFACE_IMPL(KeyguardSecurityModel, Object, IKeyguardSecurityModel)

KeyguardSecurityModel::KeyguardSecurityModel(
    /* [in] */ IContext* context)
    : mContext(context)
{
    CLockPatternUtils::New(context, (ILockPatternUtils**)&mLockPatternUtils);
}

ECode KeyguardSecurityModel::SetLockPatternUtils(
    /* [in] */ ILockPatternUtils* utils)
{
    mLockPatternUtils = utils;
    return NOERROR;
}

ECode KeyguardSecurityModel::IsBiometricUnlockEnabled(
    /* [out] */ Boolean* result)
{
    VALIDATE_NOT_NULL(result)

    Boolean res1, res2;

    *result = (mLockPatternUtils->UsingBiometricWeak(&res1), res1)
                && (mLockPatternUtils->IsBiometricWeakInstalled(&res2), res2);
    return NOERROR;
}

Boolean KeyguardSecurityModel::IsBiometricUnlockSuppressed()
{
    AutoPtr<IKeyguardUpdateMonitor> monitor = KeyguardUpdateMonitor::GetInstance(mContext);
    Int32 res;
    Boolean backupIsTimedOut = (monitor->GetFailedUnlockAttempts(&res), res) >=
            ILockPatternUtils::FAILED_ATTEMPTS_BEFORE_TIMEOUT;

    Boolean res1, res2;
    Int32 state;

    return (monitor->GetMaxBiometricUnlockAttemptsReached(&res1), res1) || backupIsTimedOut
            || (monitor->IsAlternateUnlockEnabled(&res2), !res2)
            || (monitor->GetPhoneState(&state), state) != ITelephonyManager::CALL_STATE_IDLE;
}

ECode KeyguardSecurityModel::GetSecurityMode(
    /* [out] */ SecurityMode* outmode)
{
    VALIDATE_NOT_NULL(outmode)
    *outmode = SecurityMode_None;

    SecurityMode mode = SecurityMode_None;

    AutoPtr<IKeyguardUpdateMonitor> updateMonitor = KeyguardUpdateMonitor::GetInstance(mContext);
    IccCardConstantsState simState;
    updateMonitor->GetSimState(&simState);

    // IccCardConstantsState simState = IccCardConstantsState_UNKNOWN;
    // for (Int32 i = 0; i < updateMonitor->GetNumPhones(); i++) {
    //     Int64 subId;
    //     updateMonitor->GetSubIdByPhoneId(i, &subId);
    //     updateMonitor->GetSimState(subId, &simState);
    //     if (simState == IccCardConstantsState_PIN_REQUIRED
    //         || simState == IccCardConstantsState_PUK_REQUIRED) {
    //         break;
    //     }
    // }

    Boolean res;
    Int32 data;
    if (simState == IccCardConstantsState_PIN_REQUIRED) {
        mode = SecurityMode_SimPin;
    }
    else if (simState == IccCardConstantsState_PUK_REQUIRED
            && (mLockPatternUtils->IsPukUnlockScreenEnable(&res), res)) {
        mode = SecurityMode_SimPuk;
    }
    else if ((mLockPatternUtils->GetActiveProfileLockMode(&data), data) != IProfileLockMode::INSECURE) {
        Int32 security;
        mLockPatternUtils->GetKeyguardStoredPasswordQuality(&security);
        switch (security) {
            case IDevicePolicyManager::PASSWORD_QUALITY_NUMERIC:
            case IDevicePolicyManager::PASSWORD_QUALITY_NUMERIC_COMPLEX:
                mode = (mLockPatternUtils->IsLockPasswordEnabled(&res), res) ?
                        SecurityMode_PIN : SecurityMode_None;
                break;
            case IDevicePolicyManager::PASSWORD_QUALITY_ALPHABETIC:
            case IDevicePolicyManager::PASSWORD_QUALITY_ALPHANUMERIC:
            case IDevicePolicyManager::PASSWORD_QUALITY_COMPLEX:
                mode = (mLockPatternUtils->IsLockPasswordEnabled(&res), res) ?
                        SecurityMode_Password : SecurityMode_None;
                break;
            case IDevicePolicyManager::PASSWORD_QUALITY_SOMETHING:
            case IDevicePolicyManager::PASSWORD_QUALITY_UNSPECIFIED:
                if (mLockPatternUtils->IsLockPatternEnabled(&res), res) {
                    mode = (mLockPatternUtils->IsPermanentlyLocked(&res), res) ?
                        SecurityMode_Account : SecurityMode_Pattern;
                }
                break;
            default:
                Logger::E(TAG, "Unknown security quality:%d", security);
                return E_ILLEGAL_STATE_EXCEPTION;
        }
    }

    *outmode = mode;
    return NOERROR;
}

ECode KeyguardSecurityModel::GetAlternateFor(
    /* [in] */ SecurityMode mode,
    /* [out] */ SecurityMode* outmode)
{
    VALIDATE_NOT_NULL(outmode)
    Boolean res;
    if ((IsBiometricUnlockEnabled(&res), res) && !IsBiometricUnlockSuppressed()
            && (mode == SecurityMode_Password
                    || mode == SecurityMode_PIN
                    || mode == SecurityMode_Pattern)) {
        *outmode = SecurityMode_Biometric;
        return NOERROR;
    }
    *outmode = mode; // no alternate, return what was given
    return NOERROR;
}

ECode KeyguardSecurityModel::GetBackupSecurityMode(
    /* [in] */ SecurityMode mode,
    /* [out] */ SecurityMode* outmode)
{
    VALIDATE_NOT_NULL(outmode)

    switch(mode) {
        case SecurityMode_Biometric:
            return GetSecurityMode(outmode);
        case SecurityMode_Pattern:
            *outmode = SecurityMode_Account;
            return NOERROR;
    }
    *outmode = mode; // no backup, return current security mode
    return NOERROR;
}

} // namespace Keyguard
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos
