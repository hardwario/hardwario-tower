#include <application.h>

/*
HARDWARIO TOWER - Indrustrial IoT Kit

Example firmware for single external temperature sensors DS18B20

For this example you will need:

- Sensor Module                 https://shop.hardwario.com/sensor-module/
- DS18B20 Temperature Sensor    https://shop.hardwario.com/temperature-sensor-ds18b20-original-2m-cable/
- Core Module                   https://shop.hardwario.com/core-module/
- Mini Battery Module           https://shop.hardwario.com/mini-battery-module/

For more information about firmware and HARDWARIO TOWER you can go to https://tower.hardwario.com/en/latest/firmware/basic-overview/

SENSOR MODULE CONNECTION
==========================

Sensor Module R1.0 - 4 pin connector
VCC, GND, - , DATA

Sensor Module R1.1 - 5 pin connector
- , GND , VCC , - , DATA


DS18B20 sensor pinout
=======================
VCC - red
GND - black
DATA- yellow (white)
*/

/*
Here you should define instances for the modules and tags
*/
static twr_ds18b20_t ds18b20;

/*
This is and example of event handler for DS18B20 Sensor
The 'event' variable will store value of the event that happend on the sensor
You can simply react to the event with a simple if statement

Events on DS18B20 Sensor:
    - TWR_DS18B20_EVENT_UPDATE
    - TWR_DS18B20_EVENT_ERROR
*/
void ds18b20_event_handler(twr_ds18b20_t *self, uint64_t device_address, twr_ds18b20_event_t event, void *param)
{
    (void) param;

    float temperature = NAN;

    if (event == TWR_DS18B20_EVENT_UPDATE)
    {
        twr_ds18b20_get_temperature_celsius(self, device_address, &temperature);

        twr_log_debug("UPDATE %" PRIx64 " = %0.2f", device_address, temperature);
    }
    else
    {
        twr_log_error("%" PRIx64, device_address);
    }
}

/*
You will find this function in all of our firmwares
In it you will initialize all the modules and set the event handlers for them

This function will run once at the start

Event Hadlers - functions that is called in case of some event on the module (Button press, Button hold, Temperature update, etc.)
*/
void application_init(void)
{
    twr_log_init(TWR_LOG_LEVEL_DEBUG, TWR_LOG_TIMESTAMP_ABS);

    twr_ds18b20_init_single(&ds18b20, TWR_DS18B20_RESOLUTION_BITS_12);
    twr_ds18b20_set_event_handler(&ds18b20, ds18b20_event_handler, NULL);
    twr_ds18b20_set_update_interval(&ds18b20, 5000);
}
