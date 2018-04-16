int pin = 3;
int shock =10;
int valor;
int piezo=11;
void setup() {
pinMode(pin,OUTPUT);
pinMode(shock,INPUT);
pinMode(piezo,OUTPUT);
}

void loop() {
  valor=digitalRead(shock);
  if (valor==HIGH){
    digitalWrite(pin,HIGH);
    digitalWrite(piezo,HIGH);
  }else{
    digitalWrite(pin,LOW);
    digitalWrite(piezo,LOW);
  }
}
