#include "driver_ds18b20_basic.h"

int main(int argc, char **argv)
{

    uint8_t res;
    uint8_t i;
    float temperature;

    res = ds18b20_basic_init();
    if (res != 0)
    {
        return 1;
    }

    for (i = 0; i < 3; i++)
    {
        ds18b20_interface_delay_ms(2000);
        res = ds18b20_basic_read((float *)&temperature);
        if (res != 0)
        {
            (void)ds18b20_basic_deinit();

            return 1;
        }
        ds18b20_interface_debug_print("ds18b20: temperature is %0.2fC.\n", temperature);
    }

    (void)ds18b20_basic_deinit();

    return 0;
}
