#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <Arduino.h>
#include <PubSubClient.h>

#include "secrets.h"
#include "WiFiManager.h"
#include "MqttManager.h"
#include "DebugManager.h"

//* Criação de objetos

WiFiClient wifiCliente;
WiFiClientSecure wifiClientSecure;
PubSubClient mqttClient;

CallbackMensagemMQTT callbackDaAplicacao = nullptr;

void registrarCallbackMensagem(CallbackMensagemMQTT callback)
{
    callbackDaAplicacao = callback;

    if(callbackDaAplicacao != nullptr)
    {
        debugInfo("Callback da aplicação registrado com sucesso.");
    }

    else
    {
        debugErro("Callback da aplicação não foi registrado.");
    }
}

const char* obterTopicoPublicacao(int indiceTopico)
{
    if(indiceTopico < 0 || indiceTopico >= TOTAL_TOPICOS_PUBLICAR)
    {
        debugErro("Indice inválido para tópico de publicação: " + String (indiceTopico));
        return "";
    }
    return TOPICOS_PUBLICAR[indiceTopico];
}


const char* obterTopicoRecebimento(int indiceTopico)
{
    if(indiceTopico < 0 || indiceTopico >= TOTAL_TOPICOS_RECEBER)
    {
        debugErro("Indice inválido para tópico de recebimento: " + String (indiceTopico));
        return "";
    }
    return TOPICOS_RECEBER[indiceTopico];
}

void callbackInternoMQTT(char* topico, byte* payload, unsigned int tamanho)
{
    String mensagem = "";

    for( unsigned i = 0; i < tamanho; i++)
    {
        mensagem += (char)payload[i];
    }

    debugInfo("=======================");
    debugInfo(" Mensagem MQTT recebida");
    debugInfo("=======================");
    debugInfo("Tópico: " + String (topico));
    debugInfo("Mensagem: " + mensagem);

    if(callbackDaAplicacao != nullptr)
    {
        callbackDaAplicacao(topico, mensagem);
    }

    else
    {
        debugErro("Mensagem recebida, mas nenhum callback da aplicação foi registrado.");
    }
}

void configuraMQTT()
{
    debugInfo("=======================");
    debugInfo(" Configurando MQTT...");
    debugInfo("=======================");

    if(USAR_AWS_IOT)
    {
    //TODO: implementar codigo para usar broker IOT Core da AWS
    }

    else if (MQTT_TLS)
    {
    //TODO: implementar codigo para conectar ao broker com certificado TLS
    }

    else //Conectar ao broker publico sem certificado 
    {
        debugInfo("Modo selecionado: MQTT sem TLS.");

        mqttClient.setClient(wifiCliente);
        mqttClient.setServer(MQTT_BROKER, MQTT_PORTA);

        debugInfo("Broker MQTT: " + String (MQTT_BROKER));
        debugInfo("Porta MQTT: " + String (MQTT_PORTA));
    }

    mqttClient.setCallback(callbackInternoMQTT);
    debugInfo("Callback interno no MQTT configurado.");

}