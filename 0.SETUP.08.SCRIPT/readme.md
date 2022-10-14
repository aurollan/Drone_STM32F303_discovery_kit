# Scripts

## minicom.sh
Just launch the minicom to send and receive from UART.

## minirc.dfl
A minicom configuration file matching the microcontroller UART configuration.
We need it to decode UART communication send on the bus.

## openocd_launch.sh
Just a command to launch openOCD with the right argument in the background. 
Not needed to flash but needed to launch a debug session.

## openocd.gdb
A script of command to enter in debug mode while openOCD is launch in the 
background (openocd_launch.sh).


## Why use scripts ?
Those steps are easy to write but it is really annoying to repeat them each 
time.

## Can I make my own ?
Yes, you should.
