# 00-Pico_Setup

<!-- <img src = "./Notes/Testing_Images/" height = "350"> -->

- [00-Pico\_Setup](#00-pico_setup)
  - [Project Outline](#project-outline)
  - [Project Summary](#project-summary)
  - [Related Documents](#related-documents)



## Project Outline

The goal of this project is to read both an analog and a digital input and send the data to a PC via serial.

See [Project PLan](./Notes/Project_Plan.md) for more details.

## Project Summary

This project went pretty well, the C SDK has simple functions for IO and UART. I discovered that I can use the debugger to read com port 0. This was a lot more convenient because I could use printf and I didn't need to use a second USB with an FTDI. 

The button was very noisy which caused problems when the interrupt was added so I had to add some debouncing using a capacitor and a timer.

Here is a the serial port when the button is pressed as the pot is turned.
``` 
Button is Pressed, Pot is 4
Button is Pressed, Pot is 965
Button is Pressed, Pot is 2895
Button is Pressed, Pot is 4095
```

## Related Documents
- [Project Plan](./Notes/Project_Plan.md)
- [Resources](./Notes/Resources.md)
- [Work Log](./Notes/Work_Log-0.md)
- [Checklist](./Notes/Checklist.md)
