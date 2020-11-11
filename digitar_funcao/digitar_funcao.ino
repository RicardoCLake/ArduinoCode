//Funçõ que imita alguem digitar no lcd 

#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

void digitar(String p){
    int i;
    for(i=0; i<=p.length();i++) {
       lcd.print(p[i]);
       if(p[i]=='?'||p[i]=='!'||p[i]=='.')
            delay(500);
       else
            if(p[i]==',')
                delay(300);
            else
                delay(100);
        }
    delay(1000);
}

void proxima(){
   lcd.clear();
   delay(500);
}
    
void setup(){
    lcd.begin (16,2);
    digitar("Oi!");
    proxima();
    digitar("Eu sou um LCD,");
    lcd.setCursor(0,1);
    digitar("sabia?");
}
    
void loop(){
}     
