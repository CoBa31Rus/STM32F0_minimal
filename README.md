# STM32F0_minimal
STM32F0 minimal CMSIS project for linux

This is my minimal STM32F0 project with CMSIS, ARM-NONE-EABI, OpenOCD.
Include project for geany.

# Required:

1)Install OpenOCD for debug using GDB.

2)Install or download ARM-NONE-EABI toolchain.

3)make.

 # How to:
 
1)Change arm toolchain path in Makefile TOOLPATH, 
  if your arm toolchain is installed from repo then comment TOOLPATH.
  
2)In linkerscript change ROM and RAM lenght for your device.

3)For compile execute make all.

4)For clean make clean.

5)For debug with GDB make debug.

6)For load make load.

7)Change debug level in variable OPT.
