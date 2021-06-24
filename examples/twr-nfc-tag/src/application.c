/*
HARDWARIO TOWER - Indrustrial IoT Kit

Example firmware for basic usage of a NFC Tag.

It will measure Iluminance every 1000 ms and print it out into the serial monitor

For this example you will need:

- NFC Tag                           https://shop.hardwario.com/nfc-tag/
- Core Module                       https://shop.hardwario.com/core-module/
- Mini Battery Module               https://shop.hardwario.com/mini-battery-module/

For more information about firmware and HARDWARIO TOWER you can go to https://tower.hardwario.com/en/latest/firmware/basic-overview/
*/

#include <application.h>

// led instance
twr_led_t led;

// nfc tag instance
twr_tag_nfc_t tag_nfc;

/*
You will find this function in all of our firmwares
In it you will initialize all the modules and set the event handlers for them

This function will run once at the start
*/
void application_init(void)
{
    twr_led_init(&led, TWR_GPIO_LED, false, false);

    twr_log_init(TWR_LOG_LEVEL_DEBUG, TWR_LOG_TIMESTAMP_ABS);
    twr_log_info("twr_tag_nfc_init");

    if (twr_tag_nfc_init(&tag_nfc, TWR_I2C_I2C0, TWR_TAG_NFC_I2C_ADDRESS_DEFAULT))
    {
        twr_log_info("ok");
    }
    else
    {
        twr_log_error("error");
    }

    twr_tag_nfc_ndef_t ndef;

    // NFC tag functions
    twr_tag_nfc_ndef_init(&ndef);
    twr_tag_nfc_ndef_add_text(&ndef, "HARDWARIO home page", "en");
    twr_tag_nfc_ndef_add_uri(&ndef, "https://www.hardwario.com/");
    twr_tag_nfc_ndef_add_text(&ndef, "Documentation", "en");
    twr_tag_nfc_ndef_add_uri(&ndef, "https://developers.hardwario.com/");

    twr_log_info("twr_tag_nfc_memory_write_ndef");

    if (twr_tag_nfc_memory_write_ndef(&tag_nfc, &ndef))
    {
        twr_log_info("ok");
    }
    else
    {
        twr_log_error("error");
    }

    twr_led_pulse(&led, 2000);
}
