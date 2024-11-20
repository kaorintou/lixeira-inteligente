#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h> // Inclua a biblioteca para conexões seguras

// Defina suas credenciais Wi-Fi
const char* ssid = "2G_THIAGO_PAULA";
const char* password = "paulathiago";

// Configurações do MQTT
const char* mqttServer = "b05beca6be804759848c6b9c2353faba.s1.eu.hivemq.cloud"; // URL do broker
const int mqttPort = 8883; // Porta para conexões seguras
const char* mqttTopic = "esp32/lixeira"; // Tópico para receber mensagens
const char* notificationTopic = "esp32/notificacao"; // Tópico para enviar notificações

// Credenciais do MQTT
const char* mqttUser = "kaorintou"; // Nome de usuário MQTT
const char* mqttPassword = "Meronpan@96"; // Senha MQTT

WiFiClientSecure espClient; // Use WiFiClientSecure para conexões seguras
PubSubClient client(espClient);

// Pinos do ESP32
const int sinalArduino = 1; // Pino que recebe sinal do Arduino
const int relePin = 21; // Pino que controla o relé

void setup() {
  // Inicializa o Serial Monitor
  Serial.begin(115200);

  // Configura os pinos
  pinMode(sinalArduino, INPUT); // Configura o pino de sinal como entrada
  pinMode(relePin, OUTPUT); // Configura o pino do relé como saída
  digitalWrite(relePin, LOW); // Garante que o relé comece desligado

  // Conecta ao Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }
  Serial.println("Conectado ao Wi-Fi!");

  // Configura o cliente MQTT
  espClient.setInsecure(); // Ignora a verificação de certificado para conexões inseguras
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback); // Define a função de callback para mensagens recebidas
}

void loop() {
  if (!client.connected()) {
    reconnect(); // Tenta reconectar se não estiver conectado
  }
  client.loop(); // Mantém a conexão MQTT ativa

  // Verifica se o sinal do Arduino está alto
  if (digitalRead(sinalArduino) == HIGH) {
    digitalWrite(relePin, HIGH); // Ativa o relé
    Serial.println("Relé ativado!");
  } else {
    digitalWrite(relePin, LOW); // Desativa o relé
  }
}

// Função de reconexão ao MQTT
void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    if (client.connect("ESP32Client", mqttUser, mqttPassword)) { // Insira suas credenciais MQTT
      Serial.println("conectado!");
      client.subscribe(mqttTopic); // Inscreve-se no tópico
    } else {
      Serial.print("Falha na conexão, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

// Função de callback chamada quando uma mensagem é recebida
void callback(char* topic, byte* message, unsigned int length) {
  String msg;
  for (int i = 0; i < length; i++) {
    msg += (char)message[i];
  }
  Serial.print("Mensagem recebida: ");
  Serial.println(msg);

  // Enviar notificação se a mensagem for "lixeira cheia"
  if (msg == "lixeira cheia") {
    String notification = "Notificação: A lixeira está cheia!";
    client.publish(notificationTopic, notification.c_str()); // Envia a notificação
    Serial.println("Notificação enviada: A lixeira está cheia!");
  }
}