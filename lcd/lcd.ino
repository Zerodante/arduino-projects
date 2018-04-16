#include <LiquidCrystal.h>
//crea objeto liquido
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

int pin=6;
int sstate=0;
int prev=0;
int respuesta;
void setup() {
  // put your setup code here, to run once:
lcd.begin (16,2);
pinMode(pin,INPUT);

lcd.print("normal");
lcd.setCursor(0, 1);
lcd.print("hola");

}

void loop() {
  // put your main code here, to run repeatedly:
sstate=digitalRead(pin);

if(sstate==prev){
  if(sstate==LOW){
   
  respuesta=random();
  lcd.setCursor(0,0);
  lcd.print("omni spe auferte");
  lcd.setCursor(0,1);
  
    switch(respuesta){
    case 0:
    lcd.print("suerte a la proxima");
    break;
  
    case 1:
    lcd.print("changos");
    break;
  
    case 2:
    lcd.print("no habra clase");
    break;
  
    case 3:
    lcd.print("#ppcdsalvc");
    break;
  
    case 4:
    lcd.print("fierro pariente!");
    break;
  
    case 5:
    lcd.print("estas reprobado!!");
    break;
  
    case 6:
    lcd.print("moriras pronto");
    break;
  
    case 7:
    lcd.print("omni spe auferte");
    break;
    }
   }
  }

prev=sstate;
}
