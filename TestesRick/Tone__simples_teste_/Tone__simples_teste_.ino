// tente simples da função tone


int c=523;
 int f=698;
 int fS=740;
 int g=784;
 int a=880;
 int Bb=932;
 int B=988;
 int C=1047;
 int D=1175;
 int DS=1245;
 int E=1319;
 int F=1397;
 int FS=1480;
 int G=1568;
 int A=1760;
 int BB=1976;
 int CC=2093;
 int DD=2349;
 int X=0;



void setup() {
  pinMode (7, OUTPUT);

}

void loop() {
  tone(7, C/2, 4000);
  delay(4000);
  noTone(7);
  delay(100);
  tone(7, D/2, 4000);
  delay(4000);
  noTone(7);
  delay(100);
  tone(7, E/2, 4000);
  delay(4000);
  noTone(7);
  delay(100);
  tone(7, F/2, 4000);
  delay(4000);
  noTone(7);
  delay(100);
  tone(7, G/2, 4000);
  delay(4000);
  noTone(7);
  delay(100);
  tone(7, A/2, 4000);
  delay(4000);
  noTone(7);
  delay(100);
  tone(7, BB/2, 4000);
  delay(4000);
  noTone(7);
  delay(100);
  tone(7, CC/2, 4000);
  delay(4000);
  noTone(7);
  delay(100);
  tone(7, C, 4000);
  delay(4000);
  noTone(7);
  delay(100);
  
  
}
