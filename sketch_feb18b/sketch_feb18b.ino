int notas[]={247,277,330,392};
//frecuencias de las notas

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int key=analogRead(A0);
Serial.print(key);
if(key==1023){
   tone(9,notas[0]);
  
  
  } else if (key >=990 && key<=1010){
     tone(9, notas[1]);
  

   } else if (key >=505 && key<=515){
     tone(9,notas[2]);
  8

   } else if (key >=5 && key<=10){
     tone(9,notas[3]);
  

   } else{
    noTone(9);
   }

}
