#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "WiFiManager.h"


void setup() 
{
  Serial.begin(9600);
  conectarWiFi();
}

void loop()
{
  garantirWiFiConectado();
}
