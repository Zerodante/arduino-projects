#include <CayenneMQTTESP8266.h>

#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial


char ssid [] ="USB_wifi";
char pass [] ="bfca63ea5c";
char MQTT_USERNAME [] ="d944ffa0-c8d0-11e7-98e1-8369df76aa6d";
char MQTT_PASSWORD []= "2e75c416e60b9ba0dd4435e266e9ae4616311410";
char CLIENT_ID[]= "7dba2240-c8d1-11e7-9dee-31f7eb7d04a2";


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Cayenne.begin(MQTT_USERNAME, MQTT_PASSWORD, CLIENT_ID, ssid, pass);
pinMode(2,OUTPUT);
analogWrite(2,1023);

}

void loop() {
  // put your main code here, to run repeatedly:
Cayenne.loop();
}

CAYENNE_IN(0){
  analogWrite(2,getValue.asInt());
}


