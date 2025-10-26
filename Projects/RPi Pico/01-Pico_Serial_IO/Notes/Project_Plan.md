# Project Plan

## Goal
The goal of this project is to connect a button and a potentiometer to the Pico. The pico will monitor these inputs and relay the state to a PC via a serial connection. This project will be broken up into several steps, It will start small with just getting the inputs to be polled and read using the debugger. Next the serial port wil be setup and finally the button detection will be moved to an interrupt.

## Scope
- Will use the Pico 2 W as the main device and an additional Pico as a debugger
- The project will be coded in VSCode using the Raspberry Pi C/C++ SDK 
- Will start with a new VSCode pico extension project
- Will use an internal pullup resistor to connect to the button
- Will connect a potentiometer to an analog pin to get an adjustable analog reading
- Will connect to the PC using a USB serial to UART FTDI adaptor
- The button will be detected using an external interrupt

## Scope Changes
- Will not use an FTDI controller, instead will send serial data through the debugger. See [Using UART](Work_Log-0.md#using-uart)
- Need to add debouncing to the button when using interrupts

## Steps
- [x] Create a new Pico project
- [x] Connect a button to a digital input and read its state, confirm this with the debugger
- [x] Connect a potentiometer to an analog input and read this
- [x] Poll this data and send it via a serial port
- [x] Connect the serial port to a PC and confirm it is the correct data
- [x] Change the digital input to be an external interrupt, and only send data to the PC when the button is pressed
  
## Tools
 