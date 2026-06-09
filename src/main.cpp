#include <Arduino.h>
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>
#include <Preferences.h>

#include "WiFiManager.h"
#include "MqttManager.h"
#include "DebugManager.h"
#include "LED.h"

//*=====CONSTANTES====
const char TOPICO_COMANDO[] = "senai134/shared/projeto/lampadas";

//*=====VARIÁVEIS====
bool mensagemRecebidaMQTT = false;
bool estadoLampada1;
bool estadoLampada2;
bool estadoLampada3;
bool estadoLampada4;
bool cliqueBotao1;
bool cliqueBotao2;
bool cliqueBotao3;
bool cliqueBotao4;

//!----PIN LÂMPADAS----
int pinLampada1 = 38;
int pinLampada2 = 37;
int pinLampada3 = 36;
int pinLampada4 = 35;

//!----PIN BOTÕES----
int pinLBotao1 = 18;
int pinLBotao2 = 17;
int pinLBotao3 = 16;
int pinLBotao4 = 15;

//*=====INSTÂNCIAS=====
Preferences memoria;
Bounce botaoBoot = Bounce();
Bounce botaoInterruptor1 = Bounce();
Bounce botaoInterruptor2 = Bounce();
Bounce botaoInterruptor3 = Bounce();
Bounce botaoInterruptor4 = Bounce();
Led lampada1(pinLampada1);
Led lampada2(pinLampada2);
Led lampada3(pinLampada3);
Led lampada4(pinLampada4);

//*=====PROTÓTIPOS DE FUNÇÕES=====
void tratarMensagemRecebida(const char *topico, const String &mensagem);
void tratarJsonComando(const String &mensagem);
void tratarLampadaBotao();
void publicarRespostaMQTT();
void salvarEstadoLampadas();

void setup()
{
  botaoBoot.attach(0, INPUT_PULLUP);
  botaoInterruptor1.attach(pinLBotao1, INPUT_PULLUP);
  botaoInterruptor2.attach(pinLBotao2, INPUT_PULLUP);
  botaoInterruptor3.attach(pinLBotao3, INPUT_PULLUP);
  botaoInterruptor4.attach(pinLBotao4, INPUT_PULLUP);
  configurarDebug();
  conectarWiFi();

  configurarMQTT();
  conectarMQTT();
  registrarCallbackMensagem(tratarMensagemRecebida);
  memoria.begin("estadoLampadas", false);

  estadoLampada1 = memoria.getBool("lamp1", false);
  estadoLampada2 = memoria.getBool("lamp2", false);
  estadoLampada3 = memoria.getBool("lamp3", false);
  estadoLampada4 = memoria.getBool("lamp4", false);
}
void loop()
{
  garantirWiFiConectado();
  garantirMQTTConectado();
  loopMQTT();

  botaoBoot.update();
  botaoInterruptor1.update();
  botaoInterruptor2.update();
  botaoInterruptor3.update();
  botaoInterruptor4.update();

  cliqueBotao1 = botaoInterruptor1.fell();
  cliqueBotao2 = botaoInterruptor2.fell();
  cliqueBotao3 = botaoInterruptor3.fell();
  cliqueBotao4 = botaoInterruptor4.fell();

  tratarLampadaBotao();
  salvarEstadoLampadas();
  publicarRespostaMQTT();

  lampada1.setEstado(estadoLampada1);
  lampada1.update();
  lampada2.setEstado(estadoLampada2);
  lampada2.update();
  lampada3.setEstado(estadoLampada3);
  lampada3.update();
  lampada4.setEstado(estadoLampada4);
  lampada4.update();
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

  if (erro)
  {
    debugErro("Erro ao interpretar JSON");
    debugErro(erro.c_str());
    return;
  }

  if (!doc["lampada_1"].is<bool>() && !doc["lampada_2"].is<bool>() && !doc["lampada_3"].is<bool>() && !doc["lampada_4"].is<bool>())
  {
    debugInfo("Não encontrado o comando para nenhuma lâmpada");
  }
  else
  {
    if (doc["lampada_1"].is<bool>())
    {
      estadoLampada1 = doc["lampada_1"].as<bool>();
    }

    if (doc["lampada_2"].is<bool>())
    {
      estadoLampada2 = doc["lampada_2"].as<bool>();
    }

    if (doc["lampada_3"].is<bool>())
    {
      estadoLampada3 = doc["lampada_3"].as<bool>();
    }

    if (doc["lampada_4"].is<bool>())
    {
      estadoLampada4 = doc["lampada_4"].as<bool>();
    }
  }

  mensagemRecebidaMQTT = true;
}

void tratarLampadaBotao()
{
  if (botaoBoot.fell())
  {
    debugInfo("Botao pressionado");
    estadoLampada1 = !estadoLampada1;
  }

  if (cliqueBotao1)
  {
    estadoLampada1 = !estadoLampada1;
    debugInfo("Botao 1 pressionado. Estado da lâmpada 1: " + String(estadoLampada1));
  }

  if (cliqueBotao2)
  {
    estadoLampada2 = !estadoLampada2;
    debugInfo("Botao 2 pressionado. Estado da lâmpada 2: " + String(estadoLampada2));
  }

  if (cliqueBotao3)
  {
    estadoLampada3 = !estadoLampada3;
    debugInfo("Botao 3 pressionado. Estado da lâmpada 3: " + String(estadoLampada3));
  }

  if (cliqueBotao4)
  {
    estadoLampada4 = !estadoLampada4;
    debugInfo("Botao 4 pressionado. Estado da lâmpada 4: " + String(estadoLampada4));
  }
}

void publicarRespostaMQTT()
{
  if (cliqueBotao1 || cliqueBotao2 || cliqueBotao3 || cliqueBotao4)
  {

    JsonDocument doc;

    doc["evento"] = "Comando local recebido";

    JsonObject lampadas = doc["lampadas"].to<JsonObject>();
    lampadas["lampada_1"] = estadoLampada1;
    lampadas["lampada_2"] = estadoLampada2;
    lampadas["lampada_3"] = estadoLampada3;
    lampadas["lampada_4"] = estadoLampada4;

    String mensagem;
    serializeJson(doc, mensagem);

    publicarMensagemNoTopico(0, mensagem.c_str());
  }

  if (mensagemRecebidaMQTT)
  {

    JsonDocument doc;

    doc["evento"] = "MQTT recebido";

    JsonObject lampadas = doc["lampadas"].to<JsonObject>();
    lampadas["lampada_1"] = estadoLampada1;
    lampadas["lampada_2"] = estadoLampada2;
    lampadas["lampada_3"] = estadoLampada3;
    lampadas["lampada_4"] = estadoLampada4;

    String mensagem;
    serializeJson(doc, mensagem);

    publicarMensagemNoTopico(0, mensagem.c_str());
    publicarMensagemNoTopico(1, mensagem.c_str());
    mensagemRecebidaMQTT = false;
  }
}

void salvarEstadoLampadas()
{
  if (cliqueBotao1 || cliqueBotao2 || cliqueBotao3 || cliqueBotao4 || mensagemRecebidaMQTT)
  {
    memoria.putBool("lamp1", estadoLampada1);
    memoria.putBool("lamp2", estadoLampada2);
    memoria.putBool("lamp3", estadoLampada3);
    memoria.putBool("lamp4", estadoLampada4);
  }
}
