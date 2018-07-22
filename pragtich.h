/*

pragtich.h

Defines MySensors network for Pragtich

This file should contain the general network definitions, general to all devices in the network.

*/

// RFM69 radio settings
#define MY_RADIO_RFM69
#define MY_RFM69_FREQUENCY RFM69_868MHZ
#define MY_IS_RFM69HW
//#define MY_RFM69_NEW_DRIVER
#define MY_RFM69_ATC_TARGET_RSSI_DBM (-70)  // target RSSI -70dBm
#define MY_RFM69_MAX_POWER_LEVEL_DBM (20)   // max. TX power 10dBm = 10mW


// Other
#define MY_SPLASH_SCREEN_DISABLED


//#define MY_RFM69_ENABLE_ENCRYPTION
//#define MY_RFM69_NETWORKID 100
//#define MY_RF69_IRQ_PIN D1
//#define MY_RF69_IRQ_NUM MY_RF69_IRQ_PIN
//#define MY_RF69_SPI_CS D2
//#define MY_RFM69_ATC_MODE_DISABLED
