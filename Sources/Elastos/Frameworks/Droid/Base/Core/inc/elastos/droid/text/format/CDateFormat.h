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

#ifndef __ELASTOS_DROID_TEXT_FORMAT_CDATEFORMAT_H__
#define __ELASTOS_DROID_TEXT_FORMAT_CDATEFORMAT_H__

#include "_Elastos_Droid_Text_Format_CDateFormat.h"
#include "elastos/droid/text/format/DateFormat.h"
#include <elastos/core/Singleton.h>

using Elastos::Droid::Content::IContext;
using Elastos::Utility::ICalendar;
using Elastos::Utility::IDate;
using Elastos::Core::ICharSequence;

namespace Elastos {
namespace Droid {
namespace Text {
namespace Format {

CarClass(CDateFormat)
    , public Singleton
    , public IDateFormat
{
public:
    CAR_INTERFACE_DECL()

    CAR_SINGLETON_DECL()

    CARAPI Is24HourFormat(
        /* [in] */ IContext* context,
        /* [out] */ Boolean* result);

    CARAPI GetBestDateTimePattern(
        /* [in] */ ILocale* locale,
        /* [in] */ const String& skeleton,
        /* [out] */ String* pattern);

    CARAPI GetTimeFormat(
        /* [in] */ IContext* context,
        /* [out] */ Elastos::Text::IDateFormat** format);

    CARAPI GetTimeFormatString(
        /* [in] */ IContext* context,
        /* [out] */ String* format);

    CARAPI GetDateFormat(
        /* [in] */ IContext* context,
        /* [out] */ Elastos::Text::IDateFormat** format);

    CARAPI GetDateFormatForSetting(
        /* [in] */ IContext* context,
        /* [in] */ const String& value,
        /* [out] */ Elastos::Text::IDateFormat** format);

    CARAPI GetLongDateFormat(
        /* [in] */ IContext* context,
        /* [out] */ Elastos::Text::IDateFormat** format);

    CARAPI GetMediumDateFormat(
        /* [in] */ IContext* context,
        /* [out] */ Elastos::Text::IDateFormat** format);

    CARAPI GetDateFormatOrder(
        /* [in] */ IContext* context,
        /* [out, callee] */ ArrayOf<Char32>** order);

    CARAPI Format(
        /* [in] */ ICharSequence* inFormat,
        /* [in] */ Int64 inTimeInMillis,
        /* [out] */ ICharSequence** result);

    CARAPI Format(
        /* [in] */ ICharSequence* inFormat,
        /* [in] */ IDate* inDate,
        /* [out] */ ICharSequence** result);

    CARAPI HasSeconds(
        /* [in] */ ICharSequence* inFormat,
        /* [out] */ Boolean* result);

    CARAPI Format(
        /* [in] */ ICharSequence* inFormat,
        /* [in] */ ICalendar* inDate,
        /* [out] */ ICharSequence** result);
};

} // namespace Format
} // namespace Text
} // namepsace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_TEXT_FORMAT_CDATEFORMAT_H__
