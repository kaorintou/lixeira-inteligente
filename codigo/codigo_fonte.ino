#include <LiquidCrystal.h>

// Inicializa o LCD (pinos RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Definição dos pinos do sensor ultrassônico
const int trigPin = 9; // Pino de disparo
const int echoPin = 10; // Pino de eco

// Altura da lixeira em cm
const float alturaLixeira = 30.0;

void setup() {
  // Inicializa o LCD
  lcd.begin(16, 2);
  
  // Configura os pinos do sensor ultrassônico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Exibe uma mensagem inicial
  lcd.print("Sistema Pronto");
  delay(2000); // Espera 2 segundos
}

void loop() {
  // Variável para armazenar a distância
  long duration;
  float distance;

  // Limpa o pino de disparo
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Envia um pulso de 10 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Lê o tempo de retorno do eco
  duration = pulseIn(echoPin, HIGH);
  
  // Calcula a distância em cm
  distance = duration * 0.034 / 2; // Velocidade do som é de 0.034 cm/us

  // Limpa o LCD
  lcd.clear();
  
  // Verifica a distância e calcula a porcentagem de preenchimento
  if (distance <= alturaLixeira) {
    float percentagem = (1 - (distance / alturaLixeira)) * 100;
    
    if (percentagem >= 85) { // Ajustado para 85%
      lcd.print("Lixeira Cheia");
    } else {
      lcd.print("Preench. : ");
      lcd.print((int)percentagem); // Exibe a porcentagem inteira
      lcd.print("%");
    }
  } else {
    lcd.print("Lixeira Vazia");
  }

  // Espera um segundo antes de medir novamente
  delay(1000);
}