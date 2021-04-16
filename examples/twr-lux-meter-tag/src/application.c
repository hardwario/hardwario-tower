/*
HARDWARIO TOWER - Indrustrial IoT Kit

Example firmware for basic usage of a LUX Meter Tag.

It will measure Iluminance every 1000 ms and print it out into the serial monitor

For this example you will need:

- LUX Meter Tag                     https://shop.hardwario.com/climate-module/
- Core Module                       https://shop.hardwario.com/core-module/
- Mini Battery Module               https://shop.hardwario.com/mini-battery-module/

For more information about firmware and HARDWARIO TOWER you can go to https://tower.hardwario.com/en/latest/firmware/basic-overview/
*/

#include "application.h"

// lux meter instance
twr_opt3001_t lux;

// error message to display when error occures during lux tag update (e.g. when disconnected
// Core module
#define LUXMETER_ERROR_MSG "Error"

/*
This is and example of event handler for LUX Meter Tag
The 'event' variable will store value of the event that happend on the module
You can simply react to the event with a simple if statement

Events on LUX Meter Tag:
    - TWR_TAG_LUX_METER_EVENT_UPDATE
    - TWR_TAG_LUX_METER_EVENT_ERROR
*/
void lux_module_event_handler(twr_opt3001_t *self, twr_opt3001_event_t event, void *event_param) {
    (void) event_param;
    float illumination = 0.0;

    if (event == TWR_TAG_LUX_METER_EVENT_UPDATE)
    {
        twr_tag_lux_meter_get_illuminance_lux(self, &illumination);
        twr_log_debug("%012.5f", illumination);
    }
    else
    {
        twr_log_debug(LUXMETER_ERROR_MSG);
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
    // initialize logging and lux meter tag
    twr_log_init(TWR_LOG_LEVEL_DEBUG, TWR_LOG_TIMESTAMP_ABS);
    twr_tag_lux_meter_init(&lux, TWR_I2C_I2C0, 0x44);

    // set update interval
    twr_tag_lux_meter_set_update_interval(&lux, 1000);

    // set evend handler (what to do when tag update is triggered)
    twr_tag_lux_meter_set_event_handler(&lux, lux_module_event_handler, NULL);
}
