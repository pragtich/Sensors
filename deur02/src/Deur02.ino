/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2016 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
1 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 *******************************


/**********************************
 * MySensors node configuration
 */

#include "../../pragtich.h"

// General settings
#define SKETCH_NAME "Deur02"
#define SKETCH_VERSION "1.07"

//#define MY_DEBUG
//#define MY_DEBUG_VERBOSE_OTA_UPDATE
//#define MY_DEBUG_VERBOSE_RFM69
//#define NODEMANAGER_DEBUG ON
				  
//#define MY_NODE_ID 99

#define USE_I2C_EEPROM
#define MY_OTA_FIRMWARE_FEATURE
#define MY_OTA_USE_I2C_EEPROM 
// Retry options defined in pragtich.h

// Advanced settings
#define MY_BAUD_RATE 9600
//#define MY_SMART_SLEEP_WAIT_DURATION_MS 2500
//#define MY_DISABLE_RAM_ROUTING_TABLE_FEATURE
//#define MY_SIGNAL_REPORT_ENABLED

// Enable/disable NodeManager's features
#define NODEMANAGER_DEBUG         OFF
#define NODEMANAGER_INTERRUPTS    ON
#define NODEMANAGER_SLEEP         ON
#define NODEMANAGER_RECEIVE       ON
#define NODEMANAGER_DEBUG_VERBOSE OFF
#define NODEMANAGER_POWER_MANAGER OFF
#define NODEMANAGER_CONDITIONAL_REPORT OFF
#define NODEMANAGER_EEPROM        OFF
#define NODEMANAGER_TIME          OFF
#define NODEMANAGER_RTC           OFF
#define NODEMANAGER_SD            OFF
#define NODEMANAGER_HOOKING       ON
#define NODEMANAGER_OTA_CONFIGURATION OFF
#define NODEMANAGER_SERIAL_INPUT  OFF

/***********************************
 * Load NodeManager Library
 */

#include  <MySensors_NodeManager.h>

/***********************************
 * Add your sensors below
 */

#include <sensors/SensorBattery.h>
SensorBattery battery;

//SensorConfiguration configuration(node);

//#include <sensors/SensorSignal.h>
//SensorSignal signal;
//SensorSignal signaltx(300);
#include <sensors/SensorDoor.h>
SensorDoor door(3);

/***********************************
 * Main Sketch
 */
#define DOOR_SECONDS (300)
bool DoorWokeMeUp = false;

void DoorLoop(Sensor *sensor) {
  // If I was woken up by an interrupt, avoid sampling twice
  if (DoorWokeMeUp){
    DoorWokeMeUp = false;
    return;
  }
  else {
    DoorWokeMeUp = false;
    // read the value
    
    int value = digitalRead(sensor->getInterruptPin());

    value = !value;

    Child* child = sensor->children.get(1);
#if NODEMANAGER_DEBUG == ON
    Serial.println(F("DoorLoop"));
    Serial.print(sensor->getName());
    Serial.print(F(" I="));
    Serial.print(child->getChildId());
    Serial.print(F(" P="));
    Serial.print(sensor->getPin());
    Serial.print(F(" V="));
    Serial.println(value);
#endif
    // store the value
    (child)->setValue(value);
  }
}


void DoorSetup(Sensor* sensor){
  sensor->setReportIntervalSeconds(DOOR_SECONDS);
}

void DoorInterrupt(Sensor* sensor){
  // Let the DoorLoop know, that it does not need to run
  DoorWokeMeUp = true;
}

// before
void before() {
  // setup the serial port baud rate
  Serial.begin(MY_BAUD_RATE);
  
  /*
  * Configure your sensors below
  */
  // Report measures of every attached sensors every 10 seconds
  nodeManager.setReportIntervalSeconds(DOOR_SECONDS);
  // report measures of every attached sensors every 10 minutes
  //nodeManager.setReportIntervalMinutes(10);
  // set the node to sleep in 5 minutes cycles
  nodeManager.setSleepSeconds(DOOR_SECONDS);
  // report battery level every 120 minutes
  //  battery.setReportIntervalMinutes(120);
  // set an offset to -1 to a thermistor sensor
  //thermistor.setOffset(-1);
  // change the id of a the first child of a sht21 sensor
  //sht21.children.get(1)->child_id = 5;
  // report only when the analog value is above 40%
  //analog.children.get(1)->min_threshold = 40;
  // power all the nodes through dedicated pins
  //nodeManager.setPowerManager(power);
  //

  // Disable smartSleep (messages that I am not using)
  //nodeManager.setSmartSleep(false);
  // Disable soft ack (is useless anyway, and causes issue)
  // This is the default, do this to be sure
  //nodeManager.setAck(false);
  // Pause between messages
  //  nodeManager.setSleepBetweenSend(500);
  // Invert value (zero is unlocked). This should reduce power consumption through the pull-up
  door.setInvertValueToReport(false);
  // Setup regular messaging from Door sensor even if status constants

  door.setSetupHook(DoorSetup);
  door.setPreLoopHook(DoorLoop);
  door.setInterruptHook(DoorInterrupt);
 
  /*  signal.setReportIntervalMinutes(60);
  signaltx.setReportIntervalMinutes(60);
  signaltx.setSignalCommand(SR_TX_POWER_LEVEL);
  signaltx.getChild(0)->setDescription("TX level");
  */
  /*
  * Configure your sensors above
  */
  nodeManager.before();
}

// presentation
void presentation() {
  // call NodeManager presentation routine
  nodeManager.presentation();
}

// setup
void setup() {
  // call NodeManager setup routine
  nodeManager.setup();
}

// loop
void loop() {
#ifdef MY_DEBUG_VERBOSE_OTA_UPDATE
  OTA_DEBUG(PSTR("~"));
#endif

  // call NodeManager loop routine
  nodeManager.loop();
}

#if NODEMANAGER_RECEIVE == ON
// receive
void receive(const MyMessage &message) {
  // call NodeManager receive routine
  nodeManager.receive(message);
}
#endif

#if NODEMANAGER_TIME == ON
// receiveTime
void receiveTime(unsigned long ts) {
  // call NodeManager receiveTime routine
  nodeManager.receiveTime(ts);
}
#endif
