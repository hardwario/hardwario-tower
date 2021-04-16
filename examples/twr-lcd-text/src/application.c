/*
HARDWARIO TOWER - Indrustrial IoT Kit

Example firmware for basic usage of a LCD Module

With this example you will get some words onto the LCD Module in different fonts

For this example you will need:

- LCD Module                    https://shop.hardwario.com/lcd-module-bg/
- Core Module                   https://shop.hardwario.com/core-module/
- Mini Battery Module           https://shop.hardwario.com/mini-battery-module/
or you can buy LCD Display Kit  https://shop.hardwario.com/lcd-thermostat-kit/

For more information about firmware and HARDWARIO TOWER you can go to https://tower.hardwario.com/en/latest/firmware/basic-overview/
*/

#include <application.h>

#define BLACK true

/*
You will find this function in all of our firmwares
In it you will initialize all the modules and set the event handlers for them

This function will run once at the start

Event Hadlers - functions that is called in case of some event on the module (Button press, Button hold, Temperature update, etc.)
*/
void application_init(void)
{
    // Initialize LCD
    // The parameter is internal buffer in SDK, no need to define it
    twr_module_lcd_init();

    // Init default font, this is necessary
    // See other fonts in sdk/bcl/inc/twr_font_common.h
    twr_module_lcd_set_font(&twr_font_ubuntu_15);

    // Draw string at X, Y location
    twr_module_lcd_draw_string(10, 5, "Hello world!", BLACK);

    twr_module_lcd_draw_line(5, 20, 115, 20, BLACK);

    // Use big font
    twr_module_lcd_set_font(&twr_font_ubuntu_24);
    twr_module_lcd_draw_string(10, 40, "Big", BLACK);

    // Set back default font
    twr_module_lcd_set_font(&twr_font_ubuntu_15);
    twr_module_lcd_draw_string(60, 50, "world", BLACK);

    twr_module_lcd_draw_line(10, 65, 100, 75, BLACK);

    // Don't forget to update
    twr_module_lcd_update();
}
