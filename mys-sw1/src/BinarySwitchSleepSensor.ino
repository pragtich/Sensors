e/**
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
 *
 * Interrupt driven binary switch example with dual interrupts
 * Author: Patrick 'Anticimex' Fallberg
 * Connect one button or door/window reed switch between
 * digitial I/O pin 3 (BUTTON_PIN below) and GND and the other
 * one in similar fashion on digital I/O pin 2.
 * This example is designed to fit Arduino Nano/Pro Mini
 *
 */

//#define MY_NODE_ID (17)
//// Enable debug prints to serial monitor
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
//#define MY_DEBUG_VERBOSE_RFM69_REGISTERS
#define RFM69_REGISTER_DETAIL
#define MY_RFM69_MAX_POWER_LEVEL_DBM (1u)

//#define MY_RADIO_RFM95

#include <MySensors.h>

#define SKETCH_NAME "Test Button Sensor"
#define SKETCH_MAJOR_VER "1"
#define SKETCH_MINOR_VER "2"

#define PRIMARY_CHILD_ID 4
#define SECONDARY_CHILD_ID 5

#define PRIMARY_BUTTON_PIN 3   // Arduino Digital I/O pin for button/reed switch
//#define SECONDARY_BUTTON_PIN 2 // Arduino Digital I/O pin for button/reed switch

#if (PRIMARY_BUTTON_PIN < 2 || PRIMARY_BUTTON_PIN > 3)
#error PRIMARY_BUTTON_PIN must be either 2 or 3 for interrupts to work
#endif
//#if (SECONDARY_BUTTON_PIN < 2 || SECONDARY_BUTTON_PIN > 3)
//#error SECONDARY_BUTTON_PIN must be either 2 or 3 for interrupts to work
//#endif
//#if (PRIMARY_BUTTON_PIN == SECONDARY_BUTTON_PIN)
//#error PRIMARY_BUTTON_PIN and BUTTON_PIN2 cannot be the same
//#endif
#if (PRIMARY_CHILD_ID == SECONDARY_CHILD_ID)
#error PRIMARY_CHILD_ID and SECONDARY_CHILD_ID cannot be the same
#endif


// Change to V_LIGHT if you use S_LIGHT in presentation below
MyMessage msg(PRIMARY_CHILD_ID, V_STATUS);
//MyMessage msg2(SECONDARY_CHILD_ID, V_TRIPPED);

void setup()
{
  Serial.println("Helloo");
	// Setup the buttons
	pinMode(PRIMARY_BUTTON_PIN, INPUT_PULLUP);
	//	pinMode(SECONDARY_BUTTON_PIN, INPUT_PULLUP);
}

void presentation()
{
	// Send the sketch version information to the gateway and Controller
	sendSketchInfo(SKETCH_NAME, SKETCH_MAJOR_VER "." SKETCH_MINOR_VER);

	// Register binary input sensor to sensor_node (they will be created as child devices)
	// You can use S_DOOR, S_MOTION or S_LIGHT here depending on your usage.
	// If S_LIGHT is used, remember to update variable type you send in. See "msg" above.
	present(PRIMARY_CHILD_ID, S_BINARY);
	//present(SECONDARY_CHILD_ID, S_DOOR);
}

// Loop will iterate on changes on the BUTTON_PINs
bool doinit  = true;

void loop()
{
	uint8_t value;
	static uint8_t sentValue=2;
	
	//	static uint8_t sentValue2=2;
  Serial.print("loop");
  if (doinit) {
    Serial.println("Sending first 1");
    send(msg.set(1));
    Serial.println("Sending first 0");
    send(msg.set(0));
    Serial.println("Requesting initial value from controller");
    request(PRIMARY_CHILD_ID, V_STATUS);
    wait(2000, C_SET, V_STATUS);
  }
	// Short delay to allow buttons to properly settle
	sleep(5);

	value = digitalRead(PRIMARY_BUTTON_PIN);

	if (value != sentValue) {
		// Value has changed from last transmission, send the updated value
	  send(msg.set(value==HIGH?1:0));
		sentValue = value;
	}

	//value = digitalRead(SECONDARY_BUTTON_PIN);

	//if (value != sentValue2) {
		// Value has changed from last transmission, send the updated value
	//		send(msg2.set(value==HIGH));
	//		sentValue2 = value;
	//}

	// Sleep until something happens with the sensor
	sleep(PRIMARY_BUTTON_PIN-2, CHANGE, PRIMARY_BUTTON_PIN-2, CHANGE, 0);
}

void receive(const MyMessage &message) {
  if (message.isAck()) {
     Serial.println("This is an ack from gateway");
  }

  if (message.type == V_STATUS) {
    if (doinit) {
      Serial.println("Receiving initial value from controller");
      doinit = false; 
    }
    // Change relay state
    bool state = (bool)message.getInt();
    //    digitalWrite(RELAY_PIN, state?RELAY_ON:RELAY_OFF);
    send(msg.set(state?0:1));
  }
}
