#include <Servo.h>//se llama a la libreria del servo motor
#include <LiquidCrystal.h> //Se llama a la libreria de la pantalla lcd 16x2
LiquidCrystal lcd(13, 12, 5, 4, 3, 2); //se declara la variable lcd como pantalla y se dan sus puertos de salida
Servo moto;// Declaramos que moto sera un servo motor
float sensor =A0; //aqui guardamos el valor del sensor
int LED=8; //se declara la salida del led 

void setup()
{
   
  lcd.begin(16, 2);  //se declara las filas y columnas de la pantalla (16x2)
  moto.attach(9);//Se declara que el servo saldra por el pic 9
pinMode(LED, OUTPUT);//se declara que el led es de salida y no de entrada 
Serial.begin(9600);
}
 
void loop()
{  

float volts = analogRead(sensor); //Leemos A0 y almacenamos su valor
 float dist = pow(3027.4 / volts, 1.2134); //convertimos a CM
  lcd.setCursor(1,0); //En la pantalla se ubicara en la 1 columna fila 0  
 lcd.print("Proyect zero");//imprimira la distancia en cm 
Serial.println(dist); //Escribimos dist en el monitor serie
 
if(dist <20) { //es una condicion para decir si la distancia es menor a 20 cm
  lcd.setCursor(0,1); //En la pantalla se ubicara en la 0 columna fila 1 
  lcd.print("Wilkommen");//Se imprime un bienvenido en aleman
  moto.write(179);//pone el servo a 179 grados
  digitalWrite(LED, HIGH);//prende el led

  }else{ 
  
  lcd.setCursor(0,1);//En la pantalla se ubicara en la 0 columna fila 1 
  lcd.print("peace out!");//Se imprime un adios en aleman
  moto.write(0);//pone el servo a 179 grados
  digitalWrite(LED, LOW);//apaga el led
  }

}
 
