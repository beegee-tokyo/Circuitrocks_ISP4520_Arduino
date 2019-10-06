# Arduino Core for Circuitrocks Alora Boards

This repository contains the Arduino BSP for the Circuitrocks Alora boards:

- [Circuitrocks Alora ISP4520](https://www.circuit.rocks)

## Thanks and credits for this BSP are going to Adafruit.    

**_This BSP is based on the [Adafruit_nRF52_Arduino](https://github.com/adafruit/Adafruit_nRF52_Arduino) and adapted for the [ISP4520 from Insight SIP](https://www.insightsip.com/products/combo-smart-modules/isp4520)._**    

_The main reason why the orignal BSP from Adafruit cannot be used is because of the integrated [Semtech SX1262/1 LoRa transceiver](https://www.semtech.com/products/wireless-rf/lora-transceivers/sx1262) chip that occupies some GPIOs that are not available. It was as well necessary to integrated a matching library for the Semtech SX1262 LoRa chip._

## About the Circuitrocks Alora ISP4520    
The Circuitrocks Alora ISP4520 board is based on the [ISP4520 from Insight SIP](https://www.insightsip.com/products/combo-smart-modules/isp4520), an SOC that integrates a Nordic nRF52832 and a [Semtech SX1262/1 LoRa transceiver](https://www.semtech.com/products/wireless-rf/lora-transceivers/sx1262).

## BSP Installation

There are two methods that you can use to install this BSP. We highly recommend the first option unless you wish to participate in active development of this codebase via Github.

### Recommended: Circuitrocks Alora BSP via the Arduino Board Manager

 1. [Download and install the Arduino IDE](https://www.arduino.cc/en/Main/Software) (At least v1.6.12)
 2. Start the Arduino IDE
 3. Go into Preferences
 4. Add `https://beegee-tokyo.github.io/package_circuitrocks_index.json` as an 'Additional Board Manager URL'
 5. Restart the Arduino IDE
 6. Open the Boards Manager from the Tools -> Board menu and install 'Circuitrocks Alora by Circuitrocks'
 7. Once the BSP is installed, select 'Circuitrocks Alora ISP4520 Feather' from the Tools -> Board menu, which will update your system config to use the right compiler and settings for the ISP4520.

### Optional (Core Development): Circuitrocks Alora BSP via git

 1. Install BSP via Board Manager as above to install compiler & tools.
 2. Delete the core folder `nrf52` installed by Board Manager in Adruino15, depending on your OS. It could be
  * macOS  : `~/Library/Arduino15/packages/circuitrocks/hardware/nrf52`
  * Linux  : `~/.arduino15/packages/circuitrocks/hardware/nrf52`
  * Windows: `%APPDATA%\Local\Arduino15\packages\circuitrocks\hardware\nrf52`
 3. `cd <SKETCHBOOK>`, where `<SKETCHBOOK>` is your Arduino Sketch folder:
  * macOS  : `~/Documents/Arduino`
  * Linux  : `~/Arduino`
  * Windows: `~/Documents/Arduino`
 4. Create a folder named `hardware/circuitrocks`, if it does not exist, and change directories to it
 5. Clone this repo: `git clone https://github.com/beegee-tokyo/Circuitrocks_ISP4520_Arduino.git`
 6. Restart the Arduino IDE
 7. Once the BSP is installed, select 'Circuitrocks Alora ISP4520 Feather' from the Tools -> Board menu, which will update your system config to use the right compiler and settings for the ISP4520.

### Adafruit's nrfutil tools

[adafruit-nrfutil](https://github.com/adafruit/Adafruit_nRF52_nrfutil) (derived from Nordic pc-nrfutil) is needed to upload sketch via serial port.

- For Windows and macOS, pre-built executable binaries are included in the BSP at `tools/adafruit-nrfutil/`. It should work out of the box.
- Linux user need to run follow command to install it from PyPi

    ```
    $ pip3 install adafruit-nrfutil --user
	```

### Drivers

- [SiLabs CP2104 driver](http://www.silabs.com/products/mcu/pages/usbtouartbridgevcpdrivers.aspx) is required for USB to Serial when using with Feather nRF52832

## Bootloader Support

### Upgrade existing Bootloader

Bluefruit's Bootloader is self-upgradable, you could upgrade to the latest Bootloader + Softdevice using the serial port within Arduino IDE.

- Select `Tools > Board > Circuitrocks Alora ISP4520 Feather`
- Select `Tools > Programmer > Bootloader DFU for Circuitrocks Alora ISP4520`
- Select `Tools > Burn Bootloader`
- **WAIT** until the process complete ~30 seconds

**Note: close the Serial Monitor before you click "Burn Bootloader". Afterwards, you shouldn't close the Arduino IDE, unplug the Feather, launch Serial Monitor etc ... to abort the process. There is a high chance it will brick your device! Do this with care and caution.**

### Burning new Bootloader

To burn the bootloader from within the Arduino IDE, you will need the following tools installed
on your system and available in the system path:

- Segger [JLink Software and Documentation Pack](https://www.segger.com/downloads/jlink)
- Nordic [nRF5x Command Line Tools](http://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.tools%2Fdita%2Ftools%2Fnrf5x_command_line_tools%2Fnrf5x_installation.html)

Check to make sure you can run `nrfjprog` from your terminal/command prompt

**macOS Note** At present, you will need to create a symlink in `/usr/local/bin` to the
`nrfjprog` tool wherever you have added it. You can run the following command, for example:

```
$ ln -s $HOME/prog/nordic/nrfjprog/nrfjprog /usr/local/bin/nrfjprog
```

Once the tools above have been installed and added to your system path, from the Arduino IDE:

- Select `Tools > Board > Circuitrocks Alora ISP4520`
- Select `Tools > Programmer > J-Link for Circuitrocks Alora ISP4520`
- Select `Tools > Burn Bootloader` with the board and J-Link connected

If you wish to modify bootloader to your own need, check out its repo here [Circuitrocks_ISP4520_Bootloader](https://github.com/beegee-tokyo/Circuitrocks_ISP4520_Bootloader)

#### Manually Burning the Bootloader via nrfjprog

The bootloader hex file can be found at `bin/bootloader` run the command as follows:

```
$ nrfjprog -e -f nrf52
$ nrfjprog --program feather_nrf52832_bootloader.hex -f nrf52
$ nrfjprog --reset -f nrf52
```

## Credits

This core is based on [Adafruit_nRF52_Arduino](https://github.com/adafruit/Adafruit_nRF52_Arduino) by Adafruit,which in turn is based on the [Arduino-nRF5](https://github.com/sandeepmistry/arduino-nRF5) by Sandeep Mistry,
which in turn is based on the [Arduino SAMD Core](https://github.com/arduino/ArduinoCore-samd).

The following libraries are used:

- adafruit-nrfutil is based on Nordic Semiconductor ASA's [pc-nrfutil](https://github.com/NordicSemiconductor/pc-nrfutil)
- [freeRTOS](https://www.freertos.org/) as operating system
- [tinyusb](https://github.com/hathach/tinyusb) as usb stack
- [nrfx](https://github.com/NordicSemiconductor/nrfx) for peripherals driver
- [littlefs](https://github.com/ARMmbed/littlefs) for internal file system
