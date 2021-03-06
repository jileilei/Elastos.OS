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

#ifndef  __ELASTOS_DROID_PHONE_ICCNETWORKDEPERSONALIZATIONPANEL_H__
#define  __ELASTOS_DROID_PHONE_ICCNETWORKDEPERSONALIZATIONPANEL_H__

#include "_Elastos.Droid.TeleService.h"
#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/teleservice/phone/IccPanel.h"
#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Internal.h"
#include "Elastos.Droid.Os.h"
#include "Elastos.Droid.Text.h"
#include "Elastos.Droid.View.h"
#include "Elastos.Droid.Widget.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Content::IContext;
using Elastos::Droid::Internal::Telephony::IPhone;
using Elastos::Droid::Os::IMessage;
using Elastos::Droid::Os::IBundle;
using Elastos::Droid::Os::IHandler;
using Elastos::Droid::TeleService::Phone::IccPanel;
using Elastos::Droid::Text::ITextWatcher;
using Elastos::Droid::Text::INoCopySpan;
using Elastos::Droid::Text::IEditable;
using Elastos::Droid::Text::ITextWatcher;
using Elastos::Droid::View::IView;
using Elastos::Droid::View::IViewOnClickListener;
using Elastos::Droid::View::IKeyEvent;
using Elastos::Droid::Widget::IButton;
using Elastos::Droid::Widget::ITextView;
using Elastos::Droid::Widget::IEditText;
using Elastos::Droid::Widget::ILinearLayout;
using Elastos::Core::Object;
using Elastos::Core::ICharSequence;

namespace Elastos {
namespace Droid {
namespace TeleService {
namespace Phone {

/**
 * "SIM network unlock" PIN entry screen.
 *
 * @see PhoneGlobals.EVENT_SIM_NETWORK_LOCKED
 *
 * TODO: This UI should be part of the lock screen, not the
 * phone app (see bug 1804111).
 */
class IccNetworkDepersonalizationPanel
    : public IccPanel
{
private:
    class MyTextWatcher
        : public Object
        , public ITextWatcher
        , public INoCopySpan
    {
    public:
        TO_STRING_IMPL("IccNetworkDepersonalizationPanel::MyTextWatcher")

        CAR_INTERFACE_DECL()

        MyTextWatcher(
            /* [in] */ IccNetworkDepersonalizationPanel* host)
            : mHost(host)
        {}

        CARAPI BeforeTextChanged(
            /* [in] */ ICharSequence* buffer,
            /* [in] */ Int32 start,
            /* [in] */ Int32 olen,
            /* [in] */ Int32 nlen)
        {
            return NOERROR;
        }

        CARAPI OnTextChanged(
            /* [in] */ ICharSequence* buffer,
            /* [in] */ Int32 start,
            /* [in] */ Int32 olen,
            /* [in] */ Int32 nlen)
        {
            return NOERROR;
        }

        CARAPI AfterTextChanged(
            /* [in] */ IEditable* buffer);

    private:
        IccNetworkDepersonalizationPanel* mHost;
    };

    class MyRunnable
        : public Runnable
    {
    public:
        TO_STRING_IMPL("IccNetworkDepersonalizationPanel::MyRunnable")

        MyRunnable(
            /* [in] */ IccNetworkDepersonalizationPanel* host)
            : mHost(host)
        {}

        CARAPI Run();

    private:
        IccNetworkDepersonalizationPanel* mHost;
    };

    class MyRunnable2
        : public Runnable
    {
    public:
        TO_STRING_IMPL("IccNetworkDepersonalizationPanel::MyRunnable2")

        MyRunnable2(
            /* [in] */ IccNetworkDepersonalizationPanel* host)
            : mHost(host)
        {}

        CARAPI Run();

    private:
        IccNetworkDepersonalizationPanel* mHost;
    };

    class MyHandler
        : public Handler
    {
    public:
        TO_STRING_IMPL("IccNetworkDepersonalizationPanel::MyHandler")

        MyHandler(
            /* [in] */ IccNetworkDepersonalizationPanel* host);

        CARAPI HandleMessage(
            /* [in] */ IMessage* msg);

    private:
        IccNetworkDepersonalizationPanel* mHost;
    };

    class MyViewOnClickListener
        : public Object
        , public IViewOnClickListener
    {
    public:
        TO_STRING_IMPL("IccNetworkDepersonalizationPanel::MyViewOnClickListener")

        CAR_INTERFACE_DECL()

        MyViewOnClickListener(
            /* [in] */ IccNetworkDepersonalizationPanel* host)
            : mHost(host)
        {}

        CARAPI OnClick(
            /* [in] */ IView* v);

    private:
        IccNetworkDepersonalizationPanel* mHost;
    };

    class MyViewOnClickListener2
        : public Object
        , public IViewOnClickListener
    {
    public:
        TO_STRING_IMPL("IccNetworkDepersonalizationPanel::MyViewOnClickListener2")

        CAR_INTERFACE_DECL()

        MyViewOnClickListener2(
            /* [in] */ IccNetworkDepersonalizationPanel* host)
            : mHost(host)
        {}

        CARAPI OnClick(
            /* [in] */ IView* v);

    private:
        IccNetworkDepersonalizationPanel* mHost;
    };


public:
    TO_STRING_IMPL("IccNetworkDepersonalizationPanel")

    //constructor
    IccNetworkDepersonalizationPanel(
        /* [in] */ IContext* context);

    //Mirrors IccPinUnlockPanel.onKeyDown().
    CARAPI OnKeyDown(
        /* [in] */ Int32 keyCode,
        /* [in] */ IKeyEvent* event,
        /* [out] */ Boolean* result);

protected:
    //@Override
    CARAPI OnCreate(
        /* [in] */ IBundle* icicle);

    //@Override
    CARAPI OnStart();

private:
    CARAPI_(void) IndicateBusy();

    CARAPI_(void) IndicateError();

    CARAPI_(void) IndicateSuccess();

    CARAPI_(void) HideAlert();

    CARAPI_(void) Log(
        /* [in] */ const String& msg);

private:
    //debug constants
    static const Boolean DBG;

    //events
    static const Int32 EVENT_ICC_NTWRK_DEPERSONALIZATION_RESULT;

    AutoPtr<IPhone> mPhone;

    //UI elements
    AutoPtr<IEditText> mPinEntry;
    AutoPtr<ILinearLayout> mEntryPanel;
    AutoPtr<ILinearLayout> mStatusPanel;
    AutoPtr<ITextView> mStatusText;

    AutoPtr<IButton> mUnlockButton;
    AutoPtr<IButton> mDismissButton;

    //private textwatcher to control text entry.
    AutoPtr<ITextWatcher> mPinEntryWatcher;

    //handler for unlock function results
    AutoPtr<IHandler> mHandler;

    AutoPtr<IViewOnClickListener> mUnlockListener;

    AutoPtr<IViewOnClickListener> mDismissListener;
};

} // namespace Phone
} // namespace TeleService
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_PHONE_ICCNETWORKDEPERSONALIZATIONPANEL_H__