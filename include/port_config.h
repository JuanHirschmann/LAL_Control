/**
 * @file port_config.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief Archivo de configuración para los puertos de la placa donde se implementará el sistema.
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef PORT_CONFIG_H
#define PORT_CONFIG_H

const int ONE_WIRE_BUS = 12; // D9 como digital in
const int BUTTON_PIN = 3;    // D3, tiene que corresponder a una interrupción externa
const int BUZZER_PIN = 8;    // D8, no necesita PWM

const int MOTOR_CONTROL_PIN = 2;
const int MOTOR_RED_LED_PIN = 10;   // D10
const int MOTOR_GREEN_LED_PIN = 11; // D11, Ambos con PWM

const int MOISTURE_SENSOR_PIN = A6;

const int FAN_2_STATE_RED_LED = A3;
const int FAN_2_STATE_GREEN_LED = A2;
const int FAN_1_STATE_RED_LED = A1;
const int FAN_1_STATE_GREEN_LED = A0;
#endif