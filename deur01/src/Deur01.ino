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
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 *******************************


/**********************************
 * MySensors node configuration
 */

#include "../../pragtich.h"

// General settings
#define SKETCH_NAME "Deur01"
#define SKETCH_VERSION "1.45"

#define MY_DEBUG
//#define MY_DEBUG_VERBOSE_RFM69
//#define MY_DEBUG_VERBOSE_RFM69_REGISTERS

#define USE_I2C_EEPROM
#define MY_OTA_FIRMWARE_FEATURE
#define MY_OTA_USE_I2C_EEPROM 

//#define MY_NODE_ID 99

// Message signing settings
//#define MY_SIGNING_SOFT
//#define MY_SIGNING_SOFT_RANDOMSEED_PIN 7
//#define MY_SIGNING_REQUEST_SIGNATURES
//#define MY_SIGNING_ATSHA204
//#define MY_SIGNING_ATSHA204_PIN 4
//#define MY_SIGNING_REQUEST_SIGNATURES

// OTA Firmware update settings
//#define MY_OTA_FIRMWARE_FEATURE
//#define OTA_WAIT_PERIOD 300
//#define FIRMWARE_MAX_REQUESTS 2
//#define MY_OTA_RETRY 2

// Advanced settings
#define MY_BAUD_RATE 9600
#define MY_SPLASH_SCREEN_DISABLED

#define MY_SMART_SLEEP_WAIT_DURATION_MS 2000
//#define MY_DISABLE_RAM_ROUTING_TABLE_FEATURE
#define MY_SIGNAL_REPORT_ENABLED

// Optimizations when running on 2032 Coin Cell. Also set node.setSleepBetweenSend(500) and run the board at 1Mhz
//#define MY_TRANSPORT_UPLINK_CHECK_DISABLED
//#define MY_TRANSPORT_WAIT_READY_MS  5000
//#define MY_SLEEP_TRANSPORT_RECONNECT_TIMEOUT_MS 2000
//#define MY_PARENT_NODE_ID 0
//#define MY_PARENT_NODE_IS_STATIC

/**********************************
 * MySensors gateway configuration
 */
 
// Common gateway settings
//#define MY_REPEATER_FEATURE

// Serial gateway settings
//#define MY_GATEWAY_SERIAL

// Ethernet gateway settings
//#define MY_GATEWAY_W5100

// ESP8266 gateway settings
//#define MY_GATEWAY_ESP8266
//#define MY_ESP8266_SSID ""
//#define MY_ESP8266_PASSWORD ""

// Gateway networking settings
//#define MY_IP_ADDRESS 192,168,178,87
//#define MY_IP_GATEWAY_ADDRESS 192,168,178,1
//#define MY_IP_SUBNET_ADDRESS 255,255,255,0
//#define MY_PORT 5003
//#define MY_GATEWAY_MAX_CLIENTS 2
//#define MY_USE_UDP

// Gateway MQTT settings
//#define MY_GATEWAY_MQTT_CLIENT
//#define MY_CONTROLLER_IP_ADDRESS 192, 168, 178, 68
//#define MY_PORT 1883
//#define MY_MQTT_USER "username"
//#define MY_MQTT_PASSWORD "password"
//#define MY_MQTT_CLIENT_ID "mysensors-1"
//#define MY_MQTT_PUBLISH_TOPIC_PREFIX "mygateway1-out"
//#define MY_MQTT_SUBSCRIBE_TOPIC_PREFIX "mygateway1-in"

// Gateway inclusion mode
//#define MY_INCLUSION_MODE_FEATURE
//#define MY_INCLUSION_BUTTON_FEATURE
//#define MY_INCLUSION_MODE_DURATION 60
//#define MY_DEFAULT_LED_BLINK_PERIOD 300

// Gateway Leds settings
//#define MY_DEFAULT_ERR_LED_PIN 4
//#define MY_DEFAULT_RX_LED_PIN  5
//#define MY_DEFAULT_TX_LED_PIN  6

/***********************************
 * NodeManager modules for supported sensors
 */

//#define USE_BATTERY
//#define USE_SIGNAL
//#define USE_ANALOG_INPUT
//#define USE_THERMISTOR
//#define USE_ML8511
//#define USE_ACS712
//#define USE_DIGITAL_INPUT
//#define USE_DIGITAL_OUTPUT
//#define USE_DHT
//#define USE_SHT21
//#define USE_INTERRUPT
//#define USE_DS18B20
//#define USE_BH1750
//#define USE_MLX90614
//#define USE_BME280
//#define USE_BMP085
//#define USE_BMP280
//#define USE_SONOFF
//#define USE_HCSR04
//#define USE_MCP9808
//#define USE_MQ
//#define USE_MHZ19
//#define USE_AM2320
//#define USE_TSL2561
//#define USE_PT100
//#define USE_DIMMER
//#define USE_PULSE_METER
//#define USE_PMS
//#define USE_VL53L0X
//#define USE_SSD1306
//#define USE_SHT31
//#define USE_SI7021
//#define USE_CHIRP
//#define USE_HD44780
//#define USE_TTP
//#define USE_SERVO
//#define USE_APDS9960
//#define USE_NEOPIXEL

/***********************************
 * NodeManager built-in features
 */

// Enable/disable NodeManager's features
/* #define FEATURE_POWER_MANAGER OFF */
/* #define FEATURE_INTERRUPTS ON */
/* #define FEATURE_CONDITIONAL_REPORT OFF */
/* #define FEATURE_EEPROM OFF */
/* #define FEATURE_SLEEP ON */
/* #define FEATURE_RECEIVE ON */
/* #define FEATURE_TIME OFF */
/* #define FEATURE_RTC OFF */
/* #define FEATURE_SD OFF */
/* #define FEATURE_HOOKING ON */

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

#include <MySensors_NodeManager.h>

/***********************************
 * Add your sensors below
 */

#include <sensors/SensorBattery.h>
SensorBattery battery;

//SensorConfiguration configuration(node);

#include <sensors/SensorSignal.h>
SensorSignal signal;
SensorSignal signaltx(300);
#include <sensors/SensorDoor.h>
SensorDoor door(3);

/***********************************
 * Main Sketch
 */

#define DOOR_SECONDS (20)

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
    // Does not work because the variable is protected
    // if (sensor->_invert_value_to_report) value = !value;
    value = !value;

    Child* child = sensor->children.get(1);
#if FEATURE_DEBUG == ON
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
  //node.setReportIntervalMinutes(10);
  // set the node to sleep in 5 minutes cycles
  nodeManager.setSleepSeconds(DOOR_SECONDS);
  // report battery level every 10 minutes
  //battery.setReportIntervalMinutes(10);
  // set an offset to -1 to a thermistor sensor
  //thermistor.setOffset(-1);
  // change the id of a the first child of a sht21 sensor
  //sht21.children.get(1)->child_id = 5;
  // report only when the analog value is above 40%
  //analog.children.get(1)->min_threshold = 40;
  // power all the nodes through dedicated pins
  //node.setPowerManager(power);
  //

  // Disable smartSleep (messages that I am not using)
  //node.setSmartSleep(false);
  // Disable soft ack (is useless anyway, and causes issue)
  // This is the default, do this to be sure
  //nodeManager.setAck(false);
  // Pause between messages
  //  node.setSleepBetweenSend(500);
  // Invert value (zero is unlocked). This should reduce power consumption through the pull-up
  door.setInvertValueToReport(true);
  // Setup regular messaging from Door sensor even if status constants
  door.setSetupHook(DoorSetup);
  door.setPreLoopHook(DoorLoop);
  door.setInterruptHook(DoorInterrupt);

  signal.setReportIntervalMinutes(60);
  signaltx.setReportIntervalMinutes(60);
  signaltx.setSignalCommand(SR_TX_POWER_LEVEL);
  signaltx.getChild(0)->setDescription("TX level");
  
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
