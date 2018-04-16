  // put your setup code here, to run once:

int LED2=2; //se declara la salida del led 
int LED3=3; //se declara la salida del led 
int LED4=4; //se declara la salida del led 
int LED5=5; //se declara la salida del led 
int LED6=6; //se declara la salida del led 
int LED7=7; //se declara la salida del led 


void setup() {
pinMode(LED2, OUTPUT);//se declara que el led es de salida y no de entrada 
pinMode(LED3, OUTPUT);//se declara que el led es de salida y no de entrada 
pinMode(LED4, OUTPUT);//se declara que el led es de salida y no de entrada 
pinMode(LED5, OUTPUT);//se declara que el led es de salida y no de entrada 
pinMode(LED6, OUTPUT);//se declara que el led es de salida y no de entrada 
pinMode(LED7, OUTPUT);//se declara que el led es de salida y no de entrada 
Serial.begin(9600);
}

void loop() {
 delay(1000);
 digitalWrite(LED2, HIGH);//prende el led
  digitalWrite(LED3, HIGH);//prende el led
   digitalWrite(LED4, HIGH);//prende el led
    digitalWrite(LED5, HIGH);//prende el led
     digitalWrite(LED6, HIGH);//prende el led
      digitalWrite(LED7, HIGH);//prende el led
 

 delay(200);
   digitalWrite(LED2, LOW);//apaga el led
    digitalWrite(LED3, LOW);//apaga el led
     digitalWrite(LED4, LOW);//apaga el led
      digitalWrite(LED5, LOW);//apaga el led
       digitalWrite(LED6, LOW);//apaga el led
        digitalWrite(LED7, LOW);//apaga el led
        
 
  
}


