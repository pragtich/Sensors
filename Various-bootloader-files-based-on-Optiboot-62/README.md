In this project I have put all the boot loaders I compiled (some tested, some not tested). I compile my own Optiboot6.2 based boot loaders on a Windows 7 Pro virtual machine on my Mac. By putting them all here I hope more people will have use for the HEX files. Feedback on the files is appreciated, especially if they do NOT work.

Every boot loader is mentioned with the base frequency of the processor, the upload speed and the pin which will flash 3 times when the MCU is reset. Also boot loaders are provided without flashing LED.

The name of the HEX files should tell you which frequency and upload speed it is meant for.

These bootloaders do NOT have the necessary code for Over The Air (OTA) uploads. So you can only use them with the FTDI connectors and upload sketches via serial cable.

I know I should make a tutorial on how to load this onto processors, in the mean time here is an excellent one you can probably apply:

https://forum.mysensors.org/topic/3018/tutorial-how-to-burn-1mhz-8mhz-bootloader-using-arduino-ide-1-6-5-r5/1

Update 12/FEB/2017: I have added a compressed file of the directory I keep in my Hardware folder of the Arduino Sketch library folder. It contains all bootloaders I use. As far as I can test, they all work.


The directory structure of the compressed files is as follows:

```
[Arduino]
   [hardware]
      [atmega328p]
         [avr]
            [bootloaders]
               [myoptiboot]
                  ... all the HEX files ...
            [variants]
               [28PinBoard]
                  pins_arduino.h
               [32PinBoard]
                  pins_arduino.h
               [40PinBoard]
                  pins_arduino.h
               [44PinBoard]
                  pins_arduino.h
            boards.txt
            platform.txt

```