void digitar(String p){
    int i;
    for(i=0; i<=p.length();i++) {
       Serial.print(p[i]);
       if(p[i]=='?'||p[i]=='!'||p[i]=='.'){
            delay(500);
            Serial.print('\n');
       }
       else
            if(p[i]==',')
                delay(300);
            else
                delay(100);
        }
    delay(1000);
    }
//importei essa função de quando criei para lcd (digitar_função.ino)

void setup() {
  Serial.begin(9600);
  
  digitar("...");
  Serial.print("Giselle: ");
  digitar("Já é de noite?");
  
  Serial.print('\n');

  Serial.println("(s para SIM");
  delay(800);
  Serial.println(" n para NAO)");

  String resp;

  //esse for é para esperar até sair uma resposta valida
  for(int i=0; i!=1;){
    if (Serial.available() > 0){
      resp = Serial.readString();
      Serial.print('\n');
      Serial.print("Você: ");
      delay(500);
      digitar(resp);
      Serial.print('\n');
      
      i=1;
    }
  }
  
  
  //esse for é para esperar até sair uma resposta valida
  for(int x=0;x!=1;){
    if(resp =="s\n"||resp == "S\n" ){
      Serial.print("Giselle: ");
      delay(500);
      digitar("Então, Boa noite!");
      x=1;
    }
      else {
        if(resp == "n\n"||resp == "N\n" ){
          Serial.print("Giselle: ");
          delay(500);
          digitar("Então, até mais tarde!");
          x=1;
        }
          else{
            Serial.print("Giselle: ");
            delay(500);
            digitar("Não entendi o que você disse.         Pode repetir, por favor?");

            //mesmo for de leitura
            for(int i=0; i!=1;){
              if (Serial.available() > 0){
              resp = Serial.readString();
              Serial.print('\n');
              Serial.print("Você: ");
              delay(500);
              digitar(resp);
              Serial.print('\n');
              i=1;
              }
            }
          }
      }
  }
}

void loop() {
}
