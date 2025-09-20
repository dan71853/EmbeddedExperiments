# Stepper Motors

- [Stepper Motors](#stepper-motors)
- [Initial Research](#initial-research)
- [Stepper Motor Testing](#stepper-motor-testing)


# Initial Research

The [initial research](./Initial_Research.md) was focused on a motor suited for the [VOTV Drive](../../../Projects/VOTV%20Drive/README.md) project.

# Stepper Motor Testing

Here is some notes on testing the [Pancake Stepper Motor (SP-35RC-810S)](./Pancake_Stepper_Motor_(SP-35RC-810S).md) using a RPi Pico to generate the step sequence.  

I plan on making a basic full step stepper driver using logic gates. This starts with a low frequency clock which will be made using a 555 timer, here are the notes on the [555 Timer](./555Timer.md).

The next step is to make a 2 bit binary counter, notes on the counter can be found [here](./2BitRippleCounter.md).

Next logic gates are used to create the 4 states needed for each pin, notes cn be found [here](./StepperLogicGates.md).

The final step is to connect the motor to the existing circuit. This uses the same H-Bridge as used in [Pancake Stepper Motor (SP-35RC-810S)](./Pancake_Stepper_Motor_(SP-35RC-810S).md). I tested 2 different bipolar stepper motors, the results can be found [here](./Driving_Stepper_Motors.md).




