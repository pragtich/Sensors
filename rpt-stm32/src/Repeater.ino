/**
* The MySensors Arduino library handles the wireless radio link and protocol
* between your home built sensors/actuators and HA controller of choice.
* The sensors forms a self healing radio network with optional repeaters. Each
* repeater and gateway builds a routing tables in EEPROM which keeps track of the
* network topology allowing messages to be routed to nodes.
*
* Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
* Copyright (C) 2013-2015 Sensnology AB
* Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
*
* Documentation: http://www.mysensors.org
* Support Forum: http://forum.mysensors.org
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* version 2 as published by the Free Software Foundation.
*
*******************************
*
* DESCRIPTION
* The ArduinoGateway prints data received from sensors on the serial link.
* The gateway accepts input on seral which will be sent out on radio network.
*
* The GW code is designed for Arduino Nano 328p / 16MHz
*
* Wire connections (OPTIONAL):
* - Inclusion button should be connected between digital pin 3 and GND
* - RX/TX/ERR leds need to be connected between +5V (anode) and digital pin 6/5/4 with resistor 270-330R in a series
*
* LEDs (OPTIONAL):
* - To use the feature, uncomment any of the MY_DEFAULT_xx_LED_PINs
* - RX (green) - blink fast on radio message recieved. In inclusion mode will blink fast only on presentation recieved
* - TX (yellow) - blink fast on radio message transmitted. In inclusion mode will blink slowly
* - ERR (red) - fast blink on error during transmission error or recieve crc error
*
*/

// This is a repeater node
#define MY_REPEATER_FEATURE

// Repeater is not getting an automatic node ID from controller (TODO: why?)
#define MY_NODE_ID (1)


// Enable debug prints to serial monitor
#define MY_DEBUG
#define MY_DEBUG_VERBOSE

// Enable and select radio type attached
//#define MY_RADIO_NRF24
//#define MY_RADIO_NRF5_ESB
#define MY_RADIO_RFM69
#define MY_RFM69_FREQUENCY RFM69_868MHZ
#define MY_IS_RFM69HW
#define MY_RFM69_NEW_DRIVER
#define MY_DEBUG_VERBOSE_RFM69
#define MY_DEBUG_VERBOSE_RFM69_REGISTERS

// I do not want ATC
#define MY_RFM69_ATC_MODE_DISABLED
#define MY_RFM69_TX_POWER_DBM   (20)

#define MY_RFM69_IRQ_PIN (PA11)

// Define a lower baud rate for Arduino's running on 8 MHz (Arduino Pro Mini 3.3V & SenseBender)
#if F_CPU == 8000000L
#define MY_BAUD_RATE 38400
#endif

#include <MySensors.h>

void setup()
{
	// Setup locally attached sensors
}

void presentation()
{
	//Send the sensor node sketch version information to the gateway
	sendSketchInfo("Repeater Node", "1.0");
}

void loop()
{
	// Send locally attached sensor data here
}
