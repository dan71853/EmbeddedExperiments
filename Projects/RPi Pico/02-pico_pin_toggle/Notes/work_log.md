# Work Log

## 4/11/2025

### C Arm API Setup
- Will start off with the C Arm API
- Made a project found in [here](../Code/02-c_arm_api/)
- Will connect an LED to GPIO pin 16
- Using a 220Ω should give a current of 4mA
- [Section 14.9.4.1](https://datasheets.raspberrypi.com/rp2350/rp2350-datasheet.pdf#%5B%7B%22num%22%3A1342%2C%22gen%22%3A0%7D%2C%7B%22name%22%3A%22XYZ%22%7D%2C115%2C261.612%2Cnull%5D) has details on the current limit of the RP2350, looks like there is different drive strength settings
- [Here](https://www.raspberrypi.com/documentation/computers/raspberry-pi.html#gpio-pads-control) is some more documentation, looks like the pins are ok up to 16mA so I don't need to worry
- I created some simple blink code using GPIO 16
- Started with a 1s period so I could confirm visually that the LED was blinking
- I removed all delay and the LED did not appear to turn on
- I looked with the scope and there was a 3.3V 'square wave'

<img src="./Images/C_Arm_API-30MHz.jpg" height=300>

- This was around 30MHz and was not very square wave shaped
- My scope is 100MHz so there may be some aliasing going on, I will need to look into this further
- I will try find the clock rate and calculate what I expect the signal to be
- I will probably reduce the clock rate so I can compare the different architectures