const int LED = 2;   // GPIO2 para Wokwi

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);  // enciende
  delay(500);
  digitalWrite(LED, LOW);   // apaga
  delay(500);
}
