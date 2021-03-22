#include "application.h"


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

void application_init(void)
{
    // initialize log
    twr_log_init(TWR_LOG_LEVEL_DEBUG, TWR_LOG_TIMESTAMP_ABS);

    // initialize Climate Module and set update interval to 2500 ms
    twr_module_climate_init();
    twr_module_climate_set_event_handler(climate_event_handler, NULL);
    twr_module_climate_set_update_interval_all_sensors(2500);
}
