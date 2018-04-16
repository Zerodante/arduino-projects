int sensor;


int alto=0;
int bajo=1023;
int led=13;


void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
digitalWrite(led,HIGH);

while(millis()<=5000){
  sensor=analogRead(A0);
     if (sensor>alto){
     alto=sensor;
     }
     
     if  (sensor<bajo){
     sensor=bajo;  
      }
}
   
analogWrite(led, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensor=analogRead(A0);
  int pitch=map(sensor,bajo,alto,50,4000);
  tone(9,pitch,20);//a donde vamos, la frecuencia, duracion
  delay(10);
  
}
