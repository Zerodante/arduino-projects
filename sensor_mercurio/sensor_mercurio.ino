int red=9;
int blue=11;
int green=10;
int incl=3;

//sensor de llama

int ignis=4;
int ignea=A3;

void setup() {
  // put your setup code here, to run once:
pinMode(red,OUTPUT);
pinMode(blue,OUTPUT);
pinMode(green,OUTPUT);
pinMode(incl,INPUT);
pinMode(ignea,INPUT);
pinMode(ignea,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int valor=digitalRead(incl);

float sensor=analogRead(ignea);
Serial.println(sensor);

int valor2=digitalRead(ignis);

if(valor==HIGH || valor2==HIGH){
 digitalWrite(red,1); 
 digitalWrite(blue,1); 
 digitalWrite(green,1); 
 }else{
  digitalWrite(red,0); 
 digitalWrite(blue,0); 
 digitalWrite(green,0); 
 }
}
