int pin=5;
int inclinacion=12;
int button=10;
int resistencia=A0;

int inc;
int valor;
int vres;
void setup() {
  pinMode(pin,OUTPUT);
  pinMode(inclinacion,INPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
  

}

void loop() {
  inc=digitalRead(inclinacion);
  valor=digitalRead(button);
  vres=analogRead(resistencia);
  
  Serial.println(inc);
  Serial.println(vres);
  delay(100);

  if(inc==HIGH&&valor==HIGH){
    digitalWrite(pin,HIGH);
    delay(1000);
    digitalWrite(pin,LOW);
  }
  
}
