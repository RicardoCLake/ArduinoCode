//leitura do botao para calibrar os próximos programas da série "mic"

int aperto;
int time0;
int espera = 100; //intervalo para digitar

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(16, INPUT_PULLUP);
}

void loop() {
  aperto = digitalRead(16);
  if(millis()-time0>espera){
    time0 = millis();
   Serial.println (aperto);
  }
  if(!aperto){
    digitalWrite(13, !digitalRead (13));
  }
    
}
