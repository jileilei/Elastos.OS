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

#ifndef __ELASTOS_DROID_CONTENT_IICONTENTPROVIDERCONSTANTS_H__
#define __ELASTOS_DROID_CONTENT_IICONTENTPROVIDERCONSTANTS_H__

#include <elastos.h>

namespace Elastos {
namespace Droid {
namespace Content {

class IIContentProviderConstants

{
public:
    /* IPC constants */
    static const String DESCRIPTOR;

    static const Int32 QUERY_TRANSACTION = 0x00000001;

    static const Int32 GET_TYPE_TRANSACTION = 0x00000002;

    static const Int32 INSERT_TRANSACTION = 0x00000003;

    static const Int32 DELETE_TRANSACTION = 0x00000004;

    static const Int32 UPDATE_TRANSACTION = 0x0000000a;

    static const Int32 BULK_INSERT_TRANSACTION = 0x0000000d;

    static const Int32 OPEN_FILE_TRANSACTION = 0x0000000e;

    static const Int32 OPEN_ASSET_FILE_TRANSACTION = 0x0000000f;

    static const Int32 APPLY_BATCH_TRANSACTION = 0x00000014;

    static const Int32 CALL_TRANSACTION = 0x00000015;

    static const Int32 GET_STREAM_TYPES_TRANSACTION = 0x00000016;

    static const Int32 OPEN_TYPED_ASSET_FILE_TRANSACTION = 0x00000017;
      
    static const Int32 CREATE_CANCELATION_SIGNAL_TRANSACTION = 0x00000018;

};

}
}
}

#endif //__ELASTOS_DROID_CONTENT_IICONTENTPROVIDERCONSTANTS_H__
