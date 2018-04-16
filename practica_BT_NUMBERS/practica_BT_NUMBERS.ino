int pin1 =2;
int pin2=3;
int pin3=4;
int pin4=5;
int pin5=10;
int pin6=11;
int pin7=12;
int pin8=13;
char dato;



void setup() {
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  digitalWrite(pin3,0);
  pinMode(pin4,OUTPUT);
  pinMode(pin5,OUTPUT);
  pinMode(pin6,OUTPUT);
  pinMode(pin7,OUTPUT);
  pinMode(pin8,OUTPUT);
Serial.begin(9600);
}

void loop() {
  while(Serial.available()){
    dato=Serial.read();
    switch(dato){
      case '0':{
        digitalWrite(pin1,1);
        digitalWrite(pin2,1);
        digitalWrite(pin4,1);
        digitalWrite(pin5,1);
        digitalWrite(pin6,1);
        digitalWrite(pin7,1);
        digitalWrite(pin8,1);
        break;
        
      }
      case '1':{
        digitalWrite(pin1,1);
        digitalWrite(pin2,0);
        digitalWrite(pin4,1);
        digitalWrite(pin5,0);
        digitalWrite(pin6,0);
        digitalWrite(pin7,0);
        digitalWrite(pin8,0);
        break;
        
      }
      case '2':{
        digitalWrite(pin1,1);
        digitalWrite(pin2,1);
        digitalWrite(pin4,0);
        digitalWrite(pin5,1);
        digitalWrite(pin6,1);
        digitalWrite(pin7,1);
        digitalWrite(pin8,0);
        break;
        
      }
      case '3':{
        digitalWrite(pin1,1);
        digitalWrite(pin2,1);
        digitalWrite(pin4,1);
        digitalWrite(pin5,0);
        digitalWrite(pin6,1);
        digitalWrite(pin7,1);
        digitalWrite(pin8,0);
        break;
        
      }

      case '4':{
        digitalWrite(pin1,1);
        digitalWrite(pin2,0);
        digitalWrite(pin4,1);
        digitalWrite(pin5,0);
        digitalWrite(pin6,1);
        digitalWrite(pin7,1);
        digitalWrite(pin8,0);
        break;
        
      }

      case '5':{
        digitalWrite(pin1,0);
        digitalWrite(pin2,1);
        digitalWrite(pin4,1);
        digitalWrite(pin5,0);
        digitalWrite(pin6,1);
        digitalWrite(pin7,1);
        digitalWrite(pin8,1);
        break;
        
      }

      case '6':{
        digitalWrite(pin1,0);
        digitalWrite(pin2,1);
        digitalWrite(pin4,1);
        digitalWrite(pin5,1);
        digitalWrite(pin6,1);
        digitalWrite(pin7,1);
        digitalWrite(pin8,1);
        break;
        
      }

      case '7':{
        digitalWrite(pin1,1);
        digitalWrite(pin2,1);
        digitalWrite(pin4,1);
        digitalWrite(pin5,0);
        digitalWrite(pin6,0);
        digitalWrite(pin7,0);
        digitalWrite(pin8,0);
        break;
        
      }

      case '8':{
        digitalWrite(pin1,1);
        digitalWrite(pin2,1);
        digitalWrite(pin4,1);
        digitalWrite(pin5,1);
        digitalWrite(pin6,1);
        digitalWrite(pin7,1);
        digitalWrite(pin8,1);
        break;
        
      }

      case '9':{
        digitalWrite(pin1,1);
        digitalWrite(pin2,1);
        digitalWrite(pin4,1);
        digitalWrite(pin5,0);
        digitalWrite(pin6,1);
        digitalWrite(pin7,1);
        digitalWrite(pin8,1);
        break;
        
      }
      

      
    }
  }

}
