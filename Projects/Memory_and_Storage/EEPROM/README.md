# EEPROM

- [EEPROM](#eeprom)
- [Questions](#questions)
- [Initial research](#initial-research)
- [Options to Buy](#options-to-buy)
    - [I2C](#i2c)
    - [SPI](#spi)
    - [Extra](#extra)
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

### Extra 
Will get some [adapter boards](https://www.aliexpress.com/item/1005007636152533.html).





# Project Ideas

Want to make a [drive from VOTV](https://voicesofthevoid.wiki.gg/wiki/Drive). 
This would contain information like a file name, signal level and possible the audio data itself.
