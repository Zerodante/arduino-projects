#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h> /* Esta libreria se utiliza para facilitar los comandos */

#define LED D0
#define LED2 D1
const char*  ssid= "USB_wifi";
const char* password = "bfca63ea5c";

String pagina = "<html>"
"<head>"
"<script>"
"var connection = new WebSocket('ws://'+location.hostname+':81/',['arduino']);"
"connection.onopen = function()       {connection.send('Connect ' + new Date()); };"
"connection.onerror = function(error) {console.log('WebSocket Error ',error);};"
"connection.onmessage = function(e)   {console.log('Server: ',e.data);};"
"function sendLED() {"
  "var led = parseInt(document.getElementById('led').value).toString(16);"
  "if(led,length < 2) { led='0' + led; }"
  "var ledfinal = '#'+led+'00'+'00';"
  "console.log('LedFinal: ' + ledfinal);"
  "connection.send(ledfinal);"
"}"
"function sendLED2() {"
  "var led2 = parseInt(document.getElementById('led2').value).toString(16);"
  "if(led2,length < 2) { led2='0' + led2; }"
  "var ledfinal2 = '#'+led2+'00'+'00';"
  "console.log('LedFinal2: ' + ledfinal2);"
  "connection.send(ledfinal2);"
"}"
"</script>"
"</head>"
"<body>"
"Panel de control para Leds:<br/></br/>"
"LED 1: <input id='led' type='range' min='0' max='255' step='1' value='0' oninput='sendLED();'/><br/>"
"LED 2: <input id='led2' type='range' min='0' max='255' step='1' value='0' oninput='sendLED2();'/><br/>"
"</body>"
"</html>";

ESP8266WebServer server = ESP8266WebServer(80);
WebSocketsServer webSocket = WebSocketsServer(81);


void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload,  size_t length)
{
  switch(type){
    case WStype_DISCONNECTED:
        Serial.printf("[%u] Desconectado!!!!!!\n", num);
        break;
    case WStype_CONNECTED: {
      IPAddress ip = webSocket.remoteIP(num);
      Serial.printf("[%u] Conectado desde %d.%d.%d.%d url: %s\n",num ,ip[0],ip[1],ip[2],ip[3], payload);

      webSocket.sendTXT(num, "Conectado");
    }
    break;
    case WStype_TEXT:
      Serial.printf("[%u] Obtener TEXT: %s\n",num,payload);

      if(payload[0] == '#')
      {
        uint32_t led =(uint32_t) strtol((const char *)&payload[1],NULL,16);
        analogWrite(LED, abs(255 - (led >> 16) & 0xFF));
        analogWrite(LED2, abs(255 - (led >> 16) & 0xFF));
      }
      break;
    
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  WiFi.mode(WIFI_STA); //Iniciar SoftAp en modo normal
  //Conectar a WiFi
  Serial.print("Conectado a .....");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectada");
  Serial.println(WiFi.localIP());
  pinMode(LED,OUTPUT);
  pinMode(LED2,OUTPUT);
  //WebSocket Server
  webSocket.begin();
  webSocket.onEvent (webSocketEvent);


  if(MDNS.begin("esp8266")){
    Serial.println("MDNS responder started");
  }
  //Index
  server.on("/",[](){
    server.send(200, "text/html",pagina);
  });

  server.begin();

  MDNS.addService("http","tcp",80);
  MDNS.addService("ws","tcp",81);

  digitalWrite(LED, 1); //1 = apagado
  digitalWrite(LED2,1);

  analogWriteRange(255);

}

void loop() {
  // put your main code here, to run repeatedly:
  webSocket.loop();
  server.handleClient();

}
