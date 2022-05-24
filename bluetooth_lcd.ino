#include "Wire.h" 
#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#include<SPI.h>
#include<MFRC522.h>
int Opc='C';
int pin8 = 8;
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the default I2C bus address of the backpack-see article
void setup()
{  
  Serial.begin(9600);
   SPI.begin(); 
   lcd.begin (16,2); // 16 x 2 LCD module
   lcd.setBacklightPin(3,POSITIVE); // BL, BL_POL
   lcd.setBacklight(HIGH);
   lcd.setCursor(0,0);
   lcd.print("");

}
void loop()
{
    if(Serial.available()>0){
    Opc = Serial.read();
   Serial.println(Opc);

    switch(Opc){
      case 'P': lcd.setCursor(4,0); lcd.print("Boton 1"); break;
      case 'A': lcd.setCursor(4,0); lcd.print("Boton 2"); break;
      case 'D': lcd.setCursor(4,0); lcd.print("Boton 3");  break;
      
      default: 
      digitalWrite(pin8,HIGH); delay(2000); digitalWrite(pin8,LOW);
      break;
      
      
      }
    }   
  } 
