int red=6;
int green=5;
int blue=3;

int pot=A0;
int val;
void setup() {
 pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
   pinMode(blue, OUTPUT);

}

void loop() {
  val=analogRead(pot);

  analogWrite(red, val);
  analogWrite(green, val/3);
  analogWrite(red, val/2);
  
}
