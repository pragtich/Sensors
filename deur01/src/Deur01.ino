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

// General settings
#define SKETCH_NAME "Deur01"
#define SKETCH_VERSION "1.2"

//#define MY_DEBUG
//#define MY_DEBUG_VERBOSE_RFM69
//#define FEATURE_DEBUG ON
				  
#ifndef FEATURE_DEBUG
  #define FEATURE_DEBUG OFF
#endif
//#define MY_NODE_ID 99

// NRF24 radio settings
//#define MY_RADIO_NRF24
//#define MY_RF24_ENABLE_ENCRYPTION
//#define MY_RF24_CHANNEL 125
//#define MY_RF24_PA_LEVEL RF24_PA_HIGH
//#define MY_DEBUG_VERBOSE_RF24
//#define MY_RF24_DATARATE RF24_250KBPS

// RFM69 radio settings
#define MY_RADIO_RFM69
#define MY_RFM69_FREQUENCY RFM69_868MHZ
#define MY_IS_RFM69HW
#define MY_RFM69_NEW_DRIVER
//#define MY_RFM69_ATC_TARGET_RSSI_DBM (-70)  // target RSSI -70dBm
//#define MY_RFM69_MAX_POWER_LEVEL_DBM (10)   // max. TX power 10dBm = 10mW

//#define MY_RFM69_ENABLE_ENCRYPTION
//#define MY_RFM69_NETWORKID 100
//#define MY_RF69_IRQ_PIN D1
//#define MY_RF69_IRQ_NUM MY_RF69_IRQ_PIN
//#define MY_RF69_SPI_CS D2
//#define MY_RFM69_ATC_MODE_DISABLED

// RFM95 radio settings
//#define MY_RADIO_RFM95
//#define MY_RFM95_FREQUENCY (RFM95_868MHZ)
//#define MY_DEBUG_VERBOSE_RFM95
//#define MY_RFM95_MAX_POWER_LEVEL_DBM (20)
//#define MY_RFM95_IRQ_PIN D1
//#define MY_RFM95_IRQ_NUM MY_RFM95_IRQ_PIN
//#define MY_RFM95_CS_PIN D8

// RS485 serial transport settings
//#define MY_RS485
//#define MY_RS485_BAUD_RATE 9600
//#define MY_RS485_DE_PIN 2
//#define MY_RS485_MAX_MESSAGE_LENGTH 40
//#define MY_RS485_HWSERIAL Serial1

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
//#define MY_SMART_SLEEP_WAIT_DURATION_MS 500
#define MY_SPLASH_SCREEN_DISABLED
//#define MY_DISABLE_RAM_ROUTING_TABLE_FEATURE
//#define MY_SIGNAL_REPORT_ENABLED

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

#define USE_BATTERY
#define USE_SIGNAL
//#define USE_ANALOG_INPUT
//#define USE_THERMISTOR
//#define USE_ML8511
//#define USE_ACS712
//#define USE_DIGITAL_INPUT
//#define USE_DIGITAL_OUTPUT
//#define USE_DHT
//#define USE_SHT21
#define USE_INTERRUPT
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
#define FEATURE_POWER_MANAGER OFF
#define FEATURE_INTERRUPTS ON
#define FEATURE_CONDITIONAL_REPORT OFF
#define FEATURE_EEPROM OFF
#define FEATURE_SLEEP ON
#define FEATURE_RECEIVE ON
#define FEATURE_TIME OFF
#define FEATURE_RTC OFF
#define FEATURE_SD OFF
#define FEATURE_HOOKING ON

/***********************************
 * Load NodeManager Library
 */

#include "NodeManagerLibrary.h"
NodeManager node;

/***********************************
 * Add your sensors below
 */

// built-in sensors
SensorBattery battery(node);
//SensorConfiguration configuration(node);
SensorSignal signal(node);
SensorSignal signaltx(node, 300);
//PowerManager power(5,6);

// Attached sensors
//SensorAnalogInput analog(node,A0);
//SensorLDR ldr(node,A0);
//SensorRain rain(node,A0);
//SensorSoilMoisture soil(node,A0);
//SensorThermistor thermistor(node,A0);
//SensorML8511 ml8511(node,A0);
//SensorACS712 acs712(node,A0);
//SensorDigitalInput digitalIn(node,6);
//SensorDigitalOutput digitalOut(node,6);
//SensorRelay relay(node,6);
//SensorLatchingRelay latching(node,6);
//SensorDHT11 dht11(node,6);
//SensorDHT22 dht22(node,6);
//SensorSHT21 sht21(node);
//SensorHTU21D htu21(node);
//SensorInterrupt interrupt(node,3);
SensorDoor door(node,3);
//SensorMotion motion(node,3);
//SensorDs18b20 ds18b20(node,6);
//SensorBH1750 bh1750(node);
//SensorMLX90614 mlx90614(node);
//SensorBME280 bme280(node);
//SensorBMP085 bmp085(node);
//SensorBMP280 bmp280(node);
//SensorSonoff sonoff(node);
//SensorHCSR04 hcsr04(node,6);
//SensorMCP9808 mcp9808(node);
//SensorMQ mq(node,A0);
//SensorMHZ19 mhz19(node,6,7);
//SensorAM2320 am2320(node);
//SensorTSL2561 tsl2561(node);
//SensorPT100 pt100(node,6);
//SensorDimmer dimmer(node,3);
//SensorRainGauge rainGauge(node,3);
//SensorPowerMeter powerMeter(node,3);
//SensorWaterMeter waterMeter(node,3);
//SensorPlantowerPMS pms(node,6,7);
//SensorVL53L0X vl53l0x(node,3);
//DisplaySSD1306 ssd1306(node);
//SensorSHT31 sht31(node);
//SensorSI7021 si7021(node);
//SensorChirp chirp(node);
//DisplayHD44780 hd44780(node);
//SensorTTP ttp(node);
//SensorServo servo(node,6);
//SensorAPDS9960 apds9960(node,3);
//SensorNeopixel neopixel(node,6);

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
    
    int value = digitalRead(sensor->getPin());
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
    ((ChildInt*)child)->setValueInt(value);
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
  // report measures of every attached sensors every 10 seconds
  node.setReportIntervalSeconds(DOOR_SECONDS);
  // report measures of every attached sensors every 10 minutes
  //node.setReportIntervalMinutes(10);
  // set the node to sleep in 5 minutes cycles
  node.setSleepSeconds(DOOR_SECONDS);
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
  node.setSmartSleep(false);
  // Enable ACK (to get ATC?)
  //node.setAck(true);
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
  node.before();
}

// presentation
void presentation() {
  // call NodeManager presentation routine
  node.presentation();
}

// setup
void setup() {
  // call NodeManager setup routine
  node.setup();
}

// loop
void loop() {
  // call NodeManager loop routine
  node.loop();
}

#if FEATURE_RECEIVE == ON
// receive
void receive(const MyMessage &message) {
  // call NodeManager receive routine
  node.receive(message);
}
#endif

#if FEATURE_TIME == ON
// receiveTime
void receiveTime(unsigned long ts) {
  // call NodeManager receiveTime routine
  node.receiveTime(ts);
}
#endif
