/*
HARDWARIO TOWER - Indrustrial IoT Kit

Example firmware for basic usage of a Button Module to switch the LED on and off

In this example the button press will toggle the LED located on the Core Module on and off

For this example you will need:

- Button Module                 https://shop.hardwario.com/button-module/
- Core Module                   https://shop.hardwario.com/core-module/
- Mini Battery Module           https://shop.hardwario.com/mini-battery-module/
or you can buy Push Button Kit  https://shop.hardwario.com/push-button-kit/

You can aslo just use the button on Core Module

For more information about firmware and HARDWARIO TOWER you can go to https://tower.hardwario.com/en/latest/firmware/basic-overview/
*/

#include <application.h>

// LED instance
twr_led_t led;

// Button instance
twr_button_t button;

/*
This is and example of event handler for Button Module
The 'event' variable will store value of the event that happend on the module
You can simply react to the event with a simple if statement

Events on Button Module:
    - TWR_BUTTON_EVENT_CLICK
    - TWR_BUTTON_EVENT_HOLD
    - TWR_BUTTON_EVENT_PRESS
    - TWR_BUTTON_EVENT_RELEASE
*/
void button_event_handler(twr_button_t *self, twr_button_event_t event, void *event_param)
{
    (void) self;
    (void) event_param;

    if (event == TWR_BUTTON_EVENT_PRESS)
    {
        twr_led_set_mode(&led, TWR_LED_MODE_TOGGLE);
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
    twr_led_set_mode(&led, TWR_LED_MODE_ON);

    // Initialize button
    twr_button_init(&button, TWR_GPIO_BUTTON, TWR_GPIO_PULL_DOWN, false);
    twr_button_set_event_handler(&button, button_event_handler, NULL);
}
