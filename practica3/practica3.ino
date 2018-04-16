int r=11;
int b=10;
int g=9;

int rs=A0;
int bs=A1;
int gs=A2;

int red=0;
int blue=0;
int green=0;
void setup() {
  // put your setup code here, to run once:
pinMode(r, OUTPUT);
pinMode(b, OUTPUT);
pinMode(g, OUTPUT);
Serial.begin(9600);
}

void loop() {
 red=analogRead(rs); delay(5);
 blue=analogRead(bs); delay(5);
 green=analogRead(gs); delay(5);

 Serial.print("valor rojo \t rojo");
 Serial.print(red);
 Serial.print("valor  \t azul");
 Serial.print(blue);
 Serial.print("valor  \t verde");
 Serial.print(green);
 Serial.println();


 analogWrite(r, red/4);
 analogWrite(b, blue/4);
 analogWrite(g, green/4);

}
