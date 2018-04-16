int led=4;
int sen=3;
int HZ;
int lz;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(sen,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
HZ=digitalRead(sen);
Serial.println(HZ);
lz=analogRead(sen);
Serial.println(lz);
delay(500);
if ( lz <= 392 ) 
  {                         
    digitalWrite(led,0) ;          
    delay (100);
  }else if ( lz >= 393 ){                         
    digitalWrite(led,1) ;          
    delay (100);
  }
}
