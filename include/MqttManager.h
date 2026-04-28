#ifndef MQTT_MANAGER_H
#define MQTT_MANAGER_H

#include <Arduino.h>

void configurarMQTT();
void conectarMQTT();
void garantirMQTTconectado();
void loopMQTT();

void publicarMensagem(const char* topico, const char* mensagem);

bool mqttEstaConectado();

const char* obterTopicoPublicacao();
const char* obterTopicoRecebimento();

typedef void (*CallbackMensagemMQTT)(const char* topico, const String&mensagem);

void registrarCallbackMensagem(CallbackMensagemMQTT callback);




#endif