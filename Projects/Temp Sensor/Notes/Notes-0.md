# Notes 0

## 12/12/2025

### Part Selection and Finding Datasheets

- Already have a STM32F103C8T6 so I will use that 
- Using the sensors and flash I already have
- I checked all the peripherals and they are all 3.3V compatible
- Data can be saved as raw ascii
  - This is what a line could look like `25-12-12:08-49, 23.5, 56.8`, this is 26 bytes +1 for new line
  - The flash is 32 MBit = 4 MBytes, this should be able to store around 150,000 entries  
  - At 1 entry per second this is around 2 days worth of data
  - I will use raw ascii to start off with to make it easier to debug, then I will store data as raw binary later
  - I will probably have a header at the start of the storage that points to the next free bit of data
  - I might need to batch write data
  - I should look at wear leveling 

### STM32 USB data logging

- I want to use the onboard USB port to log data
- This [guide](https://deepbluembedded.com/stm32-usb-cdc-virtual-com-port-vcp-examples/) shows how to set up the blue pill with a virtual COM port
- I will start with this and try print something to a serial port
- I had some problems with getting the cubeIDE compiling, it was complaining about some RTOS packages but I didn't need them
- This was only solved by completely removing the workspace and starting again.
- I tried the example code from the guide but I was not seeing anything in the serial port
- A common problem is some clones have the wrong D+ pullup resistor but I confirmed that there is the correct 1.5K resistor between D+ and 3.3V
- Tried some more stuff and now the device is appearing on the PC but nothing is being sent
- As UART is not needed in the final design I am just going to use a external FTDI cable
- Following this [guide](https://microcontrollerslab.com/stm32-blue-pill-uart-tutorial-polling-method/), need to use asynchronous mode and move RX and TX to B7 and B6
- I connected the FTDI converter, but I couldn't see it `/dev/ttyACM*`, but it was actually under `/dev/ttyUSB0` 
- I think I had to set the baud rate using `stty -F /dev/ttyUSB0 115200 raw -echo` 
- I can now send data using HAL_UART_Transmit()
- I tried sending data from the PC to the micro, this wasn't working because cat can only read
- I had to install screen, this worked with `screen /dev/ttyUSB0 115200`
  - Close screen with Ctrl+A  k
- I can listen to data with HAL_UART_Receive()

## 14/12/2025
### DHT11 Temperature Sensor
- I will need some sort of timer for a timeout when waiting 
- Can use HAL_GetTick() to get the current count in milliseconds