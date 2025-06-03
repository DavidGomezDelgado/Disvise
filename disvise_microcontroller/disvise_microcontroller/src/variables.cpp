#include "headers/variables.h"

const char* nombre_dispositivo = "display0";

volatile bool button1Pressed = false;
volatile bool button2Pressed = false;
volatile unsigned long lastDebounceTime = 0;

RTC_DATA_ATTR int estado = 0; // Tambiën se puede almacenar en RAM con RTC_DATA_ATTR para que su valor no sea afectado por deep_sleep

RTC_DATA_ATTR int suspendedtime = 5;

//const char* ssid = "Galaxy A34 5G EF7B";
//const char* password = "tsyaz45pxe522tf";

const char* ssid = "MIWIFI_RHhA";
const char* password = "Qf6hpdPY";

const char* api_url = "http://192.168.1.147:8080/";

int function = 0;
char place[32] = "";

unsigned long startMillis = 0;

