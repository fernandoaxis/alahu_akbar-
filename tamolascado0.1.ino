/*
  Programa: LED com Sensor PIR + LED com Botão
  Ajustado para qualquer tipo de PIR
*/

// Pinos
int sensor = 3;       // PIR
int botao = 4;        // Botão
int ledBotao = 5;     // LED controlado pelo botão
int ledSensor = 7;    // LED controlado pelo sensor

// Variáveis
bool ledEstado = false;  
int botaoAnterior = HIGH;  

void setup() {
  pinMode(sensor, INPUT);
  pinMode(botao, INPUT_PULLUP);   // Botão com resistor pull-up interno
  pinMode(ledSensor, OUTPUT);
  pinMode(ledBotao, OUTPUT);
  Serial.begin(9600);

  Serial.println("Aguarde 30s para o PIR calibrar...");
}

void loop() {
  // ----- LED do Sensor PIR -----
  int leituraSensor = digitalRead(sensor);
  Serial.println(leituraSensor); // Mostra valores no Serial Monitor (0 ou 1)

  // Se mudar de estado, acende o LED (funciona p/ PIR ativo em HIGH ou LOW)
  if (leituraSensor == HIGH) {   
    digitalWrite(ledSensor, HIGH);
  } else {
    digitalWrite(ledSensor, LOW);
  }

  // ----- LED do Botão -----
  int estadoBotao = digitalRead(botao);

  if (estadoBotao == LOW && botaoAnterior == HIGH) { 
    ledEstado = !ledEstado;  // Alterna estado do LED
    digitalWrite(ledBotao, ledEstado ? HIGH : LOW);
    delay(200); // debounce simples
  }

  botaoAnterior = estadoBotao;

  delay(10); 
}