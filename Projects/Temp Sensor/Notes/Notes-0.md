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
