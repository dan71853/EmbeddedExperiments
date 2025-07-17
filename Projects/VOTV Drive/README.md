# VOTV Drive Project
![alt text](Images/Ref-AllDrives.png)

- [VOTV Drive Project](#votv-drive-project)
- [Linked Research](#linked-research)
- [Overview](#overview)
- [Goals](#goals)
- [Plan](#plan)
  - [Memory](#memory)

# Linked Research
- [EEPROM](/Research/Memory_and_Storage/EEPROM/README.md)
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

Volatile needs constant power, there will be a battery in the drive but this will not be used for the memory. It is more thematic that the memory can 
