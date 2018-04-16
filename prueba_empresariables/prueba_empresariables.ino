#include <SoftwareSerial.h>

SoftwareSerial ESPserial(2,3);





const char *ssid="USB_wifi";
const char *pass="bfca63ea5c";

void setup() {
 
  Serial.begin(115200);
  ESPserial.begin(115200);
  
}

void loop() {
 
 SoftwareSerial.print(Serial.readString());


  }
  

