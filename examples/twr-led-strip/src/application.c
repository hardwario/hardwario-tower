/*
HARDWARIO TOWER - Indrustrial IoT Kit

Example firmware for basic usage of LED strip with Power Module

This example will change the LED strip effects button press

For this example you will need:

- Button Module                 https://shop.hardwario.com/button-module/
- Core Module                   https://shop.hardwario.com/core-module/
- Power Module                  https://shop.hardwario.com/power-module/
- Smart LED strip               https://shop.hardwario.com/led/

For more information about firmware and HARDWARIO TOWER you can go to https://tower.hardwario.com/en/latest/firmware/basic-overview/
*/

#include <application.h>

#define COUNT 144

twr_led_t led;
twr_led_strip_t led_strip;
uint32_t color;
int effect = -1;

static uint32_t _dma_buffer[COUNT * 4 * 2]; // count * type * 2

const twr_led_strip_buffer_t _led_strip_buffer =
{
    .type = TWR_LED_STRIP_TYPE_RGBW,
    .count = COUNT,
    .buffer = _dma_buffer
};

/*
This is and example of event handler for Button Module
The 'event' variable will store value of the event that happend on the module
You can simply react to the event with a simple if statement

Events on Button Module:
    - TWR_BUTTON_EVENT_CLICK
    - TWR_BUTTON_EVENT_HOLD
    - TWR_BUTTON_EVENT_PRESS
    - TWR_BUTTON_EVENT_RELEASE

Each button press will be detected and the effect will change accordingly to the current effect
This way you can check all the effects on LED strip

On a button hold the LED test will be started
This will run some simple tests to see if the strip is in good shape
*/
void button_event_handler(twr_button_t *self, twr_button_event_t event, void *event_param)
{
    (void) self;
    (void) event_param;

    if (event == TWR_BUTTON_EVENT_PRESS)
    {
        effect++;

        if (effect == 0)
        {
            twr_led_strip_effect_rainbow(&led_strip, 25);
        }
        else if (effect == 1)
        {
            twr_led_strip_effect_rainbow_cycle(&led_strip, 25);
        }
        else if (effect == 2)
        {
            color = 0xff000000;
            twr_led_strip_fill(&led_strip, 0x00000000);
            twr_led_strip_effect_color_wipe(&led_strip, color, 50);
        }
        else if (effect == 3)
        {
            twr_led_strip_effect_theater_chase(&led_strip, color, 45);
        }
        else if (effect == 4)
        {
            twr_led_strip_effect_theater_chase_rainbow(&led_strip, 45);
        }
        else if (effect == 5)
        {
            effect = -1;
            twr_led_strip_effect_stop(&led_strip);
            twr_led_strip_fill(&led_strip, 0x00000000);
            twr_led_strip_write(&led_strip);
        }
    }
    else if (event == TWR_BUTTON_EVENT_HOLD)
    {
        twr_led_strip_effect_test(&led_strip);
    }
}

/*
This is and example of event handler for LED strip
The 'event' variable will store value of the event that happend on the strip
You can simply react to the event with a simple if statement

Event on LED strip:
    - TWR_LED_STRIP_EVENT_EFFECT_DONE
*/
void led_strip_event_handler(twr_led_strip_t *self, twr_led_strip_event_t event, void *event_param)
{
    (void) event_param;

    if (event == TWR_LED_STRIP_EVENT_EFFECT_DONE)
    {
        if (effect == 2)
        {
            color >>= 8;
            if (color == 0x00000000)
            {
                color = 0xff000000;
            }
            twr_led_strip_effect_color_wipe(self, color, 50);
        }
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
    twr_led_init(&led, TWR_GPIO_LED, false, false);
    twr_led_set_mode(&led, TWR_LED_MODE_ON);

    static twr_button_t button;
    twr_button_init(&button, TWR_GPIO_BUTTON, TWR_GPIO_PULL_DOWN, false);
    twr_button_set_event_handler(&button, button_event_handler, NULL);

    twr_module_power_init();
    twr_led_strip_init(&led_strip, twr_module_power_get_led_strip_driver(), &_led_strip_buffer);
    twr_led_strip_set_event_handler(&led_strip, led_strip_event_handler, NULL);

    twr_led_strip_fill(&led_strip, 0x10000000);
    twr_led_strip_write(&led_strip);

    twr_led_set_mode(&led, TWR_LED_MODE_OFF);
}
