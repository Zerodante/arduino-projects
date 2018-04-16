int led=9;
int led1=8;
int i;
int sw=12;
int on=LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(sw,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  on=digitalRead(sw);
  
    if(on==LOW){
       digitalWrite(led1,LOW);
       digitalWrite(led,LOW);
    }
  
    if(on==HIGH){
       digitalWrite(led1,HIGH);
       delay(40);
       digitalWrite(led,HIGH);
    }
    
  /*digitalWrite(sw,
digitalWrite(led,HIGH);
delay(50);
digitalWrite(led,LOW);
delay(20);
digitalWrite(led1,HIGH);
delay(100);
digitalWrite(led1,LOW);
delay(40);*/
  
   
}
