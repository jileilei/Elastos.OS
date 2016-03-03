
#ifndef __ORG_APACHE_HTTP_PROTOCOL_RESPONSESERVER_H_
#define __ORG_APACHE_HTTP_PROTOCOL_RESPONSESERVER_H_

#include "Elastos.CoreLibrary.Apache.h"
#include "elastos/core/Object.h"

using Org::Apache::Http::IHttpResponseInterceptor;
using Org::Apache::Http::IHttpResponse;

namespace Org {
namespace Apache {
namespace Http {
namespace Protocol {

/**
 * A response interceptor that adds a Server header.
 * For use on the server side.
 *
 * @author <a href="mailto:oleg at ural.ru">Oleg Kalnichevski</a>
 *
 * @version $Revision: 576073 $
 *
 * @since 4.0
 */
class ResponseServer
    : public Object
    , public IHttpResponseInterceptor
{
public:
    CAR_INTERFACE_DECL()

    virtual ~ResponseServer() {}

    CARAPI Process(
        /* [in] */ IHttpResponse* response,
        /* [in] */ IHttpContext* context);
};

} // namespace Protocol
} // namespace Http
} // namespace Apache
} // namespace Org

#endif // __ORG_APACHE_HTTP_PROTOCOL_RESPONSESERVER_H_