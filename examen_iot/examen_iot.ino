#include <ESP8266WiFi.h>


const char* ssid = "USB_wifi";
const char* password = "bfca63ea5c";
int fotores = 0;
int led =2;
const char* server = "184.106.153.149";
String apiKey = "GRVZODHQP5HUR4CH";



void setup() {
  Serial.begin(115200);
  Serial.println("");

  //sensor de luz
  pinMode(fotores, INPUT);
  pinMode(led,OUTPUT);

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
    int luz = digitalRead(fotores);
    enviarTemp(luz);
    if (luz !=0){
      digitalWrite(led,1);
    }else{
      digitalWrite(led,0);
    }
    Serial.println(luz);
}

  void enviarTemp(int luz){
    
    WiFiClient client;

    if(client.connect(server, 80)){
      //Serial.println("cliente WiFi conectado");
      String postStr=apiKey;
      postStr += "&field1=";
      postStr += String(luz);
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

