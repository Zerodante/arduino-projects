int buzzer=10;
int pin=12;
int foto=A0;
int v;


void setup() {
  pinMode(pin,OUTPUT);
  pinMode(buzzer,OUTPUT);
 
  Serial.begin(9600);

}

void loop() {
 v=analogRead(foto);
 if(v>=700){
  tone(buzzer,3000);
  digitalWrite(pin,1);
 }else{
  digitalWrite(pin,0);
  noTone(buzzer);
 }
 Serial.println(v);

}
