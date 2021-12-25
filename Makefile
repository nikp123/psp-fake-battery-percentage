TARGET = fx_powerspoof
OBJS =  main.o crt0.o rethooks.o

PSP_LARGE_MEMORY=1
BUILD_PRX=1
PSP_FW_VERSION = 150

USE_KERNEL_LIBS = 1
USE_KERNEL_LIBC = 1

INCDIR =
CFLAGS = -O2 -G0 -w -msingle-float -g
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
LIBDIR =
LIBS =  -lpspchnnlsv -lpsputility -lpspsystemctrl_kernel

LDFLAGS = -nostdlib  -nodefaultlibs -g

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

lite:
	psp-packer $(TARGET).prx
