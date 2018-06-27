#!/bin/bash

# start xterm with openocd in the background
xterm -e openocd -f interface/stlink-v2.cfg -f target/stm32f0x.cfg &

# save the PID of the background process
XTERM_PID=$!

# wait a bit to be sure the hardware is ready
sleep 2

# execute some initialisation commands via gdb
../toolchain/bin/arm-none-eabi-gdb --batch --command=ext/run.gdb template.elf

# start the gdb gui
nemiver --remote=localhost:3333 --gdb-binary="$(which ../toolchain/bin/arm-none-eabi-gdb)" template.elf

# close xterm when the user has exited nemiver
kill $XTERM_PID
