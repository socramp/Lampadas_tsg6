#include "secrets.h"
#include <Arduino.h>

const char* WIFI_SSID = "SALA 09";
const char* WIFI_SENHA = "info@134";



//==============================
//MQTT
//==============================


const char* MQTT_BROKER  = "dce51b8abf75450cafe5cfeacd2d478b.s1.eu.hivemq.cloud";
const int MQTT_PORTA = 8883;

const char* MQTT_CLIENT_ID = "esp32_matheus_thomazini";

const char* MQTT_USUARIO = "Thomazini";
const char* MQTT_SENHA = "Senai@134";

const bool MQTT_TLS = true;

const char MQTT_CERTIFICADO_CA[] PROGMEM = "";


//==============================
//AWS
//==============================


const bool USAR_AWS_IOT = true;

const char* AWS_IOT_ENDPOINT = "a2f6egwqol151l-ats.iot.us-east-1.amazonaws.com"; //endereço do broker IoT Core

const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

const char AWS_CERT_CRT[] PROGMEM = R"CRT(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUcomQrHn+DoCPf5fb0GfNsX8NfScwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTI2MDUxODEzMTkw
M1oXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAK3sezW2EEk6DqYQLyok
ONX9M+fMQ5IaoWqDHcFT9A/i+9dDGxtzX/HUOQsVu8Vt+pC9ObM0nqWNlkm8z2rK
QDt3nLChkQq00mmXrMK9rqrokDLItNc+EmjxLiACYaUdd0iEykh3PyI4NYo/9Yc3
ZjEUQ0RPTf2ONHQm2G4w4RTNEdU6Yx7UUYkaCPlIEkiP3ns2kyI9NSJnCVtGpop/
zc1obLz/h+igOVgs59kTG6TEb6CYcmDHK0o+isuZrWDr9VvD16l/nMfQy/rwDY73
tTSL9ckXWATr6Fb0aoHWOkUVJ8CdYq939RBHmHYNjenaANKcDpjQaB5m+htuNg39
RWUCAwEAAaNgMF4wHwYDVR0jBBgwFoAUYajcfZRG63fzvPaFi4TN4btk6PYwHQYD
VR0OBBYEFKDW9ZiQfM+W3z+/RiQqtIFqBIwtMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQAWqBd2owNj8WKzLmSsqxmyxF/N
QCAWpIYTwZl6ck8j8cilrZYl8iXpWOOk+OYwo47qmFgFoHjJFpFmSk68TPaZka5j
4mtaIzklBi9KNj+AtL7KUdpic8r+MA3A4W06XrUw/PzuWvsfygfNuHg057iUytTR
pnZPf3OdtCGu5n5kuaq4kH1zJoYGU1Hvv8WNd1Rh2VD8yLyTUDpdM+cs1yw8BnUx
+VSlBjAyN5nHc7fF34qU5CoojdXz/F8Pl1OTNNBVShXZsl5KNhSN5vKnY+7evXpQ
YApjm1uxtioiZtyQuBmDBi0o9q/WbKrl4xabVej0P1uOxo/U9mOogHj3B1lG
-----END CERTIFICATE-----
)CRT";

const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEArex7NbYQSToOphAvKiQ41f0z58xDkhqhaoMdwVP0D+L710Mb
G3Nf8dQ5CxW7xW36kL05szSepY2WSbzPaspAO3ecsKGRCrTSaZeswr2uquiQMsi0
1z4SaPEuIAJhpR13SITKSHc/Ijg1ij/1hzdmMRRDRE9N/Y40dCbYbjDhFM0R1Tpj
HtRRiRoI+UgSSI/eezaTIj01ImcJW0amin/NzWhsvP+H6KA5WCzn2RMbpMRvoJhy
YMcrSj6Ky5mtYOv1W8PXqX+cx9DL+vANjve1NIv1yRdYBOvoVvRqgdY6RRUnwJ1i
r3f1EEeYdg2N6doA0pwOmNBoHmb6G242Df1FZQIDAQABAoIBACZtaYukflSvjy0B
xmn5NtWQ7Db62rMdTyzJa3mbowEflaUqHoMiKsCzsybP1nz4n7P7GxSNO8A4WExS
e0GNDkQVWXltOS60ZQkPigw8/KqmV7XgwpQMEuU85IQOAqUIraJINKluL3TQFoRF
PWpywxF0+KfPHdw33z8KlidChXiiuToRHHhPqLZ0R9v8ldprC7+LQlZ9p2HQ9Xh6
Ma9TMnv3wFATSsxc7+Q6AD3EXiC1wp/5fBrhGAG5iAr1LJzAEt3OiIZi8FgcsVdL
2Uu2XzpuKwi3/FzZY0fdIuuYqxWSRHV3Z3W1bKUm2qaxgXqNR+uFqoAZb7YDsu9c
OV3WngECgYEA3y9N8RcTmiajkFj3CxKftHtUqrvQsEmEXMA0HpoBefrBbpWyBf61
NKNyRMYJdp8mxYN+43IcrZgMs9sb/qoSfpykDZcunI8TkiKdNYB8D+aJ+7SJRjTH
yB1cQ7l9tvaOU+bN/ozifFOdM+drkze+biIqAnUhAUUPabVRXVip1skCgYEAx378
vIrKmUrBLfFsJsTF6C+QaDpLvkefyZMoaloznfNI3KLawG9MHCnySLNYWxoyZY6Z
xOJE43sB3IR7kYtYewby+8UsG79wZnfp4zzhSVtZSbqMSFJxoXnMk0Bco01xJuD0
gHkytRW1bacHGnJ7tMLf+n/VBvb7wUgknNgem70CgYBSVZAqXboEhzaV/Mv+ULuM
CGd+qNTfA/AJi3puw5/B0Sjk0+Kd5Y4Rwi5YgrphAWt7N/xqieFchRhCjZVxSGqU
PNMklF5EsV+l7JEUeLbL4t+KdNqjhLsi7vnnnhlrkt+EwkPCIVU4SlxXFouP/uOI
m5/l0jH/1utNsu82QYw+SQKBgB+kgbv6G7aCx+9cmrXvgiCY4sPVc0wkGjEj2UY9
NnC4NPdiEWZygNT6xkZHxBz3I8U+AB/db+XRDfOHQ/5K5ubkrEfI930TOWXXYU68
ylMTXS83mqaiBQoCwrMcg1UXpHnxNnbmQme8oMFau+KzA/Ig8tvNyOFI7ZeztLL4
CKrVAoGAdU5y4VsmtZ7PNcCHa4AdLw2/hcHx+7ckOeZdsRECD29dfPS97xEm45dY
c0o7kJ8A3iOss9B8hr42bFYXCdHhhbRLueRyw8X48VuzMjCbwRte6vCSAfcoq8e2
lMiM+MmPr/HJEql/enzt3KNBc8eryJcBdK43GdruJrc+XLbBdDw=
-----END RSA PRIVATE KEY-----
)KEY";

const int AWS_IOT_PORT = 8883;

const char* AWS_IOT_CLIENT_ID = "esp32matheus";


//==============================
//TOPICOS
//==============================


const char* TOPICOS_PUBLICAR[] = {
    "senai134/matheus/esp32/display",
    "senai134/esp32/log",
    "senai134/esp32/resposta"
};

const int TOTAL_TOPICOS_PUBLICAR = 3;

const char* TOPICOS_RECEBER[] = {
    "senai134/matheus/esp32/comando",
    "senai134/esp32/config",
    "senai134/esp32/display"
};

const int TOTAL_TOPICOS_RECEBER = 3;


//==============================
//DEBUG
//==============================

//0 - sem mensagens
//1 - apenas erros
//2 - todas as mensagens
const int DEBUG_NIVEL_INICIAL = 2;

const int PINO_HABILITA_DEBUG_COMPLETO = 4;



