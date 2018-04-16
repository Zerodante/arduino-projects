#include <Servo.h>
Servo myServo;
int angle;

int sen=A0;
int red=6;
int green=5;
int blue=3;
float baseline=20.0;
int note[]={240,300,};
void setup() {
 pinMode(red, OUTPUT);
   pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
  myServo.attach(9);
    Serial.begin(9600);

}

void loop() {
 
 
int sensorv=analogRead(sen);
  float voltage = (sensorv/1024.0)*5.0;
  float temp = (voltage - .5)*100 ;
  Serial.println(temp);
angle=map(temp,0,1023,0,179);
delay(15);

   if (temp < baseline){
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    tone(8,note[0]);
    myServo.write(12);
    
  }else if(temp >= baseline && temp <= baseline+8){
    digitalWrite(red, LOW);  
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    myServo.write(90);
    
  }else if(temp > baseline+8){ 
    digitalWrite(red, HIGH);  
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    tone(8,note[1]);
    myServo.write(150);
  }
}
