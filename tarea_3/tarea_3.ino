int sen=A0;
float baseline=20.0;

int red=10;
int green=11;
int blue=6;
void setup() {
  pinMode(red, OUTPUT);
   pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);

    Serial.begin(9600);
  

}

void loop() {
  int sensorv=analogRead(sen);
  float voltage = (sensorv/1024.0)*5.0;
  float temp = (voltage - .5)*100;

  Serial.println(temp);

  if (temp<baseline)
  {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }else
    if(temp>=baseline+2 && temp<=baseline+4)
{ digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  }else if(temp>=baseline+4 && temp<=baseline+6)
{ digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
}else if(temp>=baseline+6 && temp<=baseline+8)
{ digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  
  }else if(temp>=baseline+8)
{ digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
  }
}
