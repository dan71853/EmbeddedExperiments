# Notes 0

## 25/10/23

### Project Setup
- I used the VSCode extension to create a new project 
- Set the board to the pico 2W and included the UART example, left everything else as default
- Didn't need to download anything this time so the project was created instantly

``` C
// Setup digital input
gpio_init(BTN_PIN);
gpio_set_dir(BTN_PIN, false);         // Set as input
gpio_set_pulls(BTN_PIN, true, false); // Enable pullup resistor

gpio_get(BTN_PIN); //Read Pin
```   
The pin can be setup an read with these commands
- Looks like there is no function that can do this all at once, I would have to make this
- Becaus the digital pin uses an internal pullup resistor, when the button is pressed the pin is read as low, and high when the button is not pressed
- This could be reversed by using a pulldown or flipping the bit that is read

<img src="./Images/Test-Button-Unpressed.png" height = "300">


<img src="./Images/Test-Button-Pressed.png" height = "300">

Here is the pin state as seen by the debugger, The top image is when the button is not pressed. This is reading as true as expected.

