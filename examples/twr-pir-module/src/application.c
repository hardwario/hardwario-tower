/*
HARDWARIO TOWER - Indrustrial IoT Kit

Example firmware for basic usage of a PIR Module.

It will measure Iluminance every 1000 ms and print it out into the serial monitor

For this example you will need:

- PIR Module                        https://shop.hardwario.com/pir-module/
- Core Module                       https://shop.hardwario.com/core-module/
- Mini Battery Module               https://shop.hardwario.com/mini-battery-module/

For more information about firmware and HARDWARIO TOWER you can go to https://tower.hardwario.com/en/latest/firmware/basic-overview/
*/


#include <application.h>

// LED instance
twr_led_t led;

// PIR Module instance
twr_module_pir_t pir_module;

/*
This is and example of event handler for PIR Module
The 'event' variable will store value of the event that happend on the module
You can simply react to the event with a simple if statement

Events on LUX Meter Tag:
    - TWR_MODULE_PIR_EVENT_MOTION
    - TWR_MODULE_PIR_EVENT_ERROR
*/
void pir_module_event_handler(twr_module_pir_t *self, twr_module_pir_event_t event, void *event_param)
{
    (void) self;
    (void) event_param;

    // If event is motion...
    if (event == TWR_MODULE_PIR_EVENT_MOTION)
    {
        // Generate 1 second LED pulse
        twr_led_pulse(&led, 1000);
    }
    // If event is error...
    else if (event == TWR_MODULE_PIR_EVENT_ERROR)
    {
        // Indicate sensor error by LED blinking
        twr_led_set_mode(&led, TWR_LED_MODE_BLINK_FAST);
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
    // Initialize LED
    twr_led_init(&led, TWR_GPIO_LED, false, false);

    // Initialize PIR Module
    twr_module_pir_init(&pir_module);
    twr_module_pir_set_event_handler(&pir_module, pir_module_event_handler, NULL);
    twr_module_pir_set_sensitivity(&pir_module, TWR_MODULE_PIR_SENSITIVITY_MEDIUM);
}
