
Wat r this?
-----------

This repo contains source code for a PSP module that patches
what percentage of battery should the console shut down with.

Why? What's your motivation
---------------------------

I got one of those bad clone batteries that not only have a bad cell inside them
but also measure the remaining battery life inaccurately. One way I was able to
address this is by creating ~~stealing~~ this module that changes when the PSP
would shut down or consider the battery needing a charge.

How does it work?
-----------------

Well basically it patches a system function using some CFW dark magic.

* ``main.c`` shows how the functions got patched
* ``rethook.h`` contains the function prototypes of the functions being patched; and
* ``rethook.S`` contain the patched function machine code (MIPS assembly)

For our uses only ``fx_rethookIsLowBattery`` is used *(although this isn't the
actual functions name)*. In it we have a single instruction as follows:

``addiu $v0, $zero, 50`` where 50 is the percentage value that we want.

How do I use it?
----------------

1. Modify the ```rethook.S`` function with the value that you want.
2. Install the [psp toolchain](https://github.com/pspdev/pspsdk)
3. Install [this library](https://github.com/uofw/uofwinst) using said toolchain
    1. Run these two before compiling tho:
    2. ``` find . -type f -not -path . -exec sed -i 's/-mno-crt0 //g' {} +```
    3. ```find . -type f -not -path . -exec sed -i 's/python/python2/g' {} +```
    4. These should fix compilation issues that i've encountered
4. To install the above library you need two more steps:
    1. ```sudo cp -rf include/* /usr/psp/include/```
    2. ```sudo cp -rf libs/* /usr/psp/libs/```
5. Run make in this repo
6. Copy the resulting .prx file onto your MemoryStick(TM)
7. Update your ``seplugins/vsh.txt`` accordingly

Credits
-------

I used the library uofwinst which is GPL-3 and automatically makes this GPL-3 as
well. As well as the fact that I've stolen 99% of the code from [this](https://www.brewology.com/downloads/download.php?id=9358)

Additional stuffs
-----------------

You can download custom percentages from the releases page in this repo.

