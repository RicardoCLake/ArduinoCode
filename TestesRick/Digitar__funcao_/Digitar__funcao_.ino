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
            digitar("Oi!");
            proxima();
            digitar("Eu gosto de uma menina chamada maria, sabia?!");
            }
    
void loop(){
           }      
