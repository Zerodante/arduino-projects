
#include <math.h>
int b=9;
int r=10;
int g=11;
int sensor=A5;
int valor;
double temp;
int buzz=3;

void setup() {
  pinMode(r,OUTPUT);
  pinMode (g,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);

}

void loop() {
 valor=analogRead(sensor);
 temp = log(10000.0*((1024.0/valor-1)));
  temp = 1 / (0.001129148 +(0.000234125 + (0.000000087676741 * temp * temp)) * temp);
  temp -= 330.95;
  Serial.println(temp);
 delay(1000);

 double t=temp;

   if (temp<=15){
    analogWrite(r,255);
    analogWrite(g,0);
    analogWrite(b,0);
     analogWrite(buzz,HIGH);
  
   }
  else if (temp>15&& temp<=25 ){
    analogWrite(r,0);
    analogWrite(g,255);
    analogWrite(b,0);
     analogWrite(buzz,LOW);
  
  }else if ( temp>25 ){
    analogWrite(r,0);
    analogWrite(g,0);
    analogWrite(b,255);
    analogWrite(buzz,LOW);
  }
}
