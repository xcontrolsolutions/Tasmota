/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is included
#warning **** user_config_override.h: Using Settings from this File ****

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/
//////////Stock Firmware Setting Overrides///////////
// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "JMFX-SensorLan"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "7188750140"     // [Password1] Wifi password

#undef STA_SSID2
#define STA_SSID2              "SensorNetwork"                // [Ssid2] Optional alternate AP Wifi SSID
#undef STA_PASS2
#define STA_PASS2              "1234567890"                // [Password2] Optional alternate AP Wifi password

// -- Ota -----------------------------------------
#undef OTA_URL
#define OTA_URL                "http://10.101.3.1:5000/tasmota-SPS30.bin"  // [OtaUrl]


//////////SPS30 Firmware Setting Overrides//////////
#ifdef FIRMWARE_SPS30
// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4616                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

#undef PROJECT
#define PROJECT                "AFS"         // PROJECT is used as the default topic delimiter

#undef MODULE
#define MODULE                 USER_MODULE      // [Module] Select default module from tasmota_template.h

#undef FALLBACK_MODULE
#define FALLBACK_MODULE        USER_MODULE
#define USER_TEMPLATE "{\"NAME\":\"ParticleSensor\",\"GPIO\":[0,0,0,0,608,640,0,0,33,34,32,1376,1,0],\"FLAG\":0,\"BASE\":18}"  // [Template] Set JSON template

//////SetOptions Settings Overrides
#undef SAVE_STATE
#define SAVE_STATE             false              // [SetOption0] Save changed power state to Flash (false = disable, true = enable)
#undef KEY_DISABLE_MULTIPRESS
#define KEY_DISABLE_MULTIPRESS true             // [SetOption1]  Disable button multipress
//setOption2 does not exist... thanks Obama
#undef MQTT_USE
#define MQTT_USE               true              // [SetOption3] Select default MQTT use (false = Off, true = On)
#undef MQTT_RESULT_COMMAND
#define MQTT_RESULT_COMMAND    false             // [SetOption4]  Switch between MQTT RESULT or COMMAND
//setOption 5-7 DNE
#undef TEMP_CONVERSION
#define TEMP_CONVERSION        true             // [SetOption8] Return temperature in (false = Celsius or true = Fahrenheit)
//setOption 9 DNE
#undef MQTT_LWT_MESSAGE
#define MQTT_LWT_MESSAGE       false             // [SetOption10] Switch between MQTT LWT OFFLINE or empty message
#undef KEY_SWAP_DOUBLE_PRESS
#define KEY_SWAP_DOUBLE_PRESS  false             // [SetOption11] Swap button single and double press functionality
#undef APP_FLASH_CYCLE
#define APP_FLASH_CYCLE        false             // [SetOption12] Switch between dynamic or fixed slot flash save location
#undef KEY_ONLY_SINGLE_PRESS
#define KEY_ONLY_SINGLE_PRESS  true             // [SetOption13] Enable only single press to speed up button press recognition
//setOption 14 DNE
#undef LIGHT_MODE
#define LIGHT_MODE             true              // [SetOption15] Switch between commands PWM or COLOR/DIMMER/CT/CHANNEL
#undef LIGHT_CLOCK_DIRECTION
#define LIGHT_CLOCK_DIRECTION  false             // [SetOption16] Switch WS2812 clock between clockwise or counter-clockwise
#undef LIGHT_COLOR_RADIX
#define LIGHT_COLOR_RADIX      false             // [SetOption17] Switch between decimal or hexadecimal color output (false = hexadecimal, true = decimal)
#undef LIGHT_PAIRS_CO2
#define LIGHT_PAIRS_CO2        false             // [SetOption18] Enable Pair light signal with CO2 sensor
#undef LIGHT_POWER_CONTROL
#define LIGHT_POWER_CONTROL    false             // [SetOption20] Enable power control in relation to Dimmer/Color/Ct changes
#undef ENERGY_VOLTAGE_ALWAYS
#define ENERGY_VOLTAGE_ALWAYS  false             // [SetOption21] Enable show voltage even if powered off
//setOption 22,23 DNE
#undef PRESSURE_CONVERSION
#define PRESSURE_CONVERSION    false             // [SetOption24] Return pressure in (false = hPa or true = mmHg)
//setOption25 DNE
#undef MQTT_POWER_FORMAT
#define MQTT_POWER_FORMAT      false             // [SetOption26] Switch between POWER or POWER1 for single power devices
//setOption27 DNE
#undef RF_DATA_RADIX
#define RF_DATA_RADIX          false             // [SetOption28] RF receive data format (false = hexadecimal, true = decimal)
#undef IR_DATA_RADIX
#define IR_DATA_RADIX          false             // [SetOption29] IR receive data format (false = hexadecimal, true = decimal)
#undef HASS_AS_LIGHT
#define HASS_AS_LIGHT          false             // [SetOption30] Enforce HAss autodiscovery as light
#undef APP_ENABLE_LEDLINK
#define APP_ENABLE_LEDLINK     false             // [SetOption31] Enable link led blinking
#undef KEY_HOLD_TIME
#define KEY_HOLD_TIME          40                // [SetOption32] Number of 0.1 seconds to hold Button or external Pushbutton before sending HOLD message
//setOption34 Exists but not in Firmware
//setOption35 DNE
#undef BOOT_LOOP_OFFSET
#define BOOT_LOOP_OFFSET       5                 // [SetOption36] Number of boot loops before starting restoring defaults (0 = disable, 1..200 = boot loops offset)
//setOption37 DNE
//setOption38-40 Exist but not in Firmware
#undef WIFI_ARP_INTERVAL
#define WIFI_ARP_INTERVAL      0                 // [SetOption41] Send gratuitous ARP interval
//setOption42,43 Exist but not in Firmware
//setOption44-50 DNE
//setOption51 Exists but not in Firmware
#undef MQTT_APPEND_TIMEZONE
#define MQTT_APPEND_TIMEZONE   false             // [SetOption52] Append timezone to JSON time
#undef GUI_SHOW_HOSTNAME
#define GUI_SHOW_HOSTNAME      true             // [SetOption53] Show hostname and IP address in GUI main menu
#undef TUYA_SETOPTION_20
#define TUYA_SETOPTION_20      false             // [SetOption54] Apply SetOption20 settings to Tuya device
#undef MDNS_ENABLED
#define MDNS_ENABLED           false             // [SetOption55] Use mDNS (false = Disable, true = Enable)
#undef WIFI_SCAN_AT_RESTART
#define WIFI_SCAN_AT_RESTART   false             // [SetOption56] Scan wifi network at restart for configured AP's
#undef WIFI_SCAN_REGULARLY
#define WIFI_SCAN_REGULARLY    true              // [SetOption57] Scan wifi network every 44 minutes for configured AP's
#undef IR_ADD_RAW_DATA
#define IR_ADD_RAW_DATA        false             // [SetOption58] Add IR Raw data to JSON message
#undef TELE_ON_POWER
#define TELE_ON_POWER          false             // [SetOption59] send tele/STATE together with stat/RESULT (false = Disable, true = Enable)
#undef APP_NORMAL_SLEEP
#define APP_NORMAL_SLEEP       false             // [SetOption60] Enable normal sleep instead of dynamic sleep
#define APP_NORMAL_SLEEP       false             // [SetOption60] Enable normal sleep instead of dynamic sleep
#undef APP_SLEEP
#define APP_SLEEP              250               // [Sleep] Sleep time to lower energy consumption (0 = Off, 1 - 250 mSec),
#undef PWM_MAX_SLEEP
#define PWM_MAX_SLEEP          250               // Sleep will be lowered to this value when light is on, to avoid flickering, and when buzzer is on for better on/off period accuracy
#undef MQTT_BUTTON_SWITCH_FORCE_LOCAL
#define MQTT_BUTTON_SWITCH_FORCE_LOCAL   false   // [SetOption61] Force local operation when button/switch topic is set (false = off, true = on)
#undef MQTT_NO_HOLD_RETAIN
#define MQTT_NO_HOLD_RETAIN    false             // [SetOption62] Disable retain flag on HOLD messages
#undef APP_NO_RELAY_SCAN
#define APP_NO_RELAY_SCAN      false             // [SetOption63] Don't scan relay power state at restart
#undef MQTT_INDEX_SEPARATOR
#define MQTT_INDEX_SEPARATOR    true             // [SetOption64] Enable "_" instead of "-" as sensor index separator
#undef APP_DISABLE_POWERCYCLE
#define APP_DISABLE_POWERCYCLE false             // [SetOption65] Disable fast power cycle detection for device reset
#undef MQTT_TUYA_RECEIVED
#define MQTT_TUYA_RECEIVED     false             // [SetOption66] Enable TuyaMcuReceived messages over Mqtt
#undef BUZZER_ENABLE
#define BUZZER_ENABLE          false             // [SetOption67] Enable buzzer when available
#undef LIGHT_CHANNEL_MODE
#define LIGHT_CHANNEL_MODE     false             // [SetOption68] Enable multi-channels PWM instead of Color PWM
//setOption69 Deprecated
//setOption70 DNE
#undef ENERGY_DDS2382_MODE
#define ENERGY_DDS2382_MODE    false             // [SetOption71] Enable DDS2382 different Modbus registers for Active Energy (#6531)
#undef ENERGY_HARDWARE_TOTALS
#define ENERGY_HARDWARE_TOTALS false             // [SetOption72] Enable hardware energy total counter as reference (#6561)
//setOption73 Exists but not in Firmware
#undef DS18X20_PULL_UP
#define DS18X20_PULL_UP        false             // [SetOption74] Enable internal pullup for single DS18x20 sensor
#undef MQTT_GROUPTOPIC_FORMAT
#define MQTT_GROUPTOPIC_FORMAT false             // [SetOption75] GroupTopic replaces %topic% (false) or fixed topic cmnd/grouptopic (true)
#undef DEEPSLEEP_BOOTCOUNT
#define DEEPSLEEP_BOOTCOUNT    false             // [SetOption76] Enable incrementing bootcount when deepsleep is enabled
#undef LIGHT_SLIDER_POWER
#define LIGHT_SLIDER_POWER     false             // [SetOption77] Do not power off if slider moved to far left
//setOption78 Exists but not in Firmware
#undef COUNTER_RESET
#define COUNTER_RESET          false             // [SetOption79] Enable resetting of counters after telemetry was sent
#undef SHUTTER_SUPPORT
#define SHUTTER_SUPPORT        false             // [SetOption80] Enable shutter support
#undef PCF8574_INVERT_PORTS
#define PCF8574_INVERT_PORTS   false             // [SetOption81] Invert all ports on PCF8574 devices
#undef LIGHT_ALEXA_CT_RANGE
#define LIGHT_ALEXA_CT_RANGE   false             // [SetOption82] Reduced CT range for Alexa
#undef ZIGBEE_FRIENDLY_NAMES
#define ZIGBEE_FRIENDLY_NAMES  false             // [SetOption83] Enable Zigbee FriendlyNames instead of ShortAddresses when possible
//setOption 84-88 Exist but not in Firmware
//setOption89 DNE
//setOption90 Exists but not in Firmware
//setOption91 DNE
#undef LIGHT_PWM_CT_MODE
#define LIGHT_PWM_CT_MODE      false             // [SetOption92] Set PWM Mode from regular PWM to ColorTemp control (Xiaomi Philips ...) a.k.a. module 48 mode
//setOption93 Exists but not in Firmware
//setOption94 Exists but not in Firmware
//setOption 95-96 DNE
//setOption97 Exists but not in Firmware
//setOption98 Exists but not in Firmware
//setOption99 Exists but not in Firmware
#undef ZIGBEE_RMV_ZBRECEIVED
#define ZIGBEE_RMV_ZBRECEIVED  false             // [SetOption100] Remove ZbReceived form JSON message
#undef ZIGBEE_INDEX_EP
#define ZIGBEE_INDEX_EP        false             // [SetOption101] Add the source endpoint as suffix to attributes, ex `Power3` instead of `Power` if sent from endpoint 3
//setOption102
#undef MQTT_TLS_ENABLED
#define MQTT_TLS_ENABLED       false             // [SetOption103] Enable TLS mode (requires TLS version)
#undef MQTT_NO_RETAIN
#define MQTT_NO_RETAIN         false             // [SetOption104] No Retain - disable all MQTT retained messages, some brokers don't support it: AWS IoT, Losant
#undef LIGHT_WHITE_BLEND_MODE
#define LIGHT_WHITE_BLEND_MODE false             // [SetOption105] White Blend Mode - used to be `RGBWWTable` last value `0`, now deprecated in favor of this option
#undef LIGHT_VIRTUAL_CT
#define LIGHT_VIRTUAL_CT       false             // [SetOption106] Virtual CT - Creates a virtual White ColorTemp for RGBW lights
#undef LIGHT_VIRTUAL_CT_CW
#define LIGHT_VIRTUAL_CT_CW    false             // [SetOption107] Virtual CT Channel - signals whether the hardware white is cold CW (true) or warm WW (false)
//setOption108
#undef EMULATION_HUE_1ST_GEN
#define EMULATION_HUE_1ST_GEN  false             // [Emulation] Force SetOption109 1 - if you only have Echo Dot 2nd gen devices
//setOption 110-112 DNE
//setOption 113-116 Exist but not in firmware


// -- Enable Scripting or Rules-----------
#define useScripts false    //false for Rules, True for Scripts

#if useScripts
  #ifndef USE_SCRIPT
    #undef USE_RULES
    #define USE_SCRIPT  // adds about 17k flash size, variable ram size
  #endif 
#else
  #undef USE_SCRIPT
  #define USE_RULES
#endif


// -- Syslog --------------------------------------
#undef SYS_LOG_HOST
#define SYS_LOG_HOST           ""                // [LogHost] (Linux) syslog host
#undef SYS_LOG_PORT
#define SYS_LOG_PORT           514               // [LogPort] default syslog UDP port
#undef SYS_LOG_LEVEL
#define SYS_LOG_LEVEL          LOG_LEVEL_NONE    // [SysLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)
#undef SERIAL_LOG_LEVEL
#define SERIAL_LOG_LEVEL       LOG_LEVEL_NONE    // [SerialLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)
#undef WEB_LOG_LEVEL
#define WEB_LOG_LEVEL          LOG_LEVEL_INFO    // [WebLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)
#undef MQTT_LOG_LEVEL
#define MQTT_LOG_LEVEL         LOG_LEVEL_NONE    // [MqttLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "10.101.3.1" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "AFS_USER"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "AFS_PASS"         // [MqttPassword] Optional password

// -- MQTT topics ---------------------------------
  // Example "tasmota/bedroom/%topic%/%prefix%/" up to 80 characers
#undef MQTT_FULLTOPIC
#define MQTT_FULLTOPIC         "%prefix%/%topic%/" // [FullTopic] Subscribe and Publish full topic name - Legacy topic

// %prefix% token options
#undef SUB_PREFIX
#define SUB_PREFIX             "cmnd"            // [Prefix1] Tasmota devices subscribe to %prefix%/%topic% being SUB_PREFIX/MQTT_TOPIC and SUB_PREFIX/MQTT_GRPTOPIC
#undef PUB_PREFIX
#define PUB_PREFIX             "stat"            // [Prefix2] Tasmota devices publish to %prefix%/%topic% being PUB_PREFIX/MQTT_TOPIC
#undef PUB_PREFIX2
#define PUB_PREFIX2            "tele"            // [Prefix3] Tasmota devices publish telemetry data to %prefix%/%topic% being PUB_PREFIX2/MQTT_TOPIC/UPTIME, POWER and TIME
                                                 //   May be named the same as PUB_PREFIX
// %topic% token options (also ButtonTopic and SwitchTopic)
#undef MQTT_TOPIC
#define MQTT_TOPIC             PROJECT "_%06X"   // [Topic] unique MQTT device topic including (part of) device MAC address
#undef MQTT_GRPTOPIC
#define MQTT_GRPTOPIC          "Sensor"        // [GroupTopic] MQTT Group topic
#undef MQTT_GROUPTOPIC_FORMAT
#define MQTT_GROUPTOPIC_FORMAT false             // [SetOption75] GroupTopic replaces %topic% (false) or fixed topic cmnd/grouptopic (true)
#undef MQTT_BUTTON_TOPIC
#define MQTT_BUTTON_TOPIC      "0"               // [ButtonTopic] MQTT button topic, "0" = same as MQTT_TOPIC, set to 'PROJECT "_BTN_%06X"' for unique topic including device MAC address
#undef MQTT_SWITCH_TOPIC
#define MQTT_SWITCH_TOPIC      "0"               // [SwitchTopic] MQTT button topic, "0" = same as MQTT_TOPIC, set to 'PROJECT "_SW_%06X"' for unique topic including device MAC address
#undef MQTT_CLIENT_ID
#define MQTT_CLIENT_ID         "AFS_%06X"       // [MqttClient] Also fall back topic using last 6 characters of MAC address or use "DVES_%12X" for complete MAC address

// -- MQTT - Telemetry ----------------------------
#undef TELE_PERIOD
#define TELE_PERIOD            10               // [TelePeriod] Telemetry (0 = disable, 10 - 3600 seconds)
#undef TELE_ON_POWER
#define TELE_ON_POWER          false             // [SetOption59] send tele/STATE together with stat/RESULT (false = Disable, true = Enable)

// -- HTTP ----------------------------------------
#undef WEB_SERVER
#define WEB_SERVER             2                 // [WebServer] Web server (0 = Off, 1 = Start as User, 2 = Start as Admin)
#undef WEB_PASSWORD
#define WEB_PASSWORD           ""                // [WebPassword] Web server Admin mode Password for WEB_USERNAME (empty string = Disable)
#undef FRIENDLY_NAME
#define FRIENDLY_NAME          PROJECT "_%06X"         // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
#undef EMULATION
#define EMULATION              EMUL_NONE         // [Emulation] Select Belkin WeMo (single relay/light) or Hue Bridge emulation (multi relay/light) (EMUL_NONE, EMUL_WEMO or EMUL_HUE)
#undef EMULATION_HUE_1ST_GEN
#define EMULATION_HUE_1ST_GEN  false             // [Emulation] Force SetOption109 1 - if you only have Echo Dot 2nd gen devices
#undef CORS_DOMAIN
#define CORS_DOMAIN            ""                // [Cors] CORS Domain for preflight requests

// -- HTTP Options --------------------------------
#undef GUI_SHOW_HOSTNAME
#define GUI_SHOW_HOSTNAME      true             // [SetOption53] Show hostname and IP address in GUI main menu

// -- Other Options -------------------------------
#undef TIMERS_ENABLED
#define TIMERS_ENABLED         true             // [Timers] Enable Timers

// -- Lights --------------------------------------
#undef WS2812_LEDS
#define WS2812_LEDS            1                // [Pixels] Number of WS2812 LEDs to start with (max is 512)

// -- Wifi Config tools ---------------------------
#undef WIFI_SOFT_AP_CHANNEL                    // Soft Access Point Channel number between 1 and 13 as used by Wifi Manager web GUI

// -- MQTT - Domoticz -----------------------------
 #undef USE_DOMOTICZ                             // Enable Domoticz (+6k code, +0.3k mem)
  #undef DOMOTICZ_IN_TOPIC         // Domoticz Input Topic
  #undef DOMOTICZ_OUT_TOPIC       // Domoticz Output Topic

// -- HTTP ----------------------------------------
  #undef USE_EMULATION_HUE                      // Enable Hue Bridge emulation for Alexa (+14k code, +2k mem common)
  #undef USE_EMULATION_WEMO                     // Enable Belkin WeMo emulation for Alexa (+6k code, +2k mem common)

// -- mDNS ----------------------------------------
#define USE_DISCOVERY                            // Enable mDNS for the following services (+8k code or +23.5k code with core 2_5_x, +0.3k mem)

// -- Ping ----------------------------------------
//  #define USE_PING                                 // Enable Ping command (+2k code)

// -- Application ---------------------------------
#undef KEY_DISABLE_MULTIPRESS
#define KEY_DISABLE_MULTIPRESS true             // [SetOption1]  Disable button multipress

// -- Rules or Script  ----------------------------
// Select none or only one of the below defines USE_RULES or USE_SCRIPT
#undef USE_RULES 
//#define USE_RULES                                // Add support for rules (+8k code)
//  #define USE_EXPRESSION                         // Add support for expression evaluation in rules (+3k2 code, +64 bytes mem)
//    #define SUPPORT_IF_STATEMENT                 // Add support for IF statement in rules (+4k2 code, -332 bytes mem)

//#undef USE_SCRIPT

#define USE_SCRIPT                               // Add support for script (+17k code)
  //#define USE_SCRIPT_FATFS 4                     // Script: Add FAT FileSystem Support

  #define SUPPORT_MQTT_EVENT                     // Support trigger event with MQTT subscriptions (+3k5 code)
  #define USE_BUTTON_EVENT
  #define USE_SCRIPT_STATUS
  #define USE_SCRIPT_JSON_EXPORT
  #define USE_SCRIPT_TIMER
  #define USE_SCRIPT_SUB_COMMAND
  #define SCRIPT_POWER_SECTION
  #define SCRIPT_STRIP_COMMENTS
  #define USE_SCRIPT_GLOBVARS
  #define USE_WEBSEND_RESPONSE




// -- Optional modules ----------------------------
#undef ROTARY_V1                                // Add support for Rotary Encoder as used in MI Desk Lamp (+0k8 code)
#undef ROTARY_MAX_STEPS                     // Rotary step boundary
#undef USE_SONOFF_RF                            // Add support for Sonoff Rf Bridge (+3k2 code)
#undef USE_RF_FLASH                           // Add support for flashing the EFM8BB1 chip on the Sonoff RF Bridge. C2CK must be connected to GPIO4, C2D to GPIO5 on the PCB (+2k7 code)
#undef USE_SONOFF_SC                            // Add support for Sonoff Sc (+1k1 code)
#undef USE_TUYA_MCU                             // Add support for Tuya Serial MCU
#undef TUYA_DIMMER_ID                        // Default dimmer Id

#undef USE_ARMTRONIX_DIMMERS                    // Add support for Armtronix Dimmers (+1k4 code)
#undef USE_PS_16_DZ                             // Add support for PS-16-DZ Dimmer (+2k code)
#undef USE_SONOFF_IFAN                          // Add support for Sonoff iFan02 and iFan03 (+2k code)
#undef USE_BUZZER                               // Add support for a buzzer (+0k6 code)
#undef USE_ARILUX_RF                            // Add support for Arilux RF remote controller (+0k8 code, 252 iram (non 2.3.0))
#undef USE_SHUTTER                              // Add Shutter support for up to 4 shutter with different motortypes (+11k code)

#undef USE_EXS_DIMMER                           // Add support for ES-Store WiFi Dimmer (+1k5 code)

#define USE_HOTPLUG                              // Add support for sensor HotPlug




#undef USE_PWM_DIMMER                           // Add support for MJ-SD01/acenx/NTONPOWER PWM dimmers (+2k3 code, DGR=0k7)
  #undef USE_PWM_DIMMER_REMOTE                  // Add support for remote switches to PWM Dimmer (requires USE_DEVICE_GROUPS) (+0k6 code)

#undef USE_SONOFF_D1                            // Add support for Sonoff D1 Dimmer (+0k7 code)
#undef USE_SHELLY_DIMMER                        // Add support for Shelly Dimmer (+3k code)
  #undef SHELLY_CMDS                            // Add command to send co-processor commands (+0k3 code)
  #undef SHELLY_FW_UPGRADE                      // Add firmware upgrade option for co-processor (+3k4 code)


// -- Optional light modules ----------------------


  #undef USE_WS2812_HARDWARE
  #define USE_WS2812_HARDWARE  NEO_HW_WS2812X     // Hardware type (NEO_HW_WS2812, NEO_HW_WS2812X, NEO_HW_WS2813, NEO_HW_SK6812, NEO_HW_LC8812, NEO_HW_APA106, NEO_HW_P9813)

#undef USE_MY92X1                               // Add support for MY92X1 RGBCW led controller as used in Sonoff B1, Ailight and Lohas
#undef USE_SM16716                              // Add support for SM16716 RGB LED controller (+0k7 code)
#undef USE_SM2135                               // Add support for SM2135 RGBCW led control as used in Action LSC (+0k6 code)
#undef USE_SONOFF_L1                            // Add support for Sonoff L1 led control
#undef USE_ELECTRIQ_MOODL                       // Add support for ElectriQ iQ-wifiMOODL RGBW LED controller (+0k3 code)
#undef USE_LIGHT_PALETTE                        // Add support for color palette (+0k7 code)
#undef USE_LIGHT_VIRTUAL_CT                     // Add support for Virtual White Color Temperature (+1.1k code)
#undef USE_DGR_LIGHT_SEQUENCE                   // Add support for device group light sequencing (requires USE_DEVICE_GROUPS) (+0k2 code)


// -- One wire sensors ----------------------------
#undef USE_DS18x20                              // Add support for DS18x20 sensors with id sort, single scan and read retry (+2k6 code)
//  #define W1_PARASITE_POWER                      // Optimize for parasite powered sensors

// -- I2C sensors ---------------------------------


#ifdef USE_I2C
//  #define USE_SHT                                // [I2cDriver8] Enable SHT1X sensor (+1k4 code)
//  #define USE_HTU                                // [I2cDriver9] Enable HTU21/SI7013/SI7020/SI7021 sensor (I2C address 0x40) (+1k5 code)
//  #define USE_BMP                                // [I2cDriver10] Enable BMP085/BMP180/BMP280/BME280 sensors (I2C addresses 0x76 and 0x77) (+4k4 code)
//    #define USE_BME680                           // Enable support for BME680 sensor using Bosch BME680 library (+4k code)
//  #define USE_BH1750                             // [I2cDriver11] Enable BH1750 sensor (I2C address 0x23 or 0x5C) (+0k5 code)
//  #define USE_VEML6070                           // [I2cDriver12] Enable VEML6070 sensor (I2C addresses 0x38 and 0x39) (+1k5 code)
    #undef USE_VEML6070_RSET              // VEML6070, Rset in Ohm used on PCB board, default 270K = 270000ohm, range for this sensor: 220K ... 1Meg
    #undef USE_VEML6070_SHOW_RAW                // VEML6070, shows the raw value of UV-A
//  #define USE_ADS1115                            // [I2cDriver13] Enable ADS1115 16 bit A/D converter (I2C address 0x48, 0x49, 0x4A or 0x4B) based on Adafruit ADS1x15 library (no library needed) (+0k7 code)
//  #define USE_INA219                             // [I2cDriver14] Enable INA219 (I2C address 0x40, 0x41 0x44 or 0x45) Low voltage and current sensor (+1k code)
//  #define USE_INA226                             // [I2cDriver35] Enable INA226 (I2C address 0x40, 0x41 0x44 or 0x45) Low voltage and current sensor (+2k3 code)
//  #define USE_SHT3X                              // [I2cDriver15] Enable SHT3x (I2C address 0x44 or 0x45) or SHTC3 (I2C address 0x70) sensor (+0k7 code)
//  #define USE_TSL2561                            // [I2cDriver16] Enable TSL2561 sensor (I2C address 0x29, 0x39 or 0x49) using library Joba_Tsl2561 (+2k3 code)
//  #define USE_TSL2591                            // [I2cDriver40] Enable TSL2591 sensor (I2C address 0x29) using library Adafruit_TSL2591 (+1k6 code)
//  #define USE_MGS                                // [I2cDriver17] Enable Xadow and Grove Mutichannel Gas sensor using library Multichannel_Gas_Sensor (+10k code)
    #undef MGS_SENSOR_ADDR                  // Default Mutichannel Gas sensor i2c address
//  #define USE_SGP30                              // [I2cDriver18] Enable SGP30 sensor (I2C address 0x58) (+1k1 code)
//  #define USE_SI1145                             // [I2cDriver19] Enable SI1145/46/47 sensor (I2C address 0x60) (+1k code)
//  #define USE_LM75AD                             // [I2cDriver20] Enable LM75AD sensor (I2C addresses 0x48 - 0x4F) (+0k5 code)
//  #define USE_APDS9960                           // [I2cDriver21] Enable APDS9960 Proximity Sensor (I2C address 0x39). Disables SHT and VEML6070 (+4k7 code)
    #undef USE_APDS9960_GESTURE                   // Enable APDS9960 Gesture feature (+2k code)
    #undef USE_APDS9960_PROXIMITY                 // Enable APDS9960 Proximity feature (>50 code)
    #undef USE_APDS9960_COLOR                     // Enable APDS9960 Color feature (+0.8k code)
    #undef USE_APDS9960_STARTMODE               // Default to enable Gesture mode
//  #define USE_MCP230xx                           // [I2cDriver22] Enable MCP23008/MCP23017 - Must define I2C Address in #define USE_MCP230xx_ADDR below - range 0x20 - 0x27 (+4k7 code)
//    #define USE_MCP230xx_ADDR 0x20               // Enable MCP23008/MCP23017 I2C Address to use (Must be within range 0x20 through 0x26 - set according to your wired setup)
//    #define USE_MCP230xx_OUTPUT                  // Enable MCP23008/MCP23017 OUTPUT support through sensor29 commands (+1k5 code)
//    #define USE_MCP230xx_DISPLAYOUTPUT           // Enable MCP23008/MCP23017 to display state of OUTPUT pins on Web UI (+0k2 code)
//  #define USE_PCA9685                            // [I2cDriver1] Enable PCA9685 I2C HW PWM Driver - Must define I2C Address in #define USE_PCA9685_ADDR below - range 0x40 - 0x47 (+1k4 code)
//    #define USE_PCA9685_ADDR 0x40                // Enable PCA9685 I2C Address to use (Must be within range 0x40 through 0x47 - set according to your wired setup)
//    #define USE_PCA9685_FREQ 50                  // Define default PWM frequency in Hz to be used (must be within 24 to 1526) - If other value is used, it will rever to 50Hz
//  #define USE_MPR121                             // [I2cDriver23] Enable MPR121 controller (I2C addresses 0x5A, 0x5B, 0x5C and 0x5D) in input mode for touch buttons (+1k3 code)
//  #define USE_CCS811                             // [I2cDriver24] Enable CCS811 sensor (I2C address 0x5A) (+2k2 code)
//  #define USE_MPU6050                            // [I2cDriver25] Enable MPU6050 sensor (I2C address 0x68 AD0 low or 0x69 AD0 high) (+3K3 of code and 188 Bytes of RAM)
//    #define USE_MPU6050_DMP                      // Enable in MPU6050 to use the DMP on the chip, should create better results (+8k6 of code)
//  #define USE_DS3231                             // [I2cDriver26] Enable DS3231 external RTC in case no Wifi is avaliable. See docs in the source file (+1k2 code)
//    #define USE_RTC_ADDR  0x68                   // Default I2C address 0x68
//  #define USE_MGC3130                            // [I2cDriver27] Enable MGC3130 Electric Field Effect Sensor (I2C address 0x42) (+2k7 code, 0k3 mem)
//  #define USE_MAX44009                           // [I2cDriver28] Enable MAX44009 Ambient Light sensor (I2C addresses 0x4A and 0x4B) (+0k8 code)
//  #define USE_SCD30                              // [I2cDriver29] Enable Sensiron SCd30 CO2 sensor (I2C address 0x61) (+3k3 code)
  #define USE_SPS30                              // [I2cDriver30] Enable Sensiron SPS30 particle sensor (I2C address 0x69) (+1.7 code)
  #undef USE_ADE7953                            // [I2cDriver7] Enable ADE7953 Energy monitor as used on Shelly 2.5 (I2C address 0x38) (+1k5)
//  #define USE_VL53L0X                            // [I2cDriver31] Enable VL53L0x time of flight sensor (I2C address 0x29) (+4k code)
//  #define USE_VL53L1X                            // [I2cDriver54] Enable VL53L1X time of flight sensor (I2C address 0x29) using Pololu VL53L1X library (+2k9 code)
//  #define USE_TOF10120                           // [I2cDriver57] Enable TOF10120 time of flight sensor (I2C address 0x52) (+0k6 code)
//  #define USE_MLX90614                           // [I2cDriver32] Enable MLX90614 ir temp sensor (I2C address 0x5a) (+0.6k code)
//  #define USE_CHIRP                              // [I2cDriver33] Enable CHIRP soil moisture sensor (variable I2C address, default 0x20)
//  #define USE_PAJ7620                            // [I2cDriver34] Enable PAJ7620 gesture sensor (I2C address 0x73) (+2.5k code)
//  #define USE_PCF8574                            // [I2cDriver2] Enable PCF8574 I/O Expander (I2C addresses 0x20 - 0x26 and 0x39 - 0x3F) (+1k9 code)
//  #define USE_HIH6                               // [I2cDriver36] Enable Honeywell HIH Humidity and Temperature sensor (I2C address 0x27) (+0k6)
//  #define USE_DHT12                              // [I2cDriver41] Enable DHT12 humidity and temperature sensor (I2C address 0x5C) (+0k7 code)
//  #define USE_DS1624                             // [I2cDriver42] Enable DS1624, DS1621 temperature sensor (I2C addresses 0x48 - 0x4F) (+1k2 code)
//  #define USE_AHT1x                              // [I2cDriver43] Enable AHT10/15 humidity and temperature sensor (I2C address 0x38, 0x39) (+0k8 code)
//    #define USE_AHT2x                              // [I2cDriver43] Enable AHT20 instead of AHT1x humidity and temperature sensor (I2C address 0x38) (+0k8 code)
//  #define USE_WEMOS_MOTOR_V1                     // [I2cDriver44] Enable Wemos motor driver V1 (I2C addresses 0x2D - 0x30) (+0k7 code)
//    #define WEMOS_MOTOR_V1_ADDR  0x30            // Default I2C address 0x30
//    #define WEMOS_MOTOR_V1_FREQ  1000            // Default frequency
//  #define USE_HDC1080                            // [I2cDriver45] Enable HDC1080 temperature/humidity sensor (I2C address 0x40) (+1k5 code)
//  #define USE_IAQ                                // [I2cDriver46] Enable iAQ-core air quality sensor (I2C address 0x5a) (+0k6 code)
//  #define USE_AS3935                             // [I2cDriver48] Enable AS3935 Franklin Lightning Sensor (I2C address 0x03) (+5k4 code)
//  #define USE_VEML6075                           // [I2cDriver49] Enable VEML6075 UVA/UVB/UVINDEX Sensor (I2C address 0x10) (+2k1 code)
//  #define USE_VEML7700                           // [I2cDriver50] Enable VEML7700 Ambient Light sensor (I2C addresses 0x10) (+4k5 code)
//  #define USE_MCP9808                            // [I2cDriver51] Enable MCP9808 temperature sensor (I2C addresses 0x18 - 0x1F) (+0k9 code)
//  #define USE_HP303B                             // [I2cDriver52] Enable HP303B temperature and pressure sensor (I2C address 0x76 or 0x77) (+6k2 code)
//  #define USE_MLX90640                           // [I2cDriver53] Enable MLX90640 IR array temperature sensor (I2C address 0x33) (+20k code)
//  #define USE_EZOPH                              // [I2cDriver55] Enable support for EZO's pH sensor (+0k3 code) - Shared EZO code required for any EZO device (+1k2 code)
//  #define USE_EZOORP                             // [I2cDriver55] Enable support for EZO's ORP sensor (+0k3 code) - Shared EZO code required for any EZO device (+1k2 code)
//  #define USE_EZORTD                             // [I2cDriver55] Enable support for EZO's RTD sensor (+0k2 code) - Shared EZO code required for any EZO device (+1k2 code)
//  #define USE_EZOHUM                             // [I2cDriver55] Enable support for EZO's HUM sensor (+0k3 code) - Shared EZO code required for any EZO device (+1k2 code)
//  #define USE_EZOEC                              // [I2cDriver55] Enable support for EZO's EC sensor (+0k3 code) - Shared EZO code required for any EZO device (+1k2 code)
//  #define USE_EZOCO2                             // [I2cDriver55] Enable support for EZO's CO2 sensor (+0k2 code) - Shared EZO code required for any EZO device (+1k2 code)
//  #define USE_EZOO2                              // [I2cDriver55] Enable support for EZO's O2 sensor (+0k3 code) - Shared EZO code required for any EZO device (+1k2 code)
//  #define USE_EZOPRS                             // [I2cDriver55] Enable support for EZO's PRS sensor (+0k7 code) - Shared EZO code required for any EZO device (+1k2 code)
//  #define USE_EZOFLO                             // [I2cDriver55] Enable support for EZO's FLO sensor (+0k4 code) - Shared EZO code required for any EZO device (+1k2 code)
//  #define USE_EZODO                              // [I2cDriver55] Enable support for EZO's DO sensor (+0k3 code) - Shared EZO code required for any EZO device (+1k2 code)
//  #define USE_EZORGB                             // [I2cDriver55] Enable support for EZO's RGB sensor (+0k5 code) - Shared EZO code required for any EZO device (+1k2 code)
//  #define USE_EZOPMP                             // [I2cDriver55] Enable support for EZO's PMP sensor (+0k3 code) - Shared EZO code required for any EZO device (+1k2 code)
//  #define USE_SEESAW_SOIL                        // [I2cDriver56] Enable Capacitice Soil Moisture & Temperature Sensor (I2C addresses 0x36 - 0x39) (+1k3 code)

  #define USE_DISPLAY                            // Add I2C Display Support (+2k code)
    #define USE_DISPLAY_MODES1TO5                // Enable display mode 1 to 5 in addition to mode 0
//    #define USE_DISPLAY_LCD                      // [DisplayModel 1] [I2cDriver3] Enable Lcd display (I2C addresses 0x27 and 0x3F) (+6k code)
//    #define USE_DISPLAY_SSD1306                  // [DisplayModel 2] [I2cDriver4] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
//    #define USE_DISPLAY_MATRIX                   // [DisplayModel 3] [I2cDriver5] Enable 8x8 Matrix display (I2C adresseses see below) (+11k code)
//      #define MTX_ADDRESS1     0x71              // [DisplayAddress1] I2C address of first 8x8 matrix module
//      #define MTX_ADDRESS2     0x74              // [DisplayAddress2] I2C address of second 8x8 matrix module
//      #define MTX_ADDRESS3     0x75              // [DisplayAddress3] I2C address of third 8x8 matrix module
//      #define MTX_ADDRESS4     0x72              // [DisplayAddress4] I2C address of fourth 8x8 matrix module
//      #define MTX_ADDRESS5     0x73              // [DisplayAddress5] I2C address of fifth 8x8 matrix module
//      #define MTX_ADDRESS6     0x76              // [DisplayAddress6] I2C address of sixth 8x8 matrix module
//      #define MTX_ADDRESS7     0x00              // [DisplayAddress7] I2C address of seventh 8x8 matrix module
//      #define MTX_ADDRESS8     0x00              // [DisplayAddress8] I2C address of eigth 8x8 matrix module
//    #define USE_DISPLAY_SEVENSEG                 // [DisplayModel 11] [I2cDriver47] Enable sevenseg display (I2C 0x70-0x77) (<+11k code)
//      #define USE_DISPLAY_SEVENSEG_COMMON_ANODE  // Enable support for common anode sevenseg displays
                                                 // Multiple sevenseg displays are logically arranged vertically with MTX_ADDRESS1 at y=0,
                                                 // MTX_ADDRESS2 at y=1, up to MTX_ADDRESS8 at y=7
                                                 // Command: DisplayText [yn]8888
                                                 // will display 8888 at sevenseg display at I2C address MTX_ADDRESS(n-1)
                                                 // Each segment may be address Command: DisplayText [xn]m
                                                 //  where n is 0..4 (4 digits and middle :) and m is decimal for bitmap of which segment to turn on.
                                                 // Reference: https://cdn-learn.adafruit.com/downloads/pdf/adafruit-led-backpack.pdf
    // #define SEVENSEG_ADDRESS1     0x70      // No longer used.  Use MTX_ADDRESS1 - MTX_ADDRESS8 instead to specify I2C address of sevenseg displays
    #define USE_DISPLAY_SH1106                   // [DisplayModel 7] [I2cDriver6] Enable SH1106 Oled 128x64 display (I2C addresses 0x3C and 0x3D)
    #define USE_DT_VARS
#endif  // USE_I2C

// -- SPI sensors ---------------------------------
//#define USE_SPI                                  // Hardware SPI using GPIO12(MISO), GPIO13(MOSI) and GPIO14(CLK) in addition to two user selectable GPIOs(CS and DC)

#ifdef USE_SPI
//  #define USE_NRF24                              // Add SPI support for NRF24L01(+) (+2k6 code)
    #define USE_MIBLE                            // BLE-bridge for some Mijia-BLE-sensors (+4k7 code)
//  #define USE_DISPLAY                            // Add SPI Display support for 320x240 and 480x320 TFT
    #define USE_DISPLAY_ILI9341                  // [DisplayModel 4] Enable ILI9341 Tft 480x320 display (+19k code)
//    #define USE_DISPLAY_EPAPER_29                // [DisplayModel 5] Enable e-paper 2.9 inch display (+19k code)
//    #define USE_DISPLAY_EPAPER_42                // [DisplayModel 6] Enable e-paper 4.2 inch display
//    #define USE_DISPLAY_ILI9488                  // [DisplayModel 8] [I2cDriver38] (Touch)
//    #define USE_DISPLAY_SSD1351                  // [DisplayModel 9] Enable SSD1351 module
//    #define USE_DISPLAY_RA8876                   // [DisplayModel 10] [I2cDriver39] (Touch)
//    #define USE_DISPLAY_ST7789                   // [DisplayModel 12] Enable ST7789 module
//    #define USE_DISPLAY_SSD1331                  // [DisplayModel 14] Enable SSD1331 module
//  #define USE_RC522                              // Add support for MFRC522 13.56Mhz Rfid reader (+6k code)
//    #define USE_RC522_DATA_FUNCTION              // Add support for reading data block content (+0k4 code)
//    #define USE_RC522_TYPE_INFORMATION           // Add support for showing card type (+0k4 code)

#endif  // USE_SPI

//#define USE_DISPLAY                              // Add Display support
//  #define USE_DISPLAY_TM1637                     // [DisplayModel 15] Enable TM1637 module

// -- Serial sensors ------------------------------
//#define USE_MHZ19                                // Add support for MH-Z19 CO2 sensor (+2k code)
//#define USE_SENSEAIR                             // Add support for SenseAir K30, K70 and S8 CO2 sensor (+2k3 code)
  #undef CO2_LOW                             // Below this CO2 value show green light (needs PWM or WS2812 RG(B) led and enable with SetOption18 1)
  #undef CO2_HIGH                           // Above this CO2 value show red light (needs PWM or WS2812 RG(B) led and enable with SetOption18 1)
//#define USE_PMS5003                              // Add support for PMS5003 and PMS7003 particle concentration sensor (+1k3 code)
  //#define PMS_MODEL_PMS3003                      // Enable support of PMS3003 instead of PMS5003/PMS7003 (needs the USE_PMS5003 above)
//#define USE_NOVA_SDS                             // Add support for SDS011 and SDS021 particle concentration sensor (+1k5 code)
  #undef STARTING_OFFSET                      // Turn on NovaSDS XX-seconds before tele_period is reached
//#define USE_HPMA                                 // Add support for Honeywell HPMA115S0 particle concentration sensor (+1k4)
//#define USE_SR04                                 // Add support for HC-SR04 ultrasonic devices (+1k code)
//#define USE_DYP                                  // Add support for DYP ME-007 ultrasonic distance sensor, serial port version (+0k5 code)
#undef USE_SERIAL_BRIDGE                        // Add support for software Serial Bridge (+0k8 code)
//#define USE_TCP_BRIDGE                           //  Add support for Serial to TCP bridge (+1.3k code)
//#define USE_MP3_PLAYER                           // Use of the DFPlayer Mini MP3 Player RB-DFR-562 commands: play, volume and stop
  #undef MP3_VOLUME                          // Set the startup volume on init, the range can be 0..30(max)
//#define USE_AZ7798                               // Add support for AZ-Instrument 7798 CO2 datalogger (+1k6 code)
//#define USE_PN532_HSU                            // Add support for PN532 using HSU (Serial) interface (+1k8 code, 140 bytes mem)
//  #define USE_PN532_DATA_FUNCTION                // Add sensor40 command support for erase, setting data block content (+1k7 code, 388 bytes mem)
//  #define USE_PN532_DATA_RAW                     // Allow DATA block to be used by non-alpha-numberic data (+ 80 bytes code, 48 bytes ram)
//#define USE_RDM6300                              // Add support for RDM6300 125kHz RFID Reader (+0k8)
//#define USE_IBEACON                              // Add support for bluetooth LE passive scan of ibeacon devices (uses HM17 module)
//#define USE_GPS                                  // Add support for GPS and NTP Server for becoming Stratus 1 Time Source (+3k1 code, +132 bytes RAM)
//  #define USE_FLOG                               // Add support for GPS logging in OTA's Flash (Experimental) (+2k9 code, +8 bytes RAM)
//#define USE_HM10                                 // (ESP8266 only) Add support for HM-10 as a BLE-bridge (+9k3 code)
//#define USE_HRXL                                 // Add support for MaxBotix HRXL-MaxSonar ultrasonic range finders (+0k7)
//#define USE_TASMOTA_CLIENT                       // Add support for Arduino Uno/Pro Mini via serial interface including flashing (+2k6 code, 64 mem)
  #undef USE_TASMOTA_CLIENT_FLASH_SPEED    // Usually 57600 for 3.3V variants and 115200 for 5V variants
  #undef USE_TASMOTA_CLIENT_SERIAL_SPEED   // Depends on the sketch that is running on the Uno/Pro Mini
//#define USE_OPENTHERM                            // Add support for OpenTherm (+15k code)
//#define USE_MIEL_HVAC                            // Add support for Mitsubishi Electric HVAC serial interface (+5k code)
//#define USE_PROJECTOR_CTRL                       // Add support for LCD/DLP Projector serial control interface (+2k code)
//  #define USE_PROJECTOR_CTRL_NEC                 // Use codes for NEC
//  #define USE_PROJECTOR_CTRL_OPTOMA              // Use codes for OPTOMA
//#define USE_AS608                                // Add support for AS608 optical and R503 capacitive fingerprint sensor (+3k code)
//  #define USE_AS608_MESSAGES                     // Add verbose error messages (+0k4 code)

// -- Power monitoring sensors --------------------
#undef USE_ENERGY_MARGIN_DETECTION              // Add support for Energy Margin detection (+1k6 code)
  #undef USE_ENERGY_POWER_LIMIT                 // Add additional support for Energy Power Limit detection (+1k2 code)
#undef USE_PZEM004T                             // Add support for PZEM004T Energy monitor (+2k code)
#undef USE_PZEM_AC                              // Add support for PZEM014,016 Energy monitor (+1k1 code)
#undef USE_PZEM_DC                              // Add support for PZEM003,017 Energy monitor (+1k1 code)
#undef USE_MCP39F501                            // Add support for MCP39F501 Energy monitor as used in Shelly 2 (+3k1 code)
//#define USE_SDM72                                // Add support for Eastron SDM72-Modbus energy monitor (+0k3 code)
  #undef SDM72_SPEED                        // SDM72-Modbus RS485 serial speed (default: 9600 baud)
  // #define SDM72_IMPEXP                            // Show additonal import/export active energy and power in MQTT and Web (+0k5 code)
//#define USE_SDM120                               // Add support for Eastron SDM120-Modbus energy monitor (+1k1 code)
  #undef SDM120_SPEED                       // SDM120-Modbus RS485 serial speed (default: 2400 baud)
//#define USE_SDM630                               // Add support for Eastron SDM630-Modbus energy monitor (+0k6 code)
  #undef SDM630_SPEED                       // SDM630-Modbus RS485 serial speed (default: 9600 baud)
//  #define SDM630_IMPORT                          // Show import active energy in MQTT and Web (+0k3 code)
//#define USE_DDS2382                              // Add support for Hiking DDS2382 Modbus energy monitor (+0k6 code)
  #undef DDS2382_SPEED                      // Hiking DDS2382 Modbus RS485 serial speed (default: 9600 baud)
//#define USE_DDSU666                              // Add support for Chint DDSU666 Modbus energy monitor (+0k6 code)
  #undef DDSU666_SPEED                      // Chint DDSU666 Modbus RS485 serial speed (default: 9600 baud)
//#define USE_SOLAX_X1                             // Add support for Solax X1 series Modbus log info (+3k1 code)
  #undef SOLAXX1_SPEED                      // Solax X1 Modbus RS485 serial speed (default: 9600 baud)
  #undef SOLAXX1_PV2                            // Solax X1 using second PV
//#define USE_LE01MR                               // Add support for F&F LE-01MR Modbus energy monitor (+1k code)
  #undef LE01MR_SPEED                       // LE-01MR modbus baudrate (default: 9600)
  #undef LE01MR_ADDR                           // LE-01MR modbus address (default: 0x01)
#undef USE_BL0940                               // Add support for BL0940 Energy monitor as used in Blitzwolf SHP-10 (+1k6 code)
//#define USE_TELEINFO                             // Add support for Teleinfo via serial RX interface (+5k2 code, +168 RAM + SmartMeter LinkedList Values RAM)
//#define USE_IEM3000                              // Add support for Schneider Electric iEM3000-Modbus series energy monitor (+0k8 code)
  #undef IEM3000_SPEED                    // iEM3000-Modbus RS485 serial speed (default: 19200 baud)
  #undef IEM3000_ADDR                          // iEM3000-Modbus modbus address (default: 0x01)
//#define USE_WE517                                // Add support for Orno WE517-Modbus energy monitor (+1k code)

// -- Low level interface devices -----------------
#undef USE_DHT                                  // Add support for DHT11, AM2301 (DHT21, DHT22, AM2302, AM2321) and SI7021 Temperature and Humidity sensor (1k6 code)

//#define USE_MAX31855                             // Add support for MAX31855/MAX6675 K-Type thermocouple sensor using softSPI
//#define USE_MAX31865                             // Add support for MAX31865 RTD sensors using softSPI
  #undef MAX31865_PTD_WIRES                    // PTDs come in several flavors, pick yours. Specific settings per sensor possible with MAX31865_PTD_WIRES1..MAX31865_PTD_WIRES6
  #undef MAX31865_PTD_RES                    // Nominal PTD resistance at 0°C (100Ω for a PT100, 1000Ω for a PT1000, YMMV!). Specific settings per sensor possible with MAX31865_PTD_RES1..MAX31865_PTD_RES6
  #undef MAX31865_REF_RES                    // Reference resistor (Usually 430Ω for a PT100, 4300Ω for a PT1000). Specific settings per sensor possible with MAX31865_REF_RES1..MAX31865_REF_RES6
  #undef MAX31865_PTD_BIAS                     // To calibrate your not-so-good PTD. Specific settings per sensor possible with MAX31865_PTD_BIAS1..MAX31865_PTD_BIAS6
//#define USE_LMT01                                // Add support for TI LMT01 temperature sensor, count pulses on single GPIO (+0k5 code)
//#define USE_WIEGAND                              // Add support for 24/26/32/34 bit RFID Wiegand interface (D0/D1) (+1k7 code)

// -- IR Remote features - all protocols from IRremoteESP8266 --------------------------
// IR Full Protocols mode is activated through platform.io only.
// Either use 'default_envs = tasmota-ircustom' and disable some features here to keep code not too big
// or use 'default_envs = tasmota-ir' for a pre-packaged IR-dedicated firmware
// When using 'tasmota-ircustom' or 'tasmota-ir', parameters below
// (USE_IR_REMOTE, USE_IR_RECEIVE, USE_IR_HVAC...) are IGNORED.
//
// Code impact of IR full protocols is +81k code, 3k mem
// You can reduce this size by disabling some protocols in "lib/IRremoteESP8266.x.x.x/src/IRremoteESP8266.h"

// -- IR Remote features - subset of IR protocols --------------------------
#undef USE_IR_REMOTE                            // Send IR remote commands using library IRremoteESP8266 and ArduinoJson (+4k3 code, 0k3 mem, 48 iram)
  #undef IR_SEND_INVERTED                 // Invert the output. (default = false) e.g. LED is illuminated when GPIO is LOW rather than HIGH.
                                                 // Setting inverted to something other than the default could easily destroy your IR LED if you are overdriving it.
                                                 // Unless you REALLY know what you are doing, don't change this.
  #undef IR_SEND_USE_MODULATION             // Do we do frequency modulation during transmission? i.e. If not, assume a 100% duty cycle.
  #undef USE_IR_SEND_NEC                        // Support IRsend NEC protocol
  #undef USE_IR_SEND_RC5                        // Support IRsend Philips RC5 protocol
  #undef USE_IR_SEND_RC6                        // Support IRsend Philips RC6 protocol
  
  #undef USE_IR_RECEIVE                         // Support for IR receiver (+7k2 code, 264 iram)
    #undef IR_RCV_BUFFER_SIZE                // Max number of packets allowed in capture buffer (default 100 (*2 bytes ram))
    #undef IR_RCV_TIMEOUT                    // Number of milli-Seconds of no-more-data before we consider a message ended (default 15)
    #undef IR_RCV_MIN_UNKNOWN_SIZE            // Set the smallest sized "UNKNOWN" message packets we actually care about (default 6, max 255)
    #undef IR_RCV_WHILE_SENDING                // Turns on receiver while sending messages, i.e. receive your own. This is unreliable and can cause IR timing issues



#endif //ifdef FIRMWARE_SPS30



#endif  // _USER_CONFIG_OVERRIDE_H_
