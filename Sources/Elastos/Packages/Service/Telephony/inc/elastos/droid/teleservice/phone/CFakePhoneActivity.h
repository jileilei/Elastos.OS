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

#ifndef  __ELASTOS_DROID_PHONE_CFACKPHONEACTIVITY_H__
#define  __ELASTOS_DROID_PHONE_CFACKPHONEACTIVITY_H__

#include "_Elastos_Droid_TeleService_Phone_CFakePhoneActivity.h"
#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/app/Activity.h"
#include "Elastos.Droid.Os.h"
#include "Elastos.Droid.View.h"
#include "Elastos.Droid.Widget.h"
#include <elastos/core/Object.h>

using Elastos::Droid::App::Activity;
using Elastos::Droid::Os::IBundle;
using Elastos::Droid::View::IView;
using Elastos::Droid::View::IViewOnClickListener;
using Elastos::Droid::Widget::IButton;
using Elastos::Droid::Widget::IEditText;
using Elastos::Core::Object;

namespace Elastos {
namespace Droid {
namespace TeleService {
namespace Phone {

/**
 * A simple activity that presents you with a UI for faking incoming phone operations.
 */
CarClass(CFakePhoneActivity)
    , public Activity
{
private:
    class ButtonListener
        : public Object
        , public IViewOnClickListener
    {
    public:
        TO_STRING_IMPL("CFakePhoneActivity::ButtonListener")

        CAR_INTERFACE_DECL()

        ButtonListener(
            /* [in] */ CFakePhoneActivity* host)
            : mHost(host)
        {}

        CARAPI OnClick(
            /* [in] */ IView* v);

    private:
        CFakePhoneActivity* mHost;
    };

    class MyViewOnClickListener
        : public Object
        , public IViewOnClickListener
    {
    public:
        TO_STRING_IMPL("CFakePhoneActivity::MyViewOnClickListener")

        CAR_INTERFACE_DECL()

        MyViewOnClickListener(
            /* [in] */ CFakePhoneActivity* host)
            : mHost(host)
        {}

        CARAPI OnClick(
            /* [in] */ IView* v);

    private:
        CFakePhoneActivity* mHost;
    };

public:
    CAR_OBJECT_DECL();

    CFakePhoneActivity() {}

    CARAPI constructor();

    //@Override
    CARAPI OnCreate(
        /* [in] */ IBundle* icicle);

private:
    static const String TAG;

    AutoPtr<IButton> mPlaceCall;
    AutoPtr<IEditText> mPhoneNumber;
    //AutoPtr<ISimulatedRadioControl> mRadioControl;
};

} // namespace Phone
} // namespace TeleService
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_PHONE_CFACKPHONEACTIVITY_H__