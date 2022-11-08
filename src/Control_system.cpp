#include "Control_system.h"

Control_system::Control_system(TwoWire *wire_interface)
{
    this->init_instructions();
    this->display = new Display_LCM2004; //(wire_interface);
    this->temp_sensor = new Temperature_sensor(ONE_WIRE_BUS);
    this->update_temperature.turn_on();
    this->display->set_fan_speed_pct(10);
}
void Control_system::init_instructions()
{
    const char *OPERATION_PROCEDURE[] = {
        "Paso 1",
        "Paso 2",
        "Paso 3",
        "Paso 4",
        "Paso 5",
        "Paso 6",
        "Paso 7",
        "FIN",
    };
    int n_rows = sizeof OPERATION_PROCEDURE / sizeof OPERATION_PROCEDURE[0];
    Instruction_node aux;
    for (int i = 0; i < n_rows; i++)
    {
        aux.set_text(OPERATION_PROCEDURE[i], strlen(OPERATION_PROCEDURE[i]));
        this->procedure_list.append(aux);
    }
}
void Control_system::update()
{
    this->display->set_text(procedure_list.get_current_instruction()->get_text());
    // this->display->set_fan_speed_pct();
    if (this->update_temperature.get_state())
    {

        this->display->set_temp(this->temp_sensor->get_reading());
        // this->update_temperature.turn_off();
    }
    if (this->show_next_step.get_state())
    {
        this->display->set_fan_speed_pct(10);
    }
    if (this->show_next_step.get_state())
    {
        this->procedure_list.next_instruction();
        this->show_next_step.turn_off();
    }
    this->display->update_display();
}

Control_system::~Control_system()
{
    delete this->display;
    delete this->temp_sensor;
}