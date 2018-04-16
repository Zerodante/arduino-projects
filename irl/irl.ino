#include <IRLremote.h>
int inter=0;
uint8_t prot =0;
uint16_t dir =0;
uint32_t tecla =0;
uint8_t Reg;
int emisor=3;
int pulse=11;
int pulse2=12;
int pulse3=13;
int pulse4=10;
int valor;
int valor2;
int valor3;
int valor4;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(pulse,INPUT);
pinMode(pulse2,INPUT);
pinMode(pulse3,INPUT);
pinMode(pulse4,INPUT);
 IRLbegin <IR_ALL>(inter);
}

void IREvent(uint8_t proto, uint16_t direct, uint32_t command)
{
  prot=proto;
  dir=direct;
  tecla=command;
}

void loop() {
  // put your main code here, to run repeatedly:
    Reg=SREG;
  cli(); //modificacion de registros. bloquea bit.

    Serial.print("protocolo:");
    Serial.println(prot);
    Serial.print("direccion:");
    Serial.println(dir, HEX);
    Serial.print("tecla:");
    Serial.println(tecla);
    
   

  valor=digitalRead(pulse);
   valor2=digitalRead(pulse2);
    valor3=digitalRead(pulse3);
     valor4=digitalRead(pulse4);
  if (valor==HIGH){
  uint16_t direccion=0xC686;
  uint32_t commando=0x7F80;
  IRLwrite(emisor,direccion,commando);
  Serial.println("enviado..........");
  delay(40);  
  }

   if (valor2==HIGH){
  uint16_t direccion=0xC686;
  uint32_t commando=0x7F81;
  IRLwrite(emisor,direccion,commando);
  Serial.println("enviado..........");
  delay(40);  
  }


   if (valor3==HIGH){
  uint16_t direccion=0xC686;
  uint32_t commando=0x7F82;
  IRLwrite(emisor,direccion,commando);
  Serial.println("enviado..........");
  delay(40);  
  }


   if (valor4==HIGH){
  uint16_t direccion=0xC686;
  uint32_t commando=0x7F89;
  IRLwrite(emisor,direccion,commando);
  Serial.println("enviado..........");
  delay(40);  
  }
  SREG=Reg;
}

