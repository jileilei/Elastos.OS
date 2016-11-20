
#ifndef __ORG_ALLJOYN_BUS_NATIVEPENDINGASYNCJOIN_H__
#define __ORG_ALLJOYN_BUS_NATIVEPENDINGASYNCJOIN_H__

#include "_Org.Alljoyn.Bus.h"
#include "Elastos.Droid.Content.h"

using Elastos::Droid::Content::IContext;

namespace Org {
namespace Alljoyn {
namespace Bus {

class NativePendingAsyncJoin
{
public:
    NativePendingAsyncJoin(
        /* [in] */ ISessionListener* sessionListener,
        /* [in] */ IOnJoinSessionListener* onJoinSessionListener,
        /* [in] */ IContext* context);

private:
    NativePendingAsyncJoin(const NativePendingAsyncJoin& other);
    NativePendingAsyncJoin& operator =(const NativePendingAsyncJoin& other);

public:
    AutoPtr<ISessionListener> mSessionListener;
    AutoPtr<IOnJoinSessionListener> mOnJoinSessionListener;
    AutoPtr<IContext> mContext;
};

} // namespace Bus
} // namespace Alljoyn
} // namespace Org

#endif // __ORG_ALLJOYN_BUS_NATIVEPENDINGASYNCJOIN_H__
