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

#include <Elastos.CoreLibrary.Utility.h>
#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/media/audiofx/CAutomaticGainControl.h"
#include "elastos/droid/media/audiofx/CAudioEffectHelper.h"
#include "elastos/droid/media/audiofx/AudioEffect.h"

using Elastos::Utility::IUUIDHelper;
using Elastos::Utility::CUUIDHelper;

namespace Elastos {
namespace Droid {
namespace Media {
namespace Audiofx {

const String CAutomaticGainControl::TAG("AutomaticGainControl");

CAR_INTERFACE_IMPL(CAutomaticGainControl, AudioEffect, IAutomaticGainControl)

CAR_OBJECT_IMPL(CAutomaticGainControl)

/**
 * Class constructor.
 * <p> The constructor is not guarantied to succeed and throws the following exceptions:
 * <ul>
 *  <li>IllegalArgumentException is thrown if the device does not implement an AEC</li>
 *  <li>UnsupportedOperationException is thrown is the resources allocated to audio
 *  pre-procesing are currently exceeded.</li>
 *  <li>RuntimeException is thrown if a memory allocation error occurs.</li>
 * </ul>
 *
 * @param audioSession system wide unique audio session identifier. The AcousticEchoCanceler
 * will be applied to the AudioRecord with the same audio session.
 *
 * @throws java.lang.IllegalArgumentException
 * @throws java.lang.UnsupportedOperationException
 * @throws java.lang.RuntimeException
 */
ECode CAutomaticGainControl::constructor(
    /* [in] */ Int32 audioSession)
{
    AutoPtr<IUUIDHelper> helper;
    CUUIDHelper::AcquireSingleton((IUUIDHelper**)&helper);
    AutoPtr<IUUID> typeAGC;
    AutoPtr<IUUID> typeNULL;
    helper->FromString(IAudioEffect::EFFECT_TYPE_AGC, (IUUID**)&typeAGC);
    helper->FromString(IAudioEffect::EFFECT_TYPE_NULL, (IUUID**)&typeNULL);
    return AudioEffect::constructor(typeAGC, typeNULL, 0, audioSession);
}

/**
 * Checks if the device implements acoustic echo cancellation.
 * @return true if the device implements acoustic echo cancellation, false otherwise.
 */
ECode CAutomaticGainControl::IsAvailable(
    /* [out] */ Boolean* result)
{
    VALIDATE_NOT_NULL(result);

    AutoPtr<IUUIDHelper> helper;
    CUUIDHelper::AcquireSingleton((IUUIDHelper**)&helper);
    AutoPtr<IUUID> typeAGC;
    helper->FromString(IAudioEffect::EFFECT_TYPE_AGC, (IUUID**)&typeAGC);
    AutoPtr<IAudioEffectHelper> aeHelper;
    CAudioEffectHelper::AcquireSingleton((IAudioEffectHelper**)&aeHelper);
    return aeHelper->IsEffectTypeAvailable(typeAGC, result);
}

} // namespace Audiofx
} // namespace Media
} // namepsace Droid
} // namespace Elastos
