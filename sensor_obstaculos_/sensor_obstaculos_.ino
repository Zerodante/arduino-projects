int obstaculos=12;
int led=8;
int valor;
int linea=3;
int valor2;


void setup() {
pinMode(obstaculos,INPUT);
pinMode(linea,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);  

}

void loop() {
valor=digitalRead(obstaculos);
valor2=digitalRead(linea);
Serial.println(valor);
Serial.println(valor2);
delay(1000);
if (valor==0||valor2==0){
  digitalWrite(led,1);
}else 
  digitalWrite(led,0);
 
}
