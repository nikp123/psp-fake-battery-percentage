#include <pspkernel.h>
#include <kubridge.h>
#include <pspmoduleinfo.h>
#include <pspmodulemgr.h>
#include <pspthreadman.h>
#include <pspthreadman_kernel.h>
#include <pspctrl.h>
#include <string.h>
#include <pspctrl_kernel.h>
#include "main.h"

PSP_MODULE_INFO("Power Spoofer", 0x1000, 1, 2);

int module_start(SceSize args, void *argp) __attribute__((alias("_start")));
int module_stop(SceSize args, void *argp) __attribute__((alias("_stop")));

SceUID  main_id;

int _start(SceSize args, void *argp){
	main_id = sceKernelCreateThread("Main_Func", &fx_mainFunc, 0x18, 0x512, 0, NULL);
	sceKernelStartThread(main_id, 0, NULL);
	return 0;
}

int _stop(SceSize args, void *argp){
 	sceKernelTerminateDeleteThread(main_id);
	return 0;
}
