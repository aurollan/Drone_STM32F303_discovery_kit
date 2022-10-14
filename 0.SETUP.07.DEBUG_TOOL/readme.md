# Flash tool /!\ HARDWARE REQUIRED /!\
First of all, there is a lot of tool to debug your device.
Of course you can use the tool you want because it won't be relevant
in any part of the project.
Just remember that debugging require hardware and software.
Make sure you use a compatible duo.

## Software debug tool
On the software part I use openOCD but I need another tool to provide debugger 
feature to OpenOCD: GDB.

    sudo apt-get install gdb-mutltiarch

### Why use GDB ?
GDB is a well known and powerful debug tool available on ARM architecture.
It support all of expected debugging feature. I use it on a terminal with
`layout src` to follow the code flow.

## Hardware debug tool
For this project I use an STM32F303 discovery kit.
This discovery kit is delivered with an in board st-link interface.
Again, you can chose any tool you like.
