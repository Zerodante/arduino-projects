#include <ESP8266WiFi.h>
#include <DHT.h>

const char* ssid = "USB_wifi";
const char* password = "bfca63ea5c";

unsigned long previousMILLIS = 0;
int sensor = 2;

const char* server = "184.106.153.149";
String apiKey = "WFTYH5ER2H63DM2O";

DHT dht(sensor, DHT11);

void setup() {
  Serial.begin(115200);
  Serial.println("");

  //sensor de temperatura
  dht.begin();

  //conectar a la red wifi
  Serial.print("conectando a.....");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectada");
  Serial.println(WiFi.localIP());
}

void loop() {
  unsigned long currentMILLIS = millis();
  if (currentMILLIS - previousMILLIS >= 10000) {
    previousMILLIS = currentMILLIS;
    float temperatura = dht.readTemperature();
    enviarTemp(temperatura);
  }
}

  void enviarTemp(float temperatura){
    
    WiFiClient client;

    if(client.connect(server, 80)){
      Serial.println("cliente WiFi conectado");
      String postStr=apiKey;
      postStr += "&field1=";
      postStr += String(temperatura);
      postStr += "\r\n\r\n";

      client.print("POST /update HTTP/1.1\n");
      client.print("Host:api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY:"+apiKey+"\n");
      client.print("Content-Type:application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);
      delay(1000);
    }

          client.stop();
}


