# EEPROM

- [EEPROM](#eeprom)
- [Questions](#questions)
- [Initial research](#initial-research)
- [Options to Buy](#options-to-buy)
    - [I2C](#i2c)
    - [SPI](#spi)
- [EPROM](#eprom)
    - [Extra](#extra)
    - [Final Order](#final-order)
- [More Research](#more-research)
    - [I2C 24LC256I](#i2c-24lc256i)
    - [SPI 25LC256](#spi-25lc256)
    - [Parallel EPROM M27C512](#parallel-eprom-m27c512)
- [Project Ideas](#project-ideas)

# Questions
- Why use EEPROM?
  - When is EEPROM better?
- How to access the storage?
  - What hardware communication is used?
  - Is the data just raw memory or can there be structure/directories?
  - What is the speed?
  - Is there any timing requirements?
- Is this different to internal memory on an microcontroller?
- How to check data integrity 


# Initial research

Datasheets for the [24LC256](https://ww1.microchip.com/downloads/en/devicedoc/21203m.pdf) 

Might want an [EEPROM programmer](https://www.aliexpress.com/w/wholesale-eeprom-programmer.html?g=y&SearchText=eeprom+programmer&selectedSwitches=filterCode%3Achoice_atm).

Might look at some [EPROM](https://www.aliexpress.com/item/32891060994.html) for fun.



# Options to Buy
The [24C02](https://www.aliexpress.com/w/wholesale-24C02.html?g=y&SearchText=24C02&selectedSwitches=filterCode%3Achoice_atm), [datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/21202J.pdf). But this is 5V, want something 3.3V compatible.

Will probably get DIP package, then it can be make on prototype board.

### I2C
The [24LC256](https://www.aliexpress.com/w/wholesale-24LC256.html?g=y&SearchText=24LC256&selectedSwitches=filterCode%3Achoice_atm) looks like a cheap option on Aliexpress. Here is the [datasheet](https://ww1.microchip.com/downloads/en/devicedoc/21203m.pdf). 
All 3 24XX256 options support 3.3V. This difference is the speed, some can only be used at full speed at voltages greater than 2.5V. This means that the 24AA256 and the 24LC256 will be the same. I don't need the full 1MHz speed for my testing so will go with the AA or LC. 
The LC is [more in stock](https://www.aliexpress.com/w/wholesale-24LC256-DIP-.html?g=y&SearchText=24LC256+DIP+&selectedSwitches=filterCode%3Achoice_atm) with a dip package.

[This store](https://www.aliexpress.com/item/1005007109141216.html) has a few different options for storage capacity (in KB). Probably don't need more than 256, but will do more research before I decide.

Will get [24LC256I SOP8](https://www.aliexpress.com/item/1005006918590140.html). This will need an adaptor from sop-8 to dip.

### SPI
25LC256 (25LC256-I/P), cant find a dip package on Aliexpress.
Will get the [25LC256](https://www.aliexpress.com/item/1005006706668024.html) in the sop-8 package.

# EPROM
Will get some EPROM just to experiment a bit. Found [M27C512](https://www.aliexpress.com/item/1005009205345368.html), [Datasheet](https://media.digikey.com/pdf/data%20sheets/st%20microelectronics%20pdfs/m27c512.pdf). This will be good to play with a parallel data bus.

Note: it is only 5V so might need a level shifter.

### Extra 
Will get some [adapter boards](https://www.aliexpress.com/item/1005007636152533.html).

[Level shifter](https://www.aliexpress.com/item/1005009385587772.html), [Datasheet](https://www.ti.com/lit/ds/symlink/txs0108e.pdf). Bidirectional and can go from 3.3V to 5V.  

Will need some resistors for address and pullup resistors, and some capacitors for decoupling. I already have these.

### Final Order
- 10 x [I2C 24LC256I SOP8](https://www.aliexpress.com/item/1005006918590140.html) [Datasheet](https://ww1.microchip.com/downloads/en/devicedoc/21203m.pdf)
- 5 x [SPI 25LC256 SOP8](https://www.aliexpress.com/item/1005006706668024.html) [Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/20005715A.pdf)
- 20 x [Adapter Boards](https://www.aliexpress.com/item/1005007636152533.html) [Datasheet](https://media.digikey.com/pdf/data%20sheets/st%20microelectronics%20pdfs/m27c512.pdf)
- 5 x [M27C512](https://www.aliexpress.com/item/1005009205345368.html)
- 3 x [Level shifter](https://www.aliexpress.com/item/1005009385587772.html)
  

# More Research
Have decided on the 24LC256I and 25LC256. These are both 256 KB of memory and in a SOP8 package. Both are 3.3V compatible.

Both are made by microchip, these are essential the same chip but one is I2C and the other is SPI. This should make for a good comparison.

### I2C 24LC256I
This will need pullup resistors on the clock and data lines. 

There is the Write Protect pin, this would be good to see in action. Tieing it LOW or leaving it floating will enable normal operations.

The address will also need to be set, this can be done by tieing the address pins to high or low.
It has a 7-bit address, the 4 MSB bits are hardcoded, the rest are set by the pins. `1 0 1 0 A2 A1 A0`.

Will look more into the I2C protocol when making the software, want to look at the paging, acknowledge polling and Contiguous Addressing.

For reading look at the difference between random and sequential reads

The LC version should go up to 400 kHz clock speed. I will test this, I want to see how this translates to read and write speeds. How does the write cycle delay time effect this speed.

### SPI 25LC256
This is very similar to the I2C version. This has a 10 MHz clock, I want to see how much faster this is compared to the I2C version. This also has a 5 ms write time so the write speed is probably not much faster.

SPI is a bit different to I2C, the SPI version has a list of instructions to say when to read or write. As SPI does not have a read or write bit like I2C. 
But there is more than just read and write, there is actually a status register that is not available on the I2C version. I want to see if this status register can be used.

Looks like the device supports both 0 and 3 SPI modes, I will want to do some more tests on these to better understand the difference. 
[Here](https://www.analog.com/en/resources/analog-dialogue/articles/introduction-to-spi-interface.html) is some more information on the modes.

The write enable is software controlled through the status register, unlike the pin on the I2C version. But there is also a hold function which I want to better understand.

Need to test max read and write speeds.

### Parallel EPROM M27C512
[Datasheet](https://media.digikey.com/pdf/data%20sheets/st%20microelectronics%20pdfs/m27c512.pdf), Looks like there is an output enable and a chip enable. 

It is 5V so make sure a level shifter is used.
Will need to do a lot of research into how to use this. Will do this when it arrives. 


# Project Ideas

Start out with reading and writing simple data on a breadboard.


Want to make a [drive from VOTV](https://voicesofthevoid.wiki.gg/wiki/Drive). 
This would contain information like a file name, signal level and possible the audio data itself.
Would also want to add RGB LEDs, a battery and possibly look at board edge connectors.
