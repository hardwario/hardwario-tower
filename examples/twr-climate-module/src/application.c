/*
HARDWARIO TOWER - Indrustrial IoT Kit

Example firmware for basic usage of a Climate Module. It will measure values on all sensors and print them into the serial monitor
This module contains Temperature, Humidity, Barometer, Altitude and Light Intensity(LUX) sensor

For this example you will need:

- Climate Module                    https://shop.hardwario.com/climate-module/
- Core Module                       https://shop.hardwario.com/core-module/
- Mini Battery Module               https://shop.hardwario.com/mini-battery-module/
or you can buy Climate Monitor Kit  https://shop.hardwario.com/climate-monitor-kit/

For more information about firmware and HARDWARIO TOWER you can go to https://tower.hardwario.com/en/latest/firmware/basic-overview/
*/

#include "application.h"

/*
This function is just a simple example of event handler for Climate Module
The 'event' variable will store value of the event that happend on the module
You can simply react to the event with a simple if statement

In this example the function reacts to barometer update event because it should be updated after all the other sensors

Events on Climate Module:
    - TWR_MODULE_CLIMATE_EVENT_UPDATE_BAROMETER
    - TWR_MODULE_CLIMATE_EVENT_UPDATE_THERMOMETER
    - TWR_MODULE_CLIMATE_EVENT_UPDATE_HYGROMETER
    - TWR_MODULE_CLIMATE_EVENT_UPDATE_LUX_METER
*/
void climate_event_handler(twr_module_climate_event_t event, void* params)
{
    (void) params;
    float data[4] = {0.0};

    if (event == TWR_MODULE_CLIMATE_EVENT_UPDATE_BAROMETER) {
        // get all data from climate module
        twr_module_climate_get_temperature_celsius(&data[0]);
        twr_module_climate_get_humidity_percentage(&data[1]);
        twr_module_climate_get_illuminance_lux(&data[2]);
        twr_module_climate_get_pressure_pascal(&data[3]);

        twr_log_debug("%.4f, %.4f, %.2f, %.2f", data[0], data[1], data[2], data[3]);
    }
}

/*
You will find this function in all of our firmwares
In it you will initialize all the modules and set the event handlers for them

This function will run once at the start

Event Hadlers - functions that is called in case of some event on the module (Button press, Button hold, Temperature update, etc.)

You can set update intervals for each Climate Module separately or for all of them as you can see in this example.
*/
void application_init(void)
{
    // initialize log
    twr_log_init(TWR_LOG_LEVEL_DEBUG, TWR_LOG_TIMESTAMP_ABS);

    // initialize Climate Module and set update interval to 2500 ms
    twr_module_climate_init();
    twr_module_climate_set_event_handler(climate_event_handler, NULL);
    twr_module_climate_set_update_interval_all_sensors(2500);
}
