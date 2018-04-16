int Motor1=9;
int Motor2=10;
int Motor3=11;
int estado;


void setup() {
  // put your setup code here, to run once:
pinMode(Motor1,OUTPUT);
pinMode(Motor2,OUTPUT);
pinMode(Motor3,OUTPUT);
digitalWrite(Motor3,HIGH);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available() > 0 ){
  estado=Serial.read();
 
  if (estado=='0'){
      digitalWrite(Motor1,LOW);
      digitalWrite(Motor2,LOW);
      Serial.println("Motor apagado");
         
    } else if(estado=='1'){
       digitalWrite(Motor1,LOW);
       digitalWrite(Motor2,HIGH);
       Serial.println("Motor encendido +") ;
          
    } else if(estado=='2'){
       digitalWrite(Motor1,HIGH);
       digitalWrite(Motor2,LOW);
       Serial.println("Motor encendido -");      
    }
  }
}
