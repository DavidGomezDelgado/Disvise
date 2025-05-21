#include "headers/variables.h"

volatile bool button1Pressed = false;
volatile bool button2Pressed = false;
volatile unsigned long lastDebounceTime = 0;

RTC_DATA_ATTR int estado = 0; // Tambiën se puede almacenar en RAM con RTC_DATA_ATTR para que su valor no sea afectado por deep_sleep

RTC_DATA_ATTR int suspendedtime = 5;

const char* ssid = "";
const char* password = "";

const char* api_url = "";

int function = 0;
char place[32] = "";

unsigned long startMillis = 0;

