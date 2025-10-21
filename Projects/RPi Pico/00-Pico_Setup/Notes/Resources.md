# Resources

<!-- ## Glossary -->

## External Links
### Guides
- [RPi Getting Started Guide](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)

### Tools
- [RPi SDK](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html#content)
- [Latest debugprobe_on_pico.uf2](https://github.com/raspberrypi/debugprobe/releases/latest)

### Datasheets
- [Pico 2 W](https://datasheets.raspberrypi.com/picow/pico-2-w-datasheet.pdf)


## Local links
- [Project Overview](../README.md)
- [Project Plan](./Project_Plan.md)
- [Notes](./Notes-0.md)


<!-- ## Useful Commands/Shortcuts
## Pinouts/Diagrams
-->
## Common Issues 

### Pico Upload Issue
This error can happen when trying to upload for the first time
``` 
No accessible RP-series devices in BOOTSEL mode were found.
but:
RP2350 device at bus 3, address 10 appears to be in BOOTSEL mode, but picotool was unable to connect. Maybe try 'sudo' or check your permissions.
```
This can be fixed by copping [these rules](https://github.com/raspberrypi/picotool/blob/master/udev/60-picotool.rules) to /etc/udev/rules.d/ 

`sudo cp 60-picotool.rules /etc/udev/rules.d/`
