#include <IRLremote.h>
int inter=0;
uint8_t prot =0;
uint16_t dir =0;
uint32_t tecla =0;
int laser=10;
uint8_t Reg;
void setup() {
  // put your setup code here, to run once:
  pinMode(laser,OUTPUT);
  IRLbegin <IR_ALL>(inter);
  Serial.begin(115200);
}
void IREvent(uint8_t proto, uint16_t direct, uint32_t command)
{
  prot=proto;
  dir=direct;
  tecla=command;
}
void loop() {
  Reg=SREG;
  cli(); //modificacion de registros. bloquea bit.
  if(prot!=0){
    Serial.print("protocolo:");
    Serial.println(prot);
    Serial.print("direccion:");
    Serial.println(dir, HEX);
    Serial.print("tecla:");
    Serial.println(tecla);
    
    prot=0;
  }
 SREG=Reg;
digitalWrite(laser,1);
}
