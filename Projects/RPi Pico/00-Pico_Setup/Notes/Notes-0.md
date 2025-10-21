# Notes 0

## 25/10/20

### Blink Example

- Following [this guide](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf) to setup the SDK with VSCode
- Did not use the RISC-V, will try that later
- Saved the project in `EmbeddedExperiments/Projects/RPi Pico/00-Pico_Setup/Code/`
- It did take a couple of minutes to download and install the tool chain
- I already had VSCode open for this repo, but the tool opened the new code in a new window. I will leave it in this new window and the file paths might break otherwise
- A gitignore file was created, it had !.vscode/* which means to not ignore the anything in the vscode, I will just leave this gitignore alone 
- Get this error when trying to upload
``` 
No accessible RP-series devices in BOOTSEL mode were found.
but:
RP2350 device at bus 3, address 10 appears to be in BOOTSEL mode, but picotool was unable to connect. Maybe try 'sudo' or check your permissions.
```
- There is a note in [Appendix B](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf#%5B%7B%22num%22%3A27%2C%22gen%22%3A0%7D%2C%7B%22name%22%3A%22XYZ%22%7D%2C115%2C841.89%2Cnull%5D) of the Getting Started guide, but this is not that helpful
- Instead copy [these rules](https://github.com/raspberrypi/picotool/blob/master/udev/60-picotool.rules) to /etc/udev/rules.d/ 
- `sudo cp 60-picotool.rules /etc/udev/rules.d/`
- This fixed the issue and the blink code uploaded 

### Debug Example
- Need to go to the [Debug with a second Pico](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf#debug-probe-with-pico-series) chapter.
- Download the [latest debugprobe_on_pico.uf2](https://github.com/raspberrypi/debugprobe/releases/latest), I am using a Pico 1 so need to use the debugprobe_on_pico.uf2 
- Boot pico while holding BOOTSEL and copy the .uf2 file onto the device
- Problems when starting the debugger
- libhidapi is missing, install with `sudo apt install libhidapi-hidraw0`
- Might also need `sudo apt install gdb-multiarch` 