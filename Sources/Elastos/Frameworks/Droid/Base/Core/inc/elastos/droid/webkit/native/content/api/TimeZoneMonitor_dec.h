//This file is autogenerated for
//    TimeZoneMonitor.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_TIMEZONEMONITOR_CALLBACK_DEC_HH
#define ELASTOS_TIMEZONEMONITOR_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_TimeZoneMonitor_nativeTimeZoneChangedFromJava(IInterface* caller,Handle32 nativeTimeZoneMonitorAndroid);
    extern void Elastos_TimeZoneMonitor_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif


namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Content {
namespace Browser {

struct ElaTimeZoneMonitorCallback
{
    AutoPtr<IInterface> (*elastos_TimeZoneMonitor_getInstance)(IInterface* context, Int64 nativePtr);
    void (*elastos_TimeZoneMonitor_stop)(IInterface* obj);
};

void* TimeZoneMonitor::ElaTimeZoneMonitorCallback_Init()
{
    static ElaTimeZoneMonitorCallback sElaTimeZoneMonitorCallback;

    sElaTimeZoneMonitorCallback.elastos_TimeZoneMonitor_getInstance = &TimeZoneMonitor::GetInstance;
    sElaTimeZoneMonitorCallback.elastos_TimeZoneMonitor_stop = &TimeZoneMonitor::Stop;

    Elastos_TimeZoneMonitor_InitCallback((Handle32)&sElaTimeZoneMonitorCallback);
    return &sElaTimeZoneMonitorCallback;
}

static void* sPElaTimeZoneMonitorCallback = TimeZoneMonitor::ElaTimeZoneMonitorCallback_Init();

} // namespace Browser
} // namespace Content
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_TIMEZONEMONITOR_CALLBACK_DEC_HH