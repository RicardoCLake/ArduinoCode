//leitura do microfone para calibrar os próximos programas da série "mic"

int som; //A0
int mn = 428; //queda minima em A0
int time0;
int espera = 150; //intervalo para digitar

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  som = analogRead(A0);
  if(millis()-time0>espera){
    time0 = millis();
   Serial.println (som);
  }
  if(som<mn){
    digitalWrite(13, !digitalRead (13));
    
  }
    
}
