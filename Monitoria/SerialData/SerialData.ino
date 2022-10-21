String sinais; // Variável usada para enviar os sinais
int leitura;  // Armazena a tensão medida

void setup() {
  Serial.begin(9600); // Inicia comunicação serial   
  pinMode(A1, INPUT);  
}

void loop() {
  leitura = analogRead(A1);
  // Escreve os valores de interesse entre "|"
  sinais = "|" + String(micros()) + "|" + String(leitura) + "|";
  Serial.println(sinais); // Imprime os dados no monitor serial
  delay(100); // Aguarda 100 ms
}
