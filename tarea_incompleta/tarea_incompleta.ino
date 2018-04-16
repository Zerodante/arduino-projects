#include <Servo.h>
Servo myservo;

int piezo=A0;
int pin=2;
int pin1=3;
int pin2=4;
int pin3=5;

int knock;
int swi;
int quiet=10;
int loud=100;
boolean locked=false;
int num=0;


void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
pinMode(pin2,OUTPUT);
pinMode(pin3,OUTPUT);
pinMode(pin4,OUTPUT);
pinMode(pin,INPUT);
Serial.begin
}

void loop() {
  // put your main code here, to run repeatedly:

}
