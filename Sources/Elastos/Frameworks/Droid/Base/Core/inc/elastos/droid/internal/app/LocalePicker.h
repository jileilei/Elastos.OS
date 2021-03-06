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

#ifndef __ELASTOS_DROID_INTERNAL_APP_LOCALEPICKER_H__
#define __ELASTOS_DROID_INTERNAL_APP_LOCALEPICKER_H__

#include "Elastos.Droid.Internal.h"
#include "elastos/droid/app/ListFragment.h"
#include "elastos/droid/widget/ArrayAdapter.h"

using Elastos::Droid::App::ListFragment;
using Elastos::Droid::Internal::App::ILocaleSelectionListener;
using Elastos::Droid::Widget::ArrayAdapter;
using Elastos::Droid::Widget::IArrayAdapter;
using Elastos::Core::IComparable;
using Elastos::Text::ICollator;
using Elastos::Utility::ILocale;


namespace Elastos {
namespace Droid {
namespace Internal {
namespace App {

class ECO_PUBLIC LocalePicker
    : public ListFragment
    , public ILocalePicker
{
public:
    class LocaleInfo
        : public Object
        , public ILocaleInfo
        , public IComparable
    {
    public:
        CAR_INTERFACE_DECL()

        LocaleInfo(
            /* [in] */ const String& label,
            /* [in] */ ILocale* locale);

        CARAPI GetLabel(
            /* [out] */ String* label);

        CARAPI GetLocale(
            /* [out] */ ILocale** locale);

        CARAPI ToString(
            /* [out] */ String* string);

        CARAPI CompareTo(
            /* [in] */ IInterface* another,
            /* [out] */ Int32* result);

    public:
        static const AutoPtr<ICollator> sCollator;

        String mLabel;
        AutoPtr<ILocale> mLocale;
    };

private:
    class ECO_LOCAL LocalArrayAdapter
        : public ArrayAdapter
    {
    public:
        CARAPI constructor(
            /* [in] */ IContext* context,
            /* [in] */ Int32 resource,
            /* [in] */ Int32 textViewResourceId,
            /* [in] */ IList* objects,
            /* [in] */ ILayoutInflater* inflater);

        CARAPI GetView(
            /* [in] */ Int32 position,
            /* [in] */ IView* convertView,
            /* [in] */ IViewGroup* parent,
            /* [in] */ IView** view);

    private:
        AutoPtr<ILayoutInflater> mInflater;
        Int32 mLayoutId;
        Int32 mFieldId;
    };

public:
    CAR_INTERFACE_DECL()

    static CARAPI GetAllAssetLocales(
        /* [in] */ IContext* context,
        /* [in] */ Boolean isInDeveloperMode,
        /* [out] */ IList** list);

    static CARAPI ConstructAdapter(
        /* [in] */ IContext* context,
        /* [out] */ IArrayAdapter** adapter);

    static CARAPI ConstructAdapter(
        /* [in] */ IContext* context,
        /* [in] */ Int32 layoutId,
        /* [in] */ Int32 fieldId,
        /* [out] */ IArrayAdapter** adapter);

    CARAPI OnActivityCreated(
        /* [in] */ IBundle* savedInstanceState);

    CARAPI SetLocaleSelectionListener(
        /* [in] */ ILocaleSelectionListener* listener);

    CARAPI OnResume();

    CARAPI OnListItemClick(
        /* [in] */ IListView* l,
        /* [in] */ IView* v,
        /* [in] */ Int32 position,
        /* [in] */ Int64 id);

    static CARAPI UpdateLocale(
        /* [in] */ ILocale* locale);

private:
    ECO_LOCAL static CARAPI_(String) ToTitleCase(
        /* [in] */ const String& s);

    ECO_LOCAL static CARAPI_(String) GetDisplayName(
        /* [in] */ ILocale* l,
        /* [in] */ ArrayOf<String>* specialLocaleCodes,
        /* [in] */ ArrayOf<String>* specialLocaleNames);

private:
    ECO_LOCAL static const String TAG;
    ECO_LOCAL static const Boolean DEBUG = FALSE;
    AutoPtr<ILocaleSelectionListener> mListener;
};

} //namespace App
} //namespace Internal
} //namespace Droid
} //namespace Elastos

#endif // __ELASTOS_DROID_INTERNAL_APP_LOCALEPICKER_H__
