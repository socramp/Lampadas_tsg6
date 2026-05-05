#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>
#include <WiFiClientSecure.h>
#include "WiFiManager.h"
#include "MqttManager.h"
#include "DebugManager.h"

//*=====CONSTANTES=====
const int PinoLedRGB = 48;
const int PinoLedLampada = 45;
const int QntLeds = 1;
const char TOPICO_COMANDO[] = "senai134/matheus/esp32/comando";

//*=====INSTÂNCIAS=====
Adafruit_NeoPixel ledRGB(QntLeds, PinoLedRGB, NEO_GRB + NEO_KHZ800);


//*=====PROTÓTIPOS DE FUNÇÕES=====
void tratarMensagemRecebida(const char* topico, const String& mensagem);
void configurarLedRGB();
void alterarCorLedRGB(int vermelho, int verde, int azul);
void tratarJsonComando(const String& mensagem);


void setup() 
{
  pinMode(PinoLedLampada, OUTPUT);
  configurarDebug();
  conectarWiFi();
  configurarMQTT();
  registrarCallbackMensagem(tratarMensagemRecebida);
  conectarMQTT();
  configurarLedRGB();
}

void loop()
{
  garantirWiFiConectado();
  garantirMQTTConectado();
  loopMQTT();
}

void tratarMensagemRecebida(const char* topico, const String& mensagem)
{
    debugInfo("==============================");
    debugInfo("Mensagem recebida na aplicação");
    debugInfo("==============================");

    if(topico == nullptr)
    {
      debugErro("Tópico MQTT inválido.");
      return;
    }

    debugInfo("Tópico: " + String(topico));
    debugInfo("Mensagem: " + mensagem);

    if(strcmp(topico, TOPICO_COMANDO) == 0)
    {
      tratarJsonComando(mensagem);
      return;
    }

      debugErro("Tópico não tratado: " + String(topico));
}

void configurarLedRGB()
{
  ledRGB.begin();
  ledRGB.setBrightness(100);
  ledRGB.clear();
  ledRGB.show();

  debugInfo("LED RGB configurado no pino " + String(PinoLedRGB));
}

void alterarCorLedRGB(int vermelho, int verde, int azul)
{
    vermelho = constrain(vermelho, 0, 255);
    verde = constrain(verde, 0, 255);
    azul = constrain(azul, 0, 255);

    ledRGB.setPixelColor(0, ledRGB.Color(vermelho, verde, azul));
    ledRGB.show();

    debugInfo("Cor aplicada no LED RGB");
    debugInfo("R: " + String(vermelho));
    debugInfo("G: " + String(verde));
    debugInfo("B: " + String(azul));
}

void tratarJsonComando(const String& mensagem)
{
    JsonDocument doc;

    DeserializationError erro = deserializeJson(doc, mensagem);

    if(erro)
    {
      debugErro("Erro ao interpretar JSON");
      debugErro(erro.c_str());
      return;
    }
    
    
    if(!doc["lampada"].is<bool>())
    {
      debugInfo("Não encontrado o comando para Lâmpada");
    }

    else 
    {
      bool estadoLampada = doc["lampada"].as<bool>();
      digitalWrite(PinoLedLampada, estadoLampada);
    }


    if(!doc["led"].is<JsonObject>())
    {
      debugInfo("Não encontrado o comando para o LED RGB");
    }

    else
    {
      if(!doc["led"] ["r"].is<int>() ||
         !doc["led"] ["g"].is<int>() ||
         !doc["led"] ["b"].is<int>() )
         {
            debugErro("JSON inválido. Use led.r, led.g e led.b");
         }

      else
      {
        int vermelho = doc["led"] ["r"].as<int>();
        int verde = doc["led"] ["g"].as<int>();
        int azul = doc["led"] ["b"].as<int>();

        alterarCorLedRGB(vermelho, verde, azul);
      }
    }
}