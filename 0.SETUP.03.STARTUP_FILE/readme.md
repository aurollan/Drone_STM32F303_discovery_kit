# Start up file
This is a local copy of the "original" startup file that you can find here:

    0.SETUP.01.LIBRARY/STM32F30x_DSP_StdPeriph_Lib_V1.3.0/Libraries/CMSIS/Device/ST/STM32F30x/Source/Templates/TrueSTUDIO

I have commented this line causing me compilation issues but you
should not have issue with the original startup file.

    /* Call static constructors */
        /* Useless for now */
        /* bl __libc_init_array */

# Not enough information ?
Check out my other tutorial, I explain more in detail why and how we use a
start up file. Or look for answer on the internet, there is a lot of good
article on this topic.
