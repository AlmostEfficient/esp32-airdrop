## IRL MONEY PRINTER
Turn an ESP32 wifi board into a real life SOL faucet.

## Setup
### Install relevant drivers
Your vendor will likely give you a guide for this based on which board you buy. I used an ESP32-WROOM-32 board from Espressif, and they have a guide [here](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html#installation-step-by-step). You may need to restart your computer after installing the drivers.

Plug in your board and it will light up if it has an LED and is working properly.

#### Windows 
Open Device Manager and look for a device called "USB Serial Device (COM#)" under Ports (COM & LPT). The COM# is the port number you will need to use in the next step.

Mine shows as:
```
Sificon Labs CP210x USB UART Bridge (COM3)
```

#### MacOS/Linux
Open a terminal and run the following command:
```
ls /dev/tty.*
```

You should see a device called something like `/dev/tty.SLAB_USBtoUART`. The `/dev/tty.` part is the port name you will need to use in the next step.

### Install Platform IO
Open up this folder in VSCode and it should prompt you to install Platform IO. If it doesn't, just search for it in the extensions tab and install it.

Restart VSCode and the extension icon should appear in the sidebar. 

## Notes
### HTTP restrictions 
A bunch of stuff doesn't work because clients are on HTTP. For instance: the [clipboard](https://developer.mozilla.org/en-US/docs/Web/API/Navigator/clipboard) API is only available via HTTPS, so you can't copy codes/addresses to the users' clipboard.