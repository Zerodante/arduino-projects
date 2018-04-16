#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
char ssid [] ="MUCHOPANCHO";
char pass [] ="elhuemul";



char valueStr[15];
String strtemp="";
char Temp[50];
int sensor=0;
DHT dht(sensor,DHT11);

unsigned long previousMillis=0;
char SERVER[50]= "34.249.42.33";
int SERVERPORT=16430;
String USERNAME ="sjrhbrea";
char PASSWORD[50]="dyJPwFNay0-R";

char PLACA[50];
char SALIDADIGITAL[50];
WiFiClient espClient;
PubSubClient client(espClient);
void callback (char* topic, byte*payload, unsigned int length){
  char PAYLOAD[5]="    ";
  Serial.print("Mensaje recibido:[");
  Serial.print(topic);
  Serial.print("]");
  for (int i=0; i<length; i++){
    PAYLOAD[i]=(char)payload[i];    
  }
  Serial.println(PAYLOAD);
  if(String(topic)==String(SALIDADIGITAL)){
    if(payload[1]=='N'){
      digitalWrite(2, HIGH);
    }
     if(payload[1]=='F'){
      digitalWrite(2, LOW);
    }
  }
}

void reconnect(){
  uint8_t retries=3;
  //loop hasta que conecte
  while(!client.connected()){
    Serial.print("intentando conexion");
    //creaos unID de cliente al azar
    String clientID="ESP8266Client-";
    clientID+= String(random(0xffff),HEX);
    //intenta conectarse
    USERNAME.toCharArray(PLACA,50);
    if(client.connect("",PLACA,PASSWORD)){
      Serial.println("conectado");
      client.subscribe(SALIDADIGITAL);
    } else{
      Serial.print("fallo, rc=");
      Serial.print(client.state());
      Serial.println("intentando nuevamente en 3 sec");
      delay(3000);
    }
    retries--;
    if(retries==0){
      while(1);
    }
  }
}
void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
dht.begin();
//inicia serial
Serial.begin(115200);
Serial.println("");

//conectar ala red
Serial.print("conectando...");
Serial.println(ssid);

WiFi.begin(ssid, pass);
 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
  client.setServer(SERVER, SERVERPORT);
  client.setCallback(callback);

  String salidadigital = "/"+USERNAME+ "/" + "salidadigital";
  salidadigital.toCharArray(SALIDADIGITAL,50);

  String temperatura = "/"+USERNAME+ "/" + "temperatura";
  temperatura.toCharArray(Temp,50);
}

void loop() {
  // put your main code here, to run repeatedly:
if (!client.connected()){
  reconnect();
}
  client.loop();
  unsigned long currentMillis=millis();
  if(currentMillis -previousMillis>=10000){
    previousMillis=currentMillis;
    float temp=dht.readTemperature();
    strtemp=String(temp, 1);
    strtemp.toCharArray(valueStr, 15);
    Serial.println("Enviando:["+String(Temp)+"]"+strtemp);
    client.publish(Temp, valueStr);
  }
}
