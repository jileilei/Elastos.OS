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

#include "Elastos.Droid.Telecom.h"
#include "elastos/droid/incallui/CGlowPadWrapper.h"
#include "elastos/droid/incallui/InCallPresenter.h"
#include "R.h"
#include <elastos/utility/logging/Logger.h>

using Elastos::Droid::InCallUI::Widget::MultiwaveView::EIID_IGlowPadViewOnTriggerListener;
using Elastos::Droid::Dialer::R;
using Elastos::Droid::Telecom::IVideoProfileVideoState;
using Elastos::Utility::Logging::Logger;

namespace Elastos {
namespace Droid {
namespace InCallUI {

ECode CGlowPadWrapper::PingHandler::HandleMessage(
    /* [in] */ IMessage* msg)
{
    Int32 what;
    msg->GetWhat(&what);
    switch (what) {
        case PING_MESSAGE_WHAT:
            mHost->TriggerPing();
            break;
    }
    return NOERROR;
}

ECode CGlowPadWrapper::PingHandler::ToString(
    /* [out] */ String* str)
{
    VALIDATE_NOT_NULL(str);
    *str = "CGlowPadWrapper::PingHandler";
    return NOERROR;
}

CAR_INTERFACE_IMPL(CGlowPadWrapper::InnerListener, Object, IGlowPadViewOnTriggerListener)

CGlowPadWrapper::InnerListener::InnerListener(
    /* [in] */ CGlowPadWrapper* host)
    : mHost(host)
{}

// @Override
ECode CGlowPadWrapper::InnerListener::OnGrabbed(
    /* [in] */ IView* v,
    /* [in] */ Int32 handle)
{
    return mHost->OnGrabbed(v, handle);
}

// @Override
ECode CGlowPadWrapper::InnerListener::OnReleased(
    /* [in] */ IView* v,
    /* [in] */ Int32 handle)
{
    return mHost->OnReleased(v, handle);
}

// @Override
ECode CGlowPadWrapper::InnerListener::OnTrigger(
    /* [in] */ IView* v,
    /* [in] */ Int32 target)
{
    return mHost->OnTrigger(v, target);
}

// @Override
ECode CGlowPadWrapper::InnerListener::OnGrabbedStateChange(
    /* [in] */ IView* v,
    /* [in] */ Int32 handle)
{
    return mHost->OnGrabbedStateChange(v, handle);
}

ECode CGlowPadWrapper::InnerListener::OnFinishFinalAnimation()
{
    return mHost->OnFinishFinalAnimation();
}

const Int32 CGlowPadWrapper::PING_MESSAGE_WHAT;
const Boolean CGlowPadWrapper::ENABLE_PING_AUTO_REPEAT;
const Int64 CGlowPadWrapper::PING_REPEAT_DELAY_MS;

CAR_INTERFACE_IMPL(CGlowPadWrapper, GlowPadView, IGlowPadWrapper)

CAR_OBJECT_IMPL(CGlowPadWrapper)

CGlowPadWrapper::CGlowPadWrapper()
    : mPingEnabled(TRUE)
    , mTargetTriggered(FALSE)
{
    mPingHandler = new PingHandler(this);
}

ECode CGlowPadWrapper::constructor(
    /* [in] */ IContext* context)
{
    FAIL_RETURN(GlowPadView::constructor(context));
    Logger::D("CGlowPadWrapper", "class created %s ", TO_CSTR(this));
    return NOERROR;
}

ECode CGlowPadWrapper::constructor(
    /* [in] */ IContext* context,
    /* [in] */ IAttributeSet* attrs)
{
    FAIL_RETURN(GlowPadView::constructor(context, attrs));
    Logger::D("CGlowPadWrapper", "class created %s ", TO_CSTR(this));
    return NOERROR;
}

ECode CGlowPadWrapper::OnFinishInflate()
{
    Logger::D("CGlowPadWrapper", "onFinishInflate()");
    FAIL_RETURN(GlowPadView::OnFinishInflate());
    AutoPtr<InnerListener> listener = new InnerListener(this);
    SetOnTriggerListener(listener);
    return NOERROR;
}

void CGlowPadWrapper::StartPing()
{
    Logger::D("CGlowPadWrapper", "startPing");
    mPingEnabled = TRUE;
    TriggerPing();
}

void CGlowPadWrapper::StopPing()
{
    Logger::D("CGlowPadWrapper", "stopPing");
    mPingEnabled = FALSE;
    mPingHandler->RemoveMessages(PING_MESSAGE_WHAT);
}

void CGlowPadWrapper::TriggerPing()
{
    Logger::D("CGlowPadWrapper", "triggerPing(): %d %s", mPingEnabled, TO_CSTR(this));
    Boolean result;
    if (mPingEnabled && (mPingHandler->HasMessages(PING_MESSAGE_WHAT, &result), !result)) {
        Ping();

        if (ENABLE_PING_AUTO_REPEAT) {
            mPingHandler->SendEmptyMessageDelayed(PING_MESSAGE_WHAT, PING_REPEAT_DELAY_MS, &result);
        }
    }
}

ECode CGlowPadWrapper::OnGrabbed(
    /* [in] */ IView* v,
    /* [in] */ Int32 handle)
{
    Logger::D("CGlowPadWrapper", "onGrabbed()");
    StopPing();
    return NOERROR;
}

ECode CGlowPadWrapper::OnReleased(
    /* [in] */ IView* v,
    /* [in] */ Int32 handle)
{
    Logger::D("CGlowPadWrapper", "onReleased()");
    if (mTargetTriggered) {
        mTargetTriggered = FALSE;
    }
    else {
        StartPing();
    }
    return NOERROR;
}

ECode CGlowPadWrapper::OnTrigger(
    /* [in] */ IView* v,
    /* [in] */ Int32 target)
{
    Logger::D("CGlowPadWrapper", "onTrigger()");
    Int32 resId = GetResourceIdForTarget(target);
    switch (resId) {
        case R::drawable::ic_lockscreen_answer: {
            AutoPtr<IContext> context;
            GetContext((IContext**)&context);
            mAnswerListener->OnAnswer(IVideoProfileVideoState::AUDIO_ONLY, context);
            mTargetTriggered = TRUE;
            break;
        }
        case R::drawable::ic_lockscreen_decline:
            mAnswerListener->OnDecline();
            mTargetTriggered = TRUE;
            break;
        case R::drawable::ic_lockscreen_text:
            mAnswerListener->OnText();
            mTargetTriggered = TRUE;
            break;
        case R::drawable::ic_videocam: {
            AutoPtr<IContext> context;
            GetContext((IContext**)&context);
            mAnswerListener->OnAnswer(IVideoProfileVideoState::BIDIRECTIONAL, context);
            mTargetTriggered = TRUE;
            break;
        }
        case R::drawable::ic_toolbar_video_off: {
            AutoPtr<IContext> context;
            GetContext((IContext**)&context);
            InCallPresenter::GetInstance()->DeclineUpgradeRequest(context);
            mTargetTriggered = TRUE;
            break;
        }
        default:
            // Code should never reach here.
            Logger::E("CGlowPadWrapper", "Trigger detected on unhandled resource. Skipping.");
    }
    return NOERROR;
}

ECode CGlowPadWrapper::OnGrabbedStateChange(
    /* [in] */ IView* v,
    /* [in] */ Int32 handle)
{
    return NOERROR;
}

ECode CGlowPadWrapper::OnFinishFinalAnimation()
{
    return NOERROR;
}

void CGlowPadWrapper::SetAnswerListener(
    /* [in] */ IAnswerListener* listener)
{
    mAnswerListener = listener;
}

} // namespace InCallUI
} // namespace Droid
} // namespace Elastos
