#include <pspmodulemgr.h>
#include <pspiofilemgr.h>
#include <pspthreadman.h>
#include <systemctrl.h>
#include "rethook.h"

/*
int fxPowerGetBatteryLifePercent(void)
{
	return 100;
}

int fxPowerIsLowBattery(void)
{
	return 0;
}

int fxPowerIsBatteryExist(void)
{
	return 1;
}*/

void fx_PatchSystemFunc(int address, int topatch)
{
	*((unsigned int*)(address)) = 0x03e00008;
	*((unsigned int*)(address+0x04)) = topatch;
	return;
}

void fx_mainFunc()
{
	sceKernelDelayThread(15000000);
	while(!sceKernelFindModuleByName("sceKernelLibrary"))
	sceKernelDelayThread(100000);
	/*SceKernelThreadInfo info;
	SceUID id;
	pspSdkReferThreadStatusByName("nitePRThread", &id, &info);
	sceKernelSuspendThread(id);*/
	//int addresspercent = sctrlHENFindFunction("scePower_Service", "scePower_driver", 0x2085D15D);
	int addresslowbattery = sctrlHENFindFunction("scePower_Service", "scePower_driver", 0xD3075926);
	//int addressexist = sctrlHENFindFunction("scePower_Service", "scePower_driver", 0x0AFD0D8B);
	//fx_PatchSystemFunc(addresspercent, fx_rethookPercent());
	fx_PatchSystemFunc(addresslowbattery, fx_rethookIsLowBattery());
	//fx_PatchSystemFunc(addressexist, fx_rethookIsBatteryExist());
	int status;
	sceKernelStopUnloadSelfModule(0, NULL, &status, NULL);
	return;
}
