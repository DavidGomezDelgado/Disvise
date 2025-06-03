#include <Arduino.h>

#pragma once
extern const char* nombre_dispositivo;

extern volatile bool button1Pressed;
extern volatile bool button2Pressed;
//Control de rebote por software
extern volatile unsigned long lastDebounceTime;
const unsigned long debounceDelay = 50; // ms

RTC_DATA_ATTR extern int estado; //quiero mantener su valor despues del modo suspensión

RTC_DATA_ATTR extern int suspendedtime;

extern volatile int funcion;

//Variables para conexión Wifi:
extern const char* ssid;
extern const char* password;

extern const char* api_url;

//peticion api
extern const char* api_url;

extern int function;
extern char place[32];

extern unsigned long startMillis;
