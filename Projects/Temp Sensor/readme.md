# Temperature Sensor

The project will focus on making an STM32 basted temperature sensor. The data will time stamped and logged to non-volatile memory.

This project will start off using the STM32F103C8T6 but I will make it as portable as possible, I will want to port it to an STM32G4 at some point.
I am just using what I have lying around, I will use a DHT11 temperature and humidity sensor, DS1302 as the RTC and will save data to GD25Q32 NOR flash.

USB will be used to set the time and extract the data,

