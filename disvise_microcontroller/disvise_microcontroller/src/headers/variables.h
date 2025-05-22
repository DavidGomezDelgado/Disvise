#include <Arduino.h>

#pragma once

extern volatile bool button1Pressed;
extern volatile bool button2Pressed;
//Control de rebote por software
extern volatile unsigned long lastDebounceTime;
const unsigned long debounceDelay = 50; // ms

RTC_DATA_ATTR extern int estado; //quiero mantener su valor despues del modo suspensión

RTC_DATA_ATTR extern int suspendedtime;

extern volatile int funcion;

//Variables para conexión Wifi:
//const char* ssid = "Galaxy A34 5G EF7B";
//const char* password = "tsyaz45pxe522tf";

const char* ssid = "MIWIFI_RHhA";
const char* password = "Qf6hpdPY";

const char* api_url = "http://192.168.1.138:8080/";

//peticion api
extern const char* api_url;

extern int function;
extern char place[32];

extern unsigned long startMillis;