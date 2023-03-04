# Project tree

|
|_____> Makefile
|
|_____> readme.md
|
|_____> src
        |
        |______> main.c
        |
        |______> application (drone)
        |       |
        |       |____> commands
        |       |
        |       |____> balance
        |       |
        |       |____> etc...
        |
        |______> features
        |       |
        |       |____> communication
        |       |
        |       |____> motors
        |       |
        |       |____> gyroscope
        |       |
        |       |____> accelerometer
        |       |
        |       |____> etc...
        |
        |______> mcu
               |
               |____> clock
               |
               |____> pwm
               |
               |____> uart
               |
               |____> i2c
               |
               |____> etc...


## Explanation
### Application
In the `drone application` repository we will code the drone behavior using informations gathered.

### Features
In the `feature` repository we will code the feature the application rely on to work.

### MCU
In the `mcu` repository we will setup the microcontroller configuration the features relies on to work.
