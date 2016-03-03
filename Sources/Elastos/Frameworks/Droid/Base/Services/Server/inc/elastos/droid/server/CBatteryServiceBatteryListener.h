#ifndef __ELASTOS_DROID_SERVER_CBATTERY_SERVICE_BATTERY_LISTENER_H__
#define __ELASTOS_DROID_SERVER_CBATTERY_SERVICE_BATTERY_LISTENER_H__

#include "_Elastos_Droid_Server_CBatteryServiceBatteryListener.h"
#include "elastos/droid/server/CBatteryService.h"

namespace Elastos {
namespace Droid {
namespace Server {

CarClass(CBatteryServiceBatteryListener)
    , public CBatteryService::BatteryListener
{
public:
    CAR_OBJECT_DECL()
};

} // namespace Server
} // namepsace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_SERVER_CBATTERY_SERVICE_BATTERY_LISTENER_H__