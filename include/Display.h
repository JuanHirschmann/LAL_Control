#ifndef _DISPLAY_H
#define _DISPLAY_H
#include "Wire.h"
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include "utils.h"
#include "display_config.h"
enum display_symbols
{
    TEMP_SYMBOL = 0,
    NEG_TEMP_SYMBOL,
    FAN_SYMBOL,
};

class Display
{
public:
    void init();
    void print(char *string_out);
    void set_temp(float new_temperature);
    void set_fan_speed_pct(int new_speed_pct);
    void trigger_humidity_warning();
    void trigger_overtemp_warning();
    void trigger_overtemp_error();
    void set_text(const char string_out[]);
    void update();

private:
    hd44780_I2Cexp screen_interface; //(0x27, 20, 4);
    bool blink_temp_indicator = false;
    void update_temperature();
    void update_fan_speed();
    void update_text();
    char on_screen_text[MAX_CHAR_DISPLAY];
    /**
     * @brief Medición de temperatura visualizada en pantalla
     *
     */
    float on_screen_temp = 0.0;
    /**
     * @brief Velocidad del ventilador visualizada en pantalla. 100 es máxima velocidad, 0 es apagado.
     *
     */
    int on_screen_fan_speed_pct = 0; // Porcentaje de velocidad en el ventilador (100 es máximo, 0 es apagado)
};
#endif