#include <Servo.h>

Servo newservo;//crecion de objeto
int potenciometro = A0;
int pot;
int angulo;


void setup() {
  Serial.begin(9600);
  newservo.attach(9);

}

void loop() {
 pot=analogRead(potenciometro);
 Serial.println(pot);
 angulo=map(pot,0,1023,0,179);
 Serial.println(angulo);

 newservo.write(angulo);
 delay(15);
 

}
