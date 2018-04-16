#include <SoftwareSerial.h>
SoftwareSerial BT1(10, 11); //tx rx
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
BT1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BT1.available());{
  char a= BT1.read();
  Serial.print(a); 
  }
  if (Serial.available()){
    char a= Serial.read();
    BT1.print(a);
  }
}
