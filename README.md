<div align="center">

# 💡 Sistema Inteligente de Controle de Lâmpadas

Controle de lâmpadas utilizando ESP32, interruptores físicos e comunicação MQTT.

![ESP32](https://img.shields.io/badge/ESP32-IoT-blue?style=for-the-badge)
![MQTT](https://img.shields.io/badge/MQTT-Communication-orange?style=for-the-badge)
![Arduino](https://img.shields.io/badge/Arduino-C++-00979D?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Projeto%20Concluído-green?style=for-the-badge)

</div>

---

## 📖 Sobre o Projeto

Este projeto tem como objetivo desenvolver um sistema de automação residencial capaz de controlar **2 conjuntos de lâmpadas** por meio de:

- 🎛️ Interruptores físicos
- 📡 Comunicação MQTT
- 📶 Rede Wi-Fi
- 💻 ESP32

O sistema permite que as lâmpadas sejam acionadas localmente ou remotamente, mantendo o estado sincronizado entre os dispositivos.

---

## ✨ Funcionalidades

- ✅ Controle local através de interruptores
- ✅ Controle remoto via MQTT
- ✅ Monitoramento em tempo real
- ✅ Comunicação sem fio utilizando Wi-Fi
- ✅ Integração com servidores MQTT

---

## 🛠️ Tecnologias Utilizadas

| Tecnologia |         Descrição          |
|------------|----------------------------|
| ESP32      | Microcontrolador principal |
| MQTT       | Protocolo de comunicação   |
| Wi-Fi      | Comunicação de rede        |
| C++        | Linguagem de programação   |
| VS Code    | Software de programação    |

---

## 🔌 Componentes Utilizados

- 1x ESP32 DevKit
- 2x Conjuntos de lâmpadas LED
- 2x Interruptores
- 1x Protoboard
- 2x Módulo relé de estado sólido
- 1x Fonte de alimentação

---

## 📐 Circuito

<img width="895" height="807" alt="image" src="https://github.com/user-attachments/assets/1eafa29d-79fc-4eb0-8821-83d9dbe36a5e" />

---

## 🚀 Como Executar

### 1️⃣ Clonar o Repositório

```bash
git clone https://github.com/socramp/Lampadas_tsg6.git
```

### 2️⃣ Abrir no VS Code

Abra o arquivo do repositório na WorkSpace.

## ⚙️ Configuração Inicial

Antes de compilar o projeto, crie o arquivo `secrets.cpp` com base no arquivo de exemplo:

```bash
secrets.cpp.exemplo
```

Em seguida, preencha as credenciais de Wi-Fi e MQTT necessárias para o seu ambiente.


### 3️⃣ Configurar Wi-Fi

Edite as credenciais:

```cpp
const char* WIFI_SSID = "SEU_WIFI";
const char* WIFI_SENHA = "SUA_SENHA";
```

### 4️⃣ Configurar MQTT

Caso você queira utilizar MQTT Broker, você deve configurar:

```cpp
const char* MQTT_BROKER = "";
const int MQTT_PORTA = ;

const char* MQTT_CLIENT_ID = "";

const char* MQTT_USUARIO = "";
const char* MQTT_SENHA = "";

const bool MQTT_TLS = true/false;

const char MQTT_CERTIFICADO_CA[] PROGMEM = "";
```

Se você quiser usar AWS, você deve configurar:

```cpp
const bool USAR_AWS_IOT = true;
const char* AWS_IOT_ENDPOINT = "";

const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
CERTIFICADO CA
-----END CERTIFICATE-----
)EOF";

const char AWS_CERT_CRT[] PROGMEM = R"CRT(
-----BEGIN CERTIFICATE-----
CERTIFICADO CRT
-----END CERTIFICATE-----
)CRT";

const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
CHAVE PRIVADA
-----END RSA PRIVATE KEY-----
)KEY";

const int AWS_IOT_PORT = ;
const char* AWS_IOT_CLIENT_ID = "";
```

Você também precisa configurar os tópicos em você vai publicar e receber mensagens:

```cpp
const char* TOPICOS_PUBLICAR[] = {};
const int TOTAL_TOPICOS_PUBLICAR = ;

const char* TOPICOS_RECEBER[] = {};
const int TOTAL_TOPICOS_RECEBER = ;
```

Também é possível configurar o nível de debug:

```cpp
const int DEBUG_NIVEL_INICIAL = ;
//0 - sem mensagens
//1 - apenas erros
//2 - todas as mensagens
```

### 5️⃣ Enviar para o ESP32

Conecte o ESP32 ao computador e faça o upload do código.

---

## 📡 Fluxo de Funcionamento

```text
┌─────────────────┐      ┌─────────────────┐
│   Interruptor   │      │      MQTT       │
└────────┬────────┘      └────────┬────────┘
         │                        │
         └──────────┬─────────────┘
                    │
                    ▼
             ┌─────────────┐
             │    ESP32    │
             └──────┬──────┘
                    │
                    ▼
         ┌─────────────────────┐
         │   Aplicação / Web   │
         └─────────────────────┘
```

---

## 👨‍💻 Equipe

- Matheus Thomazini de Andrade
- Marcos Paulo da Silva Sousa
- Josane Oliveira Rocha
- Caynam Félix Oliveira
- Leandro Delavale Marçal
- Nicolas Rodrigo da Silva

---

## 📄 Licença

Este projeto é destinado para fins acadêmicos e educacionais.

---

<div align="center">

⭐ Se este projeto foi útil para você, considere deixar uma estrela no repositório!

</div>
