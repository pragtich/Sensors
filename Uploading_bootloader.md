
A basic battery powered Mysensors node

Based on: https://www.mysensors.org/build/battery and a 3.3V 8MHz Arduino (clone) Pro Mini from the usual sources.
Handy pinout guide: https://blog.adafruit.com/wp-content/uploads/2016/07/promini_final.png

Perform the hardware mods from above link:
- Disable LED
- Remove voltage regulator

Make an Arduino ISP programmer

Flash the ISP firmware

- Open ArduinoISP sketch from the repository
- Connect the ISP using a USB-serial connection
- Select board $Arduino Pro or Pro Mini$
- Flash the sketch. (It should present you with a heartbeat pulse on the LED.) No heartbeat: this broke upload.

Install boot loader:

- Install Arduino IDE
- Unpack rar in $Various-bootloader-files-based-on-Optiboot-62$
- Move folder $atmega328p$ to $Arduino.app/Contents/Java/hardware$
- Start $Arduino.app$
- Select Tools->Board->$atmega328p based - 32 pin TQFP$
- Select $8MHz - crystal - 38K4 - D13$
- Select $Brown out detection - 1V8$
- Select correct USB port
- Select $Programmer: "Arduino as ISP"
- Burn Bootloader

Test:
- Connect the board to the USB serial adapter (disconnect ISP)
- Upload example Blink
- Upload Blink with modified timings
- I also like to try the ASCII table example
- Quit the Arduino IDE

Upload the real script:
- Switch to the project folder
- Edit baud rates in the $platformio.ini$. I use $38400$ for upload and $9600$ for monitor.
