        /*DESCRIÇÃO;
 *leitura do microfone no A0 e de um potenciometro em A5
 *o pontiometro lê r que gera mn
 *mn é o mínimo de leitura necessária para considerar como palma (varia entre 260 e 330) 
 *(experimentalmente, para o circuito a baixo descri
 */


int som = 0;
int r = 0; /*potenciômetro experimental (de 0 a 1023)*/
long last=0;
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  som = analogRead(A0); /*A leitura do A0 ta em 332 com o circuito: 
                         (gnd) _ 10⁴oms _ A0 _ (lado reto do mic)_(lado curvo do mic) _ (5v)*/
  r = analogRead(A5);
  long mn = 260 + (70 * (long)r) / 1023; /*mn = valor minimo de A0 para palma */

  
  if(millis()-last > 500){
    Serial.print("mn=");
    Serial.println(mn);
    Serial.print("r =");
    Serial.println(r);
    Serial.println(".");
    last=millis();
  }
  
  if(som < mn){  /*um bom mínimo (mn) foi 287 (no alto do armário claro, virado para sudeste o microfone)*/
  digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
    
  }
   
}
