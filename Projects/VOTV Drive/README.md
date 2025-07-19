# VOTV Drive Project
![alt text](Images/Ref-AllDrives.png)

- [VOTV Drive Project](#votv-drive-project)
- [Linked Research](#linked-research)
- [Overview](#overview)
- [Goals](#goals)
- [Plan](#plan)
  - [Memory](#memory)
  - [LEDs](#leds)
  - [Battery](#battery)

# Linked Research
- [EEPROM](/Research/Memory_and_Storage/EEPROM/README.md)
- [NOR and NAND Flash](/Research/Memory_and_Storage/NOR_NAND_Flash/README.md)
- [Batteries](/Research/Power/Batteries/README.md)

# Overview

Want to make a [Drive](https://voicesofthevoid.wiki.gg/wiki/Drive) from [VOTV](https://mrdrnose.itch.io/votv). </Br>
These are used ingame to store and move data/signals between different machines in the game.

There are 4 lights on the drive, 3 blue lights and a red or green light. These lights indicate the state of the signal stored on the drive.
A red light indicates that there is no signal data, this light will turn green when there is data. </Br>
The blue lights on the top indicate what level the signal has been processed to, starting at no lights for level 0 and going up to 3 lights for level 3.

<table>
  <tr>
    <td><img src="./Images/Ref-Process-A.png" height="400"/></td>
    <td><img src="./Images/Ref-Process-B.png" height="400"/></td>
  </tr>
</table>

The drives get plugged into a few machines, here it is plugged into the processing unit, I will call this the master device. The master unit can then read or write data to the drive. 

# Goals

- Create a drive that can store a small audio file.
- Be able to set the LED state.
- Have some battery to keep the LEDs lit.
- Have an easy way to slot the drive into a master device.

# Plan

## Memory

There are a few options for memory, but these can be split into 2 categories; </Br> 
Volatile and Non-Volatile. 

Volatile needs constant power, and there will be a battery in the drive. However long term storage like this is normally non-volatile so data isn't lost when the power runs out.

This will probably be a choice between an EEPROM or NOR flash. Will need to do some experiments to decide which is best. I am leaning towards the I2C EEPROM. 

## LEDs
I have chosen [WS2812D RGB LEDs](https://www.aliexpress.com/item/1005005871456289.html), I got the foggy surface so the LEDs are not as harsh to look at. This is a similar [datasheet](https://www.alldatasheet.com/html-pdf/1570129/WORLDSEMI/WS2812D-F5/569/1/WS2812D-F5.html), however the LED shape is not and current are slightly different to whats listed on the store page.

## Battery

There is the choice between rechargeable or non-rechargeable batteries. First I will calculate the current draw of the LEDs and the memory.

Looking at the [I2C EEPROM datasheet](https://ww1.microchip.com/downloads/en/devicedoc/21203m.pdf).
The standby current is 1uA, reading is 400uA and writing is 3mA. Writing is the most energy intensive, but the device will be in standby for the majority of the time. Assuming the device is in standby 99% of the time then the average current will probably be less than 100uA.

The biggest power draw will be the LEDs, the datasheet states that the LEDs are 20mA per colour channel. The only colours needed will be red, green and blue, so only a single colour channel will need to be used at a time. The maximum number of LEDs on at once is 4, this gives a total of 80mA at maximum brightness. The LEDs will probably not be set to the maximum brightness but the worst case should be considered.

The LEDs are the majority of the power draw so the EEPROM can be ignored. This gives a current draw of 80mA.</Br>
I have a salvaged CR123A battery, this is a non rechargeable battery, this should be 1500mAh but Im unsure of the current charge. Assuming fully charged then it will last around 37 hours of continuous use. This rules out non rechargeable batteries.


