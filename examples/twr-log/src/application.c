/*
HARDWARIO TOWER - Indrustrial IoT Kit

Example firmware that shows all thy possibilities of serial monitor output

For this example you will need just the Core Module https://shop.hardwario.com/core-module/

For more information about firmware and HARDWARIO TOWER you can go to https://tower.hardwario.com/en/latest/firmware/basic-overview/
*/

#include <application.h>

/*
You will find this function in all of our firmwares
In it you will initialize all the modules and set the event handlers for them

This function will run once at the start

Event Hadlers - functions that is called in case of some event on the module (Button press, Button hold, Temperature update, etc.)
*/
void application_init(void)
{
    twr_log_init(TWR_LOG_LEVEL_DUMP, TWR_LOG_TIMESTAMP_ABS);

    twr_log_debug("Initialize twr_log by calling twr_log_init(TWR_LOG_LEVEL_DEBUG, TWR_LOG_TIMESTAMP_ABS);");
    twr_log_debug("twr_log functions can use also %%s %%d and others formatting parameters.");

    twr_log_debug("Debug output using %s", "twr_log_debug()");
    twr_log_info("Info output using twr_log_info()");
    twr_log_warning("Warning output using twr_log_warning()");
    twr_log_error("Error output using twr_log_error()");

    uint8_t buffer[15];

    for (size_t i = 0; i < sizeof(buffer); i++)
    {
        buffer[i] = i;
    }

    twr_log_dump(buffer, sizeof(buffer), "Dump output using twr_log_dump()");

    char *demo = "Dump String DEMO";

    twr_log_dump(demo, strlen(demo) + 1, "Dump output using twr_log_dump()");
}
