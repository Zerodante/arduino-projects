#include<Servo.h>
Servo myservo;
int posicion = 90;
int valor;
int r=4;
int R =10;
int G=9;
int B=11;
int piezo=6;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(13);
  pinMode(r,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(piezo,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!Serial.available()){
    pinMode(R,HIGH);
    pinMode(piezo,HIGH);
  }
  while (Serial.available()) {
    valor = Serial.read();
    posicion = valor;
    myservo.write(posicion);
    delay(100);
  }
  if( posicion>150){
    digitalWrite(G,1);
    digitalWrite(B,0);
    digitalWrite(R,0);
    digitalWrite(r,0);
    pinMode(piezo,0);
    analogWrite(piezo,LOW);
  }else   if( posicion>=90){
    digitalWrite(G,0);
    digitalWrite(B,1);
    digitalWrite(R,0);
    digitalWrite(r,0);
    pinMode(piezo,0);
    analogWrite(piezo,LOW);
  }else   if (posicion<=90){
    digitalWrite(G,0);
    digitalWrite(B,0);
    digitalWrite(R,1);
    digitalWrite(r,1);
    analogWrite(piezo,HIGH);
  }
}
