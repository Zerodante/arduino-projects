#include <CapacitiveSensor.h>
/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cap = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
int pin=12;
int thresh=1000;

void setup()                    
{
 
   Serial.begin(9600);
     pinMode(pin,OUTPUT);
}

void loop()                    
{
    long sensorvalue = cap.capacitiveSensor(30);
    Serial.println(sensorvalue);

    if(sensorvalue>thresh){
      digitalWrite(pin,HIGH);
    }else{digitalWrite(pin,LOW);
    }
    delay(10);
}
