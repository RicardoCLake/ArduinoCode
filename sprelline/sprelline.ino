#include<LiquidCrystal.h>
#include<string.h>

long readUltrasonicMicros(int triggerPin, int echoPin);
int lerEscolha();

LiquidCrystal lcd(12,11,5,4,3,2);
#define BOTAO1 10
#define BOTAO2 9
#define BOTAO3 8
#define BOMBA 19
#define ECHO 14
#define TRIG 15

bool fixMode = false;
int duracao = 3000;
bool continua = true;
float distanciaMinima = 15.0;
float distanciaMedida;
int escolha;

void setup() {
  //Configurações do sistema
  lcd.begin (16,2);
  Serial.begin(9600);

  pinMode(BOTAO1, INPUT_PULLUP);
  pinMode(BOTAO2, INPUT_PULLUP);
  pinMode(BOTAO3, INPUT_PULLUP);
  
  pinMode(BOMBA, OUTPUT);
  digitalWrite(BOMBA, LOW);

  //Configuracoes do usuario
  while (continua) {
    lcd.clear();
    lcd.print("Selecione o Modo:");
    lcd.setCursor(0,1);
    lcd.print("FIXO  MOVEL");
    escolha = lerEscolha();
    if (escolha == 1) { 
    fixMode = true;
    continua = false;
    }
    if (escolha == 2) {
    fixMode = false;
    continua = false;
    }
    if (escolha == 3) continua = true;   
  }
   
  lcd.clear();
  lcd.print("Distancia Minima:");
  lcd.setCursor(0,1);
  lcd.print("7cm  15cm  25cm ");
  escolha = lerEscolha();
  if (escolha == 1) distanciaMinima = 7.0;
  if (escolha == 2) distanciaMinima = 15.0;
  if (escolha == 3) distanciaMinima = 25.0;

  if (fixMode) {
    lcd.clear();
    lcd.print("Duracao:"); 
    lcd.setCursor(0,1);
    lcd.print("1seg  3seg  5seg");
    escolha = lerEscolha();
    if (escolha == 1) duracao = 1000;
    if (escolha == 2) duracao = 3000;
    if (escolha == 3) duracao = 5000;   
  }
  
  lcd.clear();
  lcd.print("Higienize!");
}

void loop(){
  //Le as informacoes do sensor
  distanciaMedida = 0.01723 * readUltrasonicMicros(TRIG, ECHO);
  Serial.println(distanciaMedida);

  if (distanciaMedida <= distanciaMinima) {
    digitalWrite(BOMBA, HIGH);
    if (fixMode) { 
      delay(duracao);
      digitalWrite(BOMBA, LOW);
    }
  }
  else {
    digitalWrite(BOMBA, LOW);
  } 
}

int lerEscolha(){
  while (true){
    if (!digitalRead(BOTAO1)){
      delay(500);
      return 1;
    }
    if (!digitalRead(BOTAO2)){
      delay(500);
      return 2;
    }
    if (!digitalRead(BOTAO3)){
      delay(500);
      return 3;
    }
  }
}

long readUltrasonicMicros(int triggerPin, int echoPin)
{
  // Clear the trigger
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
