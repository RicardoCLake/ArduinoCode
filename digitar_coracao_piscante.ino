#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

byte cora[8] = {B00000, B01010, B11111, B11111, B11111, B01110, B00100, B00000 };

byte cori[8] = {B00000, B00000, B00100, B01110, B01110, B00100, B00000, B00000};



void setup(){
     lcd.begin (16,2);
     lcd.createChar(4,cora);
     lcd.createChar(1,cori);
     lcd.print("Boa noite!");
            }
void loop(){
lcd.write(4);
delay(400);
lcd.clear();
lcd.print("Boa noite!");
lcd.write(1);
delay(200);
lcd.clear();
lcd.print("Boa noite!");
           }