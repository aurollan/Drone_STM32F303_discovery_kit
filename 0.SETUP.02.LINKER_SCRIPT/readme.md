# Linker script
This is a local copy of the "original" linker script that you can find here:

    0.SETUP.01.LIBRARY/STM32F30x_DSP_StdPeriph_Lib_V1.3.0/Projects/STM32F30x_StdPeriph_Templates/TrueSTUDIO/STM32F303xC

I have commented those three (last) lines causing me compilation issues but you
should not have issue with the original linker script file.

    /* Remove information from the standard libraries */
    /DISCARD/ :
    {
        /* libc.a ( * ) */
        /* libm.a ( * ) */
        /* libgcc.a ( * ) */
    }

# Not enough information ?
Check out my other tutorial, I explain more in detail why and how we use a
linker script. Or look for answer on the internet, there is a lot of good
article on this topic.
