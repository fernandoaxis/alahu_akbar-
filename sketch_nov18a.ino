#define BLYNK_TEMPLATE_ID "TMPL2EyA5WxxR"
#define BLYNK_TEMPLATE_NAME "COMANDANDO LEDS"
#define BLYNK_AUTH_TOKEN "SAdGUhynzfGCRK7HsoQ-a3iw75qHJDgd"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid [] =  "biblioteca";
char pass [] = "academico";

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);

}

BLYNK_WRITE(V0){
  int pinValue = param.asInt();
  digitalWrite(13, pinValue);
}
BLYNK_WRITE(V1){
  int pinValue = param.asInt();
  digitalWrite(12, pinValue);
}
BLYNK_WRITE(V2){
  int pinValue = param.asInt();
  digitalWrite(14, pinValue);
}
BLYNK_WRITE(V3){
  int pinValue = param.asInt();
  digitalWrite(26, pinValue);
}
BLYNK_WRITE(V4){
  int pinValue = param.asInt();
  digitalWrite(27, pinValue);
}

void loop() {
  Blynk.run();
}