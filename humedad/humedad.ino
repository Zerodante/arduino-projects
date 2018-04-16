#include <DHT.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensor=7;
float T;
float hum;
DHT mydht (sensor,DHT11);

void setup() {
 lcd.begin(16, 2);
Serial.begin(9600);
mydht.begin();

}

void loop() {
  hum=mydht.readHumidity();
  T=mydht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("Temp");
  lcd.setCursor(7, 0);
  lcd.print(T);
  lcd.setCursor(11, 0);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humedad");
  lcd.setCursor(9, 1);
  lcd.print(hum);
   lcd.setCursor(14, 1);
   lcd.print("%");

   
  Serial.print("temperatura: ");
  Serial.println(T);
  Serial.print("Humedad:");
  Serial.println(hum);
  
}
