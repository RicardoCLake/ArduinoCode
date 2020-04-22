//lê a frequencia de um piscar de led com um sensor de luz na entrada analógica do arduino 


int let = 0;
unsigned long time0 = 0;
int ok = 1;
unsigned long time1 = 0;

void setup() {
  
  Serial.begin(9600);
  

}

void loop() {
 let = analogRead(A0) ;
 
  if((ok) && (let > 100)){ 
    time0 = micros();
    ok = 0;
   }
   
  if((!ok) && (let < 100)){
    time1 = micros() - time0;
    ok = 1;
  }
   
  if(time1){

    Serial.println(time1);
    time1 = 0;
  }
 
 

}
