# Compiling tool
I use the arm-gcc tool chain to compile my project.

    debian:
    sudo apt-get install gcc-arm-none-eabi

The command could be slightly different depending on your distribution 
and package manager.
Use your package manager to install the tool chain.

## Why use this tool chain ?
It is based on GCC, is open-source, works smoothly, is manufacturer independent
and IDE independent.
A lot of people works already with GCC and are familiar with this tool.
This is the tool you are most likely to find in your work environment.
But this is not the only tool. `Clang` is also available and working 
perfectly.

# Not enough information ?
Check out my other tutorial, I explain more in detail how we use this
compiler. Or look for answer on the internet, there is a lot of good
article on this topic.
