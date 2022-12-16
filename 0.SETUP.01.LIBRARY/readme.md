# Why use a library
We use a library because we don't want to code everything from scratch.
If you want to start we everything from scratch you can check my other 
tutorial.
This particular library is a Hardware Abstraction Layer.

It does only one thing that we need:
- Offer functions to configure our microcontroller

We will code everything else.

# Why this library
Because it's an error-proof library widely used.
It is (was) developed by the manufacturer, ST in our case.
It is easy to understand and well documented. And this point matter
because you will need to understand what is happening.

# Do I need every file in this library ?
No you won't, we just need `Libraries/STM32F30x_StdPeriph_Driver/` and some 
headers.

# Could I use another library ?
Yes, the first part is just setting up our component, and communicate with
peripherals (the Hardware Abstraction Layer).
You could use another Hardware Abstraction Layer library like
`libopencm3` for example.

# Which layer the HAL cover ?
|-----------------------------------------------------------------------|
|                   Application layer input/output                      |
|-----------------------------------------------------------------------|
        /\              /\             ||              /\  
        ||              ||             ||              ||
  angular velocity  rate of change  motor power   communication
        ||              ||             ||              ||       
        ||              ||             \/              \/
|-----------------------------------------------------------------------|
|                   Raw data interpretation layer                       |
|-----------------------------------------------------------------------|
        /\              /\             ||              /\  
        ||              ||             ||              ||
   gyro raw data    acc raw data  duty cycle data   string data
        ||              ||             ||              ||       
        ||              ||             ||              ||
|-----------------------------------------------------------------------|
|       || Hardware     || Abstraction ||      Layer   ||               |
|-----------------------------------------------------------------------|
|       ||              ||             ||              ||               |
|       ||              ||             \/              \/               |
|      I2C             I2C         PWM (TIMER)       USART              |
|-----------------------------------------------------------------------|

As you can see, the HAL support calls to microcontroller feature from the 
raw data interpretation layer.
