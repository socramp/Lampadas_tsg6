<div align="center">

# 💡 Sistema Inteligente de Controle de Lâmpadas

Controle de lâmpadas utilizando ESP32, interruptores físicos e comunicação MQTT.

![ESP32](https://img.shields.io/badge/ESP32-IoT-blue?style=for-the-badge)
![MQTT](https://img.shields.io/badge/MQTT-Communication-green?style=for-the-badge)
![Arduino](https://img.shields.io/badge/Arduino-C++-00979D?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-orange?style=for-the-badge)

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
- Fonte de alimentação

---

## 📐 Circuito

```markdown
<img width="895" height="807" alt="image" src="https://github.com/user-attachments/assets/1eafa29d-79fc-4eb0-8821-83d9dbe36a5e" />

```

---

## 🚀 Como Executar

### 1️⃣ Clonar o Repositório

```bash
git clone https://github.com/seu-usuario/seu-repositorio.git
```

### 2️⃣ Abrir no VS Code

Abra o arquivo do repositório na WorkSpace.

### 3️⃣ Configurar Wi-Fi

Edite as credenciais:

```cpp
const char* ssid = "SEU_WIFI";
const char* password = "SUA_SENHA";
```

### 4️⃣ Configurar MQTT

```cpp
const char* mqtt_server = "broker.hivemq.com";
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
