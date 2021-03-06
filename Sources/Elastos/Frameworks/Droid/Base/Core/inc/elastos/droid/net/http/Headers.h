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

#ifndef __ELASTOS_DROID_NET_HTTP_HEADERS_H__
#define __ELASTOS_DROID_NET_HTTP_HEADERS_H__

#include <Elastos.CoreLibrary.Utility.h>
#include "Elastos.Droid.Net.h"
#include "elastos/droid/ext/frameworkext.h"
#include <elastos/core/Object.h>

using Elastos::Utility::IArrayList;

using Org::Apache::Http::Utility::ICharArrayBuffer;

namespace Elastos {
namespace Droid {
namespace Net {
namespace Http {

/**
 * Manages received headers
 *
 * {@hide}
 */
class Headers
    : public Object
    , public IHeaders
{
public:
    CAR_INTERFACE_DECL()

    Headers();

    CARAPI constructor();

    CARAPI ParseHeader(
        /* [in] */ ICharArrayBuffer* buffer);

    CARAPI GetTransferEncoding(
        /* [out] */ Int64* result);

    CARAPI GetContentLength(
        /* [out] */ Int64* result);

    CARAPI GetConnectionType(
        /* [out] */ Int32* result);

    CARAPI GetContentType(
        /* [out] */ String* result);

    CARAPI GetContentEncoding(
        /* [out] */ String* result);

    CARAPI GetLocation(
        /* [out] */ String* result);

    CARAPI GetWwwAuthenticate(
        /* [out] */ String* result);

    CARAPI GetProxyAuthenticate(
        /* [out] */ String* result);

    CARAPI GetContentDisposition(
        /* [out] */ String* result);

    CARAPI GetAcceptRanges(
        /* [out] */ String* result);

    CARAPI GetExpires(
        /* [out] */ String* result);

    CARAPI GetCacheControl(
        /* [out] */ String* result);

    CARAPI GetLastModified(
        /* [out] */ String* result);

    CARAPI GetEtag(
        /* [out] */ String* result);

    CARAPI GetSetCookie(
        /* [out] */ IArrayList** result);

    CARAPI GetPragma(
        /* [out] */ String* result);

    CARAPI GetRefresh(
        /* [out] */ String* result);

    CARAPI GetXPermittedCrossDomainPolicies(
        /* [out] */ String* result);

    CARAPI SetContentLength(
        /* [in] */ Int64 value);

    CARAPI SetContentType(
        /* [in] */ const String& value);

    CARAPI SetContentEncoding(
        /* [in] */ const String& value);

    CARAPI SetLocation(
        /* [in] */ const String& value);

    CARAPI SetWwwAuthenticate(
        /* [in] */ const String& value);

    CARAPI SetProxyAuthenticate(
        /* [in] */ const String& value);

    CARAPI SetContentDisposition(
        /* [in] */ const String& value);

    CARAPI SetAcceptRanges(
        /* [in] */ const String& value);

    CARAPI SetExpires(
        /* [in] */ const String& value);

    CARAPI SetCacheControl(
        /* [in] */ const String& value);

    CARAPI SetLastModified(
        /* [in] */ const String& value);

    CARAPI SetEtag(
        /* [in] */ const String& value);

    CARAPI SetXPermittedCrossDomainPolicies(
        /* [in] */ const String& value);

    /**
     * Reports all non-null headers to the callback
     */
    CARAPI GetHeaders(
        /* [in] */ IHeaderCallback* hcb);

private:
    CARAPI SetConnectionType(
        /* [in] */ ICharArrayBuffer* buffer,
        /* [in] */ Int32 pos);

    static CARAPI_(AutoPtr<ArrayOf<String> >) InitHeaderNames();

private:
    static const String LOGTAG;

    // following hash are generated by String.hashCode()
    static const Int32 HASH_TRANSFER_ENCODING;

    static const Int32 HASH_CONTENT_LEN;

    static const Int32 HASH_CONTENT_TYPE;

    static const Int32 HASH_CONTENT_ENCODING;

    static const Int32 HASH_CONN_DIRECTIVE;

    static const Int32 HASH_LOCATION;

    static const Int32 HASH_PROXY_CONNECTION;

    static const Int32 HASH_WWW_AUTHENTICATE;

    static const Int32 HASH_PROXY_AUTHENTICATE;

    static const Int32 HASH_CONTENT_DISPOSITION;

    static const Int32 HASH_ACCEPT_RANGES;

    static const Int32 HASH_EXPIRES;

    static const Int32 HASH_CACHE_CONTROL;

    static const Int32 HASH_LAST_MODIFIED;

    static const Int32 HASH_ETAG;

    static const Int32 HASH_SET_COOKIE;

    static const Int32 HASH_PRAGMA;

    static const Int32 HASH_REFRESH;

    static const Int32 HASH_X_PERMITTED_CROSS_DOMAIN_POLICIES;

    // string array
    static const Int32 IDX_TRANSFER_ENCODING;

    static const Int32 IDX_CONTENT_LEN;

    static const Int32 IDX_CONTENT_TYPE;

    static const Int32 IDX_CONTENT_ENCODING;

    static const Int32 IDX_CONN_DIRECTIVE;

    static const Int32 IDX_LOCATION;

    static const Int32 IDX_PROXY_CONNECTION;

    static const Int32 IDX_WWW_AUTHENTICATE;

    static const Int32 IDX_PROXY_AUTHENTICATE;

    static const Int32 IDX_CONTENT_DISPOSITION;

    static const Int32 IDX_ACCEPT_RANGES;

    static const Int32 IDX_EXPIRES;

    static const Int32 IDX_CACHE_CONTROL;

    static const Int32 IDX_LAST_MODIFIED;

    static const Int32 IDX_ETAG;

    static const Int32 IDX_SET_COOKIE;

    static const Int32 IDX_PRAGMA;

    static const Int32 IDX_REFRESH;

    static const Int32 IDX_X_PERMITTED_CROSS_DOMAIN_POLICIES;

    static const Int32 HEADER_COUNT;

    /* parsed values */
    Int64 mTransferEncoding;
    Int64 mContentLength; // Content length of the incoming data
    Int32 mConnectionType;
    AutoPtr<IArrayList> mCookies;

    AutoPtr<ArrayOf<String> > mHeaders;

    static const AutoPtr<ArrayOf<String> > sHeaderNames;

    // Catch-all for headers not explicitly handled
    AutoPtr<IArrayList> mExtraHeaderNames;
    AutoPtr<IArrayList> mExtraHeaderValues;
};

} // namespace Http
} // namespace Net
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_NET_HTTP_HEADERS_H__
