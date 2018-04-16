#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <DHT.h>


#define AIO_SERVER    "52.70.203.194"
#define AIO_SERVERPORT 1883
#define AIO_USERNAME  "zerodante"
#define AIO_KEY       "b9dd829375c440a28b4f493acdf76aee"

WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish temp = Adafruit_MQTT_Publish(&mqtt, "zerodante/feeds/temp");


 
const char *ssid="USB_wifi";
const char *pass="bfca63ea5c";

unsigned long previousMillis=0;

int sensor=2;
DHT dht(sensor,DHT11);

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.print("conectando a.......");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  while(WiFi.status() !=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println(""); 
  Serial.println("WiFi conectada");
  Serial.println(WiFi.localIP());
 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  MQTT_connect();

int long currentMillis=millis();
if (currentMillis - previousMillis >= 2000){
  previousMillis=currentMillis;
  float t =dht.readTemperature();
  Serial.print(F("\nEnviando valor"));
  Serial.print(t);
  Serial.print(".....");
  if(! temp.publish(t)){
    Serial.print(F("rechazado loser!!!!"));
  }else{
    Serial.println(F("Aceptado!!!!"));
  }
}
  
  mqtt.processPackets(500);
}

void MQTT_connect(){
  int8_t ret;

  if (mqtt.connected()){
    return;
  }

  Serial.print("conectando con MQTT...");
  uint8_t retries=3;
  while((ret=mqtt.connect())!=0){
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("intentando nuevamente....");
      mqtt.disconnect();
      delay(5000);
      retries--;
      if (retries==0){
        while(1);
      }
      Serial.println("conectado a MQTT!");
  }
  
}
