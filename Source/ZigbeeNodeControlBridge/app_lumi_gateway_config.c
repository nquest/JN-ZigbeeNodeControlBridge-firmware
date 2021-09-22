#include "jendefs.h"
#include "zps_gen.h"
#include "dbg.h"
#include "PDM.h"
#include "pdum_apl.h"
#include "pdum_gen.h"
#include "AppApi.h"
#include "AppHardwareApi.h"
#include "uart.h"
#include "rnd_pub.h"
#include "SerialLink.h"
#ifdef NETWORK_RECOVERY
#include "app_network_recovery.h"
#endif
#include "zps_apl.h"
#include "zps_apl_zdo.h"
#include "zps_apl_aib.h"
#include "zps_apl_af.h"
#include "app_common.h"
#include "app_Znc_cmds.h"
#include "Log.h"
#include "zcl.h"
#include "app_events.h"
#include "zcl_options.h"
#include "PDM_IDs.h"
#include "ApplianceStatistics.h"
#include "bdb_DeviceCommissioning.h"
#include "app_lumi_gateway_config.h"

PUBLIC void APP_vLumiGatewayConfig(void)
{
    uint16 u16GroupId;
    uint8 u8Status = 0;
    uint8 i;
    ZPS_tsAplAib *psAplAib = ZPS_psAplAibGetAib();

    u16GroupId = 2305;

    vLog_Printf(TRACE_APP, LOG_DEBUG, "\nAdd Group ID: %x", u16GroupId);
    vLog_Printf(TRACE_APP, LOG_DEBUG, "\nAdd EndPoint: %x", 1);

    /* Request to add the bridge to a group, no name supported... */
    u8Status = ZPS_eAplZdoGroupEndpointAdd(u16GroupId,
                                           1);

    for (i = 0; i < psAplAib->psAplApsmeGroupTable->u32SizeOfGroupTable; i++)
    {
        vLog_Printf(TRACE_APP, LOG_DEBUG, "\nGroup ID: %x",
                    psAplAib->psAplApsmeGroupTable->psAplApsmeGroupTableId[i].u16Groupid);
        vLog_Printf(TRACE_APP, LOG_DEBUG, "\nEndPoint 0: %x",
                    psAplAib->psAplApsmeGroupTable->psAplApsmeGroupTableId[i].au8Endpoint[0]);
    }
}
