#include <Keyboard.h>

int k1=2;
int k2=3;
int k3=4;
int k4=5;
int k5=6;
int k6=7;
int k7=8;
int k8=9;
int k9=10;
int led=11;
int v1,v2,v3,v4,v5;
int v6,v7,v8,v9,v10;


void setup() {
 pinMode(k1,INPUT);
 pinMode(k2,INPUT);
 pinMode(k3,INPUT);
 pinMode(k4,INPUT);
 pinMode(k5,INPUT);
 pinMode(k6,INPUT);
 pinMode(k7,INPUT);
 pinMode(k8,INPUT);
 pinMode(k9,INPUT);

 pinMode(led,OUTPUT);

}

void loop() {
   v1=digitalRead(k1);
   v2=digitalRead(k2);
   v3=digitalRead(k3);
   v4=digitalRead(k4);
   v5=digitalRead(k5);
   v6=digitalRead(k6);
   v7=digitalRead(k7);
   v8=digitalRead(k8);
   v9=digitalRead(k9);
  
  if(v1==1){
    Keyboard.write('1');
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }
  
  if(v2==1){
    Keyboard.write('2');
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }
  
  
  if(v3==1){
    Keyboard.write('3');
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }
  
  
  if(v4==1){
    Keyboard.write('4');
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }
  
  
  if(v5==1){
    Keyboard.write('5');
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }
  
  
  if(v6==1){
    Keyboard.write('6');
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }
  
  
  if(v7==1){
    Keyboard.write('7');
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }
  
  
  if(v8==1){
    Keyboard.write('8');
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }
  
  
  if(v9==1){
    Keyboard.write('9');
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }



 
}
