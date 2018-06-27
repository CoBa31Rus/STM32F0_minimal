# STM32F0_minimal
STM32F0 minimal CMSIS project for linux

This is my minimal STM32F0 project with CMSIS, ARM-NONE-EABI, OpenOCD.
Include project for geany.
# Required:
-Install OpenOCD for debug using GDB
-Install or download ARM-NONE-EABI toolchain
-make

# How to:
-Change arm toolchain path in Makefile TOOLPATH, 
  if your arm toolchain is installed from repo then comment TOOLPATH
-In linkerscript change ROM and RAM lenght for your device
-For compile execute make all
-For clean make clean
-For debug with GDB make debug
-For load make load
-Change debug level in variable OPT
