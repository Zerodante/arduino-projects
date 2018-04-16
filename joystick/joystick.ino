int xaxis=A0;
int yaxis=A1;
int zaxis=3;
int led1=9;
int led2=10;
int led3=11;
int led4=12;

void setup() {
  pinMode(xaxis,INPUT);
  pinMode(yaxis,INPUT);
  pinMode(zaxis,INPUT);
  Serial.begin(9600);

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);

}

void loop() {
 int x= analogRead(xaxis);
int y=  analogRead(yaxis);
int z=  digitalRead(zaxis);
Serial.println(x);
Serial.println(y);
Serial.println(z);


if (x==0&&y==0){
  digitalWrite(led1,1);
  digitalWrite(led2,0);
  digitalWrite(led3,0);
  digitalWrite(led4,0);
}

if (x==1023&&y<=600){
  digitalWrite(led1,0);
  digitalWrite(led2,0);
  digitalWrite(led3,1);
  digitalWrite(led4,0);

  
}else if (x==1023&&y==1023){
  digitalWrite(led1,0);
  digitalWrite(led2,0);
  digitalWrite(led3,0);
  digitalWrite(led4,1);
  
}else if (x<=600&&y==1023){
  digitalWrite(led1,0);
  digitalWrite(led2,1);
  digitalWrite(led3,0);
  digitalWrite(led4,0);

  
}else if (z==1){
  digitalWrite(led1,1);
  digitalWrite(led2,1);
  digitalWrite(led3,1);
  digitalWrite(led4,1);
}



}
