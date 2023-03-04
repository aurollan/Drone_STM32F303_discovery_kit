# Configuration
Here we want to chose which peripheral we will use to connect our sensors.
According to our setup, we only need 3 communication bus to configure.
- UART for user/drone communication. We will use a simple uart over bluetooth.
- I2C for communication with the IMU. The IMU will send gyroscope, accelleration and magnetic sensor data.
- TIMER for motor PWM. We will rely on a timer managing 4 PWM. But if this feature is not available on your MCU you could set up to 4 timers.

This should be enough.

# Position configuration file
src
|
|
|___> mcu
    |
    |
    |___> configuration.h
