int shock =2;
int g=9;
int b=11;
int r=10;

int microfono=4;
int analog=A0;

void setup() {
  // put your setup code here, to run once:
pinMode(r,OUTPUT);
pinMode(g,OUTPUT);
pinMode(b,OUTPUT);
pinMode(shock,INPUT);
pinMode(microfono,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int valor =digitalRead(shock);
  int valor2 =digitalRead(microfono);
  int valor3=analogRead(analog);
  if (valor==HIGH){
    digitalWrite(r,1);
    digitalWrite(b,0);
    digitalWrite(g,0);    
  } else{
     digitalWrite(r,0);
    digitalWrite(b,0);
    digitalWrite(g,0);  
  }
 if (valor3 >30){
    digitalWrite(r,0);
    digitalWrite(b,1);
    digitalWrite(g,0);
 }else{
   digitalWrite(b,0);
 }
Serial.println(valor);
Serial.println(valor2);
Serial.println(valor3);
delay(1000);
}
