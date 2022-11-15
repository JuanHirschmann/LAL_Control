#include "Display.h"
Display::Display()
{
    // No inicializar objecto de interfaz de pantalla en el constructor.
}
void Display::print(char *string_out)
{
    this->screen_interface.print(string_out);
}
void Display::init()
{

    this->screen_interface.begin(20, 4);
    // this->screen_interface.createChar(0, TEMP_SYMBOL_CHARACTER);
    this->screen_interface.setCursor(TEMP_INDICATOR_CURSOR_OFFSET[0], TEMP_INDICATOR_CURSOR_OFFSET[1]);
    // this->screen_interface.print('\000');
}
void Display::set_temp(float new_temp)
{
    if (this->on_screen_temp != new_temp)
    {

        this->on_screen_temp = new_temp;
        this->update_needed = true;
    }
}
void Display::set_fan_speed_pct(int new_speed_pct)
{
    if (this->on_screen_fan_speed_pct != new_speed_pct)
    {
        this->on_screen_fan_speed_pct = new_speed_pct;
        this->update_needed = true;
    }
}
void Display::set_text(const char *string_out)
{
    if (strncmp(string_out, this->on_screen_text, MAX_DISPLAY_STRING_LENGTH) != 0)
    {
        strncpy(this->on_screen_text, string_out, MAX_DISPLAY_STRING_LENGTH);
        this->update_needed = true;
    }
}
void Display::update()
{
    if (this->update_needed)
    {
        this->screen_interface.clear();
        this->screen_interface.home();
        this->screen_interface.print(this->on_screen_text);
        this->screen_interface.setCursor(TEMP_INDICATOR_CURSOR_OFFSET[0], TEMP_INDICATOR_CURSOR_OFFSET[1]);
        this->screen_interface.print(this->on_screen_temp, 1);
        this->screen_interface.setCursor(FAN_INDICATOR_CURSOR_OFFSET[0], FAN_INDICATOR_CURSOR_OFFSET[1]);
        this->screen_interface.print(this->on_screen_fan_speed_pct);
        this->update_needed = false;
    }
}