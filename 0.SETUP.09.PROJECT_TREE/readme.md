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
        |______> mcu
        |       |
        |       |____> setup clock
        |       |
        |       |____> setup pwm
        |       |
        |       |____> setup uart
        |       |
        |       |____> setup i2c
        |       |
        |       |____> etc...
        |
        |______> sensors
        |       |
        |       |____> setup communication
        |       |
        |       |____> setup motors
        |       |
        |       |____> setup gyro
        |       |
        |       |____> setup acc
        |       |
        |       |____> etc...
        |
        |______> application (drone)
                |
                |____> start
                |
                |____> move
                |
                |____> balance
                |
                |____> stop
                |
                |____> etc...

## Explanation
### mcu
In the `mcu` repository we will setup the microcontroller communication 
interfaces.

### Sensors
In the `sensors` repository we will translate raw data received to actual 
information we need. We will also translate informations transmitted to actual 
raw data.

### Application
In the `drone application` repository we will code the drone behavior using informations gathered.
