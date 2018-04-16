int pinReceptor = A5; //Establecemos el pin a leer
int sensorVal; //Declaramos una variable para almacenar el valor de la lectura
 
void setup(){
Serial.begin(9600); // Abrimos comunicación Serial
}
 
void loop(){
sensorVal = analogRead(pinReceptor); //Guardamos la lectura del pin Analógico
float metros=sensorVal*0.0254;
Serial.println(sensorVal); //Sacamos la lectura por serial
delay(500);  //Pequeña pausa de medio segundo
}
