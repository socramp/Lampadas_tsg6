#include <Arduino.h>
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>

#include "WiFiManager.h"
#include "MqttManager.h"
#include "DebugManager.h"
#include "LED.h"

//*=====CONSTANTES====
const char TOPICO_COMANDO[] = "senai134/sala09/grupo6/teste";

//*=====VARIÁVEIS====
bool estadoLampada1;
bool estadoLampada2;

//*=====INSTÂNCIAS=====
Bounce botaoBoot = Bounce();
Bounce botaoInterruptor1 = Bounce();
Bounce botaoInterruptor2 = Bounce();
Led lampada1(45);
Led lampada2(40);

//*=====PROTÓTIPOS DE FUNÇÕES=====
void tratarMensagemRecebida(const char *topico, const String &mensagem);
void tratarJsonComando(const String &mensagem);
void tratarLampadaBotao();
void publicarMensagemMQTT();

void setup()
{
  botaoBoot.attach(0, INPUT_PULLUP);
  botaoInterruptor1.attach(10, INPUT_PULLUP);
  botaoInterruptor2.attach(5, INPUT_PULLUP);
  configurarDebug();
  conectarWiFi();
  configurarMQTT();
  registrarCallbackMensagem(tratarMensagemRecebida);
  conectarMQTT();
}

void loop()
{
  publicarMensagemMQTT();
  garantirWiFiConectado();
  garantirMQTTConectado();
  loopMQTT();

  botaoBoot.update();
  botaoInterruptor1.update();
  botaoInterruptor2.update();

  tratarLampadaBotao();

  lampada1.setEstado(estadoLampada1);
  lampada1.update();
  lampada2.setEstado(estadoLampada2);
  lampada2.update();
}

void tratarMensagemRecebida(const char *topico, const String &mensagem)
{
  debugInfo("==============================");
  debugInfo("Mensagem recebida na aplicação");
  debugInfo("==============================");

  if (topico == nullptr)
  {
    debugErro("Tópico MQTT inválido.");
    return;
  }

  debugInfo("Tópico: " + String(topico));
  debugInfo("Mensagem: " + mensagem);

  if (strcmp(topico, TOPICO_COMANDO) == 0)
  {
    tratarJsonComando(mensagem);
    return;
  }

  debugErro("Tópico não tratado: " + String(topico));
}

void tratarJsonComando(const String &mensagem)
{
  JsonDocument doc;

  DeserializationError erro = deserializeJson(doc, mensagem);

  if (doc["lampada1"].is<bool>())
  {
    estadoLampada1 = doc["lampada1"].as<bool>();
  }

  if (doc["lampada2"].is<bool>())
  {
    estadoLampada2 = doc["lampada2"].as<bool>();
  }
}

void tratarLampadaBotao()
{
  if (botaoBoot.fell())
  {
    debugInfo("Botao pressionado");
    estadoLampada1 = !estadoLampada1;
  }

  if (botaoInterruptor1.fell())
  {
    debugInfo("Botao 1 pressionado. Estado da lâmpada1: " + String(estadoLampada1));
    estadoLampada1 = !estadoLampada1;
  }

  if (botaoInterruptor2.fell())
  {
    debugInfo("Botao 2 pressionado. Estado da lâmpada2: " + String(estadoLampada2));
    estadoLampada2 = !estadoLampada2;
  }
}

void publicarMensagemMQTT()
{
  if(botaoInterruptor1.fell() || botaoInterruptor2.fell())
  {
    
    String mensagem = "MQTT recebido\n"
                      "Estado das lâmpadas:\n"
                      "Lâmpada 1: " + String(estadoLampada1) + "\n"
                      "Lâmpada 2: " + String(estadoLampada2);

    publicarMensagemNoTopico(0, mensagem.c_str());
  }
}