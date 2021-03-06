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

#include "elastos/droid/server/telecom/RespondViaSmsSettings.h"
#include "R.h"
#include "elastos/droid/server/telecom/Log.h"
#include "elastos/droid/server/telecom/QuickResponseUtils.h"
#include <elastos/droid/R.h>
#include <elastos/droid/provider/Settings.h>

using Elastos::Droid::App::IActionBar;
using Elastos::Droid::Content::IContext;
using Elastos::Droid::Content::ISharedPreferences;
using Elastos::Droid::Content::ISharedPreferencesEditor;
using Elastos::Droid::Preference::EIID_IPreferenceOnPreferenceChangeListener;
using Elastos::Droid::Preference::IEditTextPreference;
using Elastos::Droid::Preference::IPreferenceManager;
using Elastos::Droid::Provider::Settings;

namespace Elastos {
namespace Droid {
namespace Server {
namespace Telecom {

//=============================================================================
// RespondViaSmsSettings::Settings::InnerListener
//=============================================================================

CAR_INTERFACE_IMPL(RespondViaSmsSettings::Settings::InnerListener, Object, IPreferenceOnPreferenceChangeListener)

RespondViaSmsSettings::Settings::InnerListener::InnerListener(
    /* [in] */ Settings* host)
    : mHost(host)
{}

ECode RespondViaSmsSettings::Settings::InnerListener::OnPreferenceChange(
    /* [in] */ IPreference* preference,
    /* [in] */ IInterface* newValue,
    /* [out] */ Boolean* result)
{
    return mHost->OnPreferenceChange(preference, newValue, result);
}

//=============================================================================
// RespondViaSmsSettings::Settings
//=============================================================================
CAR_INTERFACE_IMPL(RespondViaSmsSettings::Settings, PreferenceActivity, IRespondViaSmsSettingsSettings)

ECode RespondViaSmsSettings::Settings::OnCreate(
    /* [in] */ IBundle* icicle)
{
    PreferenceActivity::OnCreate(icicle);
    Log::D("RespondViaSmsSettings", "Settings: onCreate()...");
    // This function guarantees that QuickResponses will be in our
    // SharedPreferences with the proper values considering there may be
    // old QuickResponses in Telephony pre L.
    QuickResponseUtils::MaybeMigrateLegacyQuickResponses(this);
    AutoPtr<IPreferenceManager> preferenceManager;
    GetPreferenceManager((IPreferenceManager**)&preferenceManager);
    preferenceManager->SetSharedPreferencesName(
            QuickResponseUtils::SHARED_PREFERENCES_NAME);
    // This preference screen is ultra-simple; it's just 4 plain
    // <EditTextPreference>s, one for each of the 4 "canned responses".
    //
    // The only nontrivial thing we do here is copy the text value of
    // each of those EditTextPreferences and use it as the preference's
    // "title" as well, so that the user will immediately see all 4
    // strings when they arrive here.
    //
    // Also, listen for change events (since we'll need to update the
    // title any time the user edits one of the strings.)
    AddPreferencesFromResource(R::xml::respond_via_sms_settings);
    AutoPtr<IEditTextPreference> pref;
    AutoPtr<IPreference> preference;
    FindPreference(QuickResponseUtils::KEY_CANNED_RESPONSE_PREF_1, (IPreference**)&preference);
    pref = IEditTextPreference::Probe(preference);
    String text;
    pref->GetText(&text);
    assert(0 && "TODO IEditTextPreference");
    AutoPtr<InnerListener> listener = new InnerListener(this);
    // pref->SetTitle(text);
    // pref->SetOnPreferenceChangeListener(listener);
    preference = NULL;
    FindPreference(QuickResponseUtils::KEY_CANNED_RESPONSE_PREF_2, (IPreference**)&preference);
    pref = IEditTextPreference::Probe(preference);
    pref->GetText(&text);
    assert(0 && "TODO IEditTextPreference");
    // pref->SetTitle(text);
    // pref->SetOnPreferenceChangeListener(listener);
    preference = NULL;
    FindPreference(QuickResponseUtils::KEY_CANNED_RESPONSE_PREF_3, (IPreference**)&preference);
    pref = IEditTextPreference::Probe(preference);
    pref->GetText(&text);
    assert(0 && "TODO IEditTextPreference");
    // pref->SetTitle(text);
    // pref->SetOnPreferenceChangeListener(listener);
    preference = NULL;
    FindPreference(QuickResponseUtils::KEY_CANNED_RESPONSE_PREF_4, (IPreference**)&preference);
    pref = IEditTextPreference::Probe(preference);
    pref->GetText(&text);
    assert(0 && "TODO IEditTextPreference");
    // pref->SetTitle(text);
    // pref->SetOnPreferenceChangeListener(listener);
    AutoPtr<IActionBar> actionBar;
    GetActionBar((IActionBar**)&actionBar);
    if (actionBar != NULL) {
        // android.R.id.home will be triggered in onOptionsItemSelected()
        actionBar->SetDisplayHomeAsUpEnabled(TRUE);
    }
    return NOERROR;
}

ECode RespondViaSmsSettings::Settings::OnPreferenceChange(
    /* [in] */ IPreference* preference,
    /* [in] */ IInterface* newValue,
    /* [out] */ Boolean* result)
{
    VALIDATE_NOT_NULL(result)

    String key;
    preference->GetKey(&key);
    Log::D("RespondViaSmsSettings", "onPreferenceChange: key = %s", key.string());
    Log::D("RespondViaSmsSettings", "  preference = '%s'", TO_CSTR(preference));
    Log::D("RespondViaSmsSettings", "  newValue = '%s'", TO_CSTR(newValue));
    AutoPtr<IEditTextPreference> pref = IEditTextPreference::Probe(preference);
    // Copy the new text over to the title, just like in onCreate().
    // (Watch out: onPreferenceChange() is called *before* the
    // Preference itself gets updated, so we need to use newValue here
    // rather than pref->GetText().)
    assert(0 && "TODO IEditTextPreference");
    // pref->SetTitle(TO_STR(newValue));
    *result = TRUE;  // means it's OK to update the state of the Preference with the new value
    return NOERROR;
}

ECode RespondViaSmsSettings::Settings::OnOptionsItemSelected(
    /* [in] */ IMenuItem* item,
    /* [out] */ Boolean* result)
{
    VALIDATE_NOT_NULL(result)

    Int32 itemId;
    item->GetItemId(&itemId);
    switch (itemId) {
        case Elastos::Droid::R::id::home:
            GoUpToTopLevelSetting(this);
            *result = TRUE;
            return NOERROR;
        case R::id::respond_via_message_reset: {
            // Reset the preferences settings
            AutoPtr<ISharedPreferences> prefs;
            GetSharedPreferences(
                    QuickResponseUtils::SHARED_PREFERENCES_NAME, IContext::MODE_PRIVATE, (ISharedPreferences**)&prefs);
            AutoPtr<ISharedPreferencesEditor> editor;
            prefs->Edit((ISharedPreferencesEditor**)&editor);
            editor->Remove(KEY_INSTANT_TEXT_DEFAULT_COMPONENT);
            editor->Apply();
            *result = TRUE;
            return NOERROR;
        }
        default:
            break;
    }
    return PreferenceActivity::OnOptionsItemSelected(item, result);
}

ECode RespondViaSmsSettings::Settings::OnCreateOptionsMenu(
    /* [in] */ IMenu* menu,
    /* [out] */ Boolean* result)
{
    VALIDATE_NOT_NULL(result)

    AutoPtr<IMenuInflater> menuInflater;
    GetMenuInflater((IMenuInflater**)&menuInflater);
    menuInflater->Inflate(R::menu::respond_via_message_settings_menu, menu);
    return PreferenceActivity::OnCreateOptionsMenu(menu, result);
}

//=============================================================================
// RespondViaSmsSettings
//=============================================================================
const String RespondViaSmsSettings::KEY_PREFERRED_PACKAGE("preferred_package_pref");
const String RespondViaSmsSettings::KEY_INSTANT_TEXT_DEFAULT_COMPONENT("instant_text_def_component");

ECode RespondViaSmsSettings::GoUpToTopLevelSetting(
    /* [in] */ IActivity* activity)
{
    return activity->Finish();
}

} // namespace Telecom
} // namespace Server
} // namespace Droid
} // namespace Elastos
