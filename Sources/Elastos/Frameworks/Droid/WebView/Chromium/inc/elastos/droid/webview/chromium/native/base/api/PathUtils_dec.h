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

//This file is autogenerated for
//    PathUtils.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_PATHUTILS_CALLBACK_DEC_HH
#define ELASTOS_PATHUTILS_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_PathUtils_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Base {

struct ElaPathUtilsCallback
{
    String (*elastos_PathUtils_getDataDirectory)(IInterface* appContext);
    String (*elastos_PathUtils_getDatabaseDirectory)(IInterface* appContext);
    String (*elastos_PathUtils_getCacheDirectory)(IInterface* appContext);
    String (*elastos_PathUtils_getDownloadsDirectory)(IInterface* appContext);
    String (*elastos_PathUtils_getNativeLibraryDirectory)(IInterface* appContext);
    String (*elastos_PathUtils_getExternalStorageDirectory)();
};

void* PathUtils::ElaPathUtilsCallback_Init()
{
    static ElaPathUtilsCallback sElaPathUtilsCallback;

    sElaPathUtilsCallback.elastos_PathUtils_getDataDirectory = &PathUtils::GetDataDirectory;
    sElaPathUtilsCallback.elastos_PathUtils_getDatabaseDirectory = &PathUtils::GetDatabaseDirectory;
    sElaPathUtilsCallback.elastos_PathUtils_getCacheDirectory = &PathUtils::GetCacheDirectory;
    sElaPathUtilsCallback.elastos_PathUtils_getDownloadsDirectory = &PathUtils::GetDownloadsDirectory;
    sElaPathUtilsCallback.elastos_PathUtils_getNativeLibraryDirectory = &PathUtils::GetNativeLibraryDirectory;
    sElaPathUtilsCallback.elastos_PathUtils_getExternalStorageDirectory = &PathUtils::GetExternalStorageDirectory;

    Elastos_PathUtils_InitCallback((Handle32)&sElaPathUtilsCallback);
    return &sElaPathUtilsCallback;
}

static void* sPElaPathUtilsCallback = PathUtils::ElaPathUtilsCallback_Init();

} // namespace Base
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_PATHUTILS_CALLBACK_DEC_HH
