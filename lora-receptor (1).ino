#include <SoftwareSerial.h>
#include  <HCSR04.h>

#define LEDV 4
#define LEDA 6  
SoftwareSerial loraSerial(2, 3); // TX, RX

void setup() { 
   
  pinMode(LEDV, OUTPUT); // led vermelho 
  pinMode(LEDA, OUTPUT); // led Azul

  Serial.begin(9600);  
  loraSerial.begin(9600);  
  }
  
void loop() { 
    
  if(loraSerial.available() > 1){    
    String input = loraSerial.readString();    
    Serial.println(input);      
      if(input == "water") {      
        digitalWrite(LEDA, HIGH);
        digitalWrite(LEDV, LOW);
      } 
      if(input == "no_water") {      
        digitalWrite(LEDA, LOW);
        digitalWrite(LEDV, HIGH);      
      }  
   }   delay(20);
   
  String input = loraSerial.readString();    
  Serial.println(input);      
     if(input == "distance");
     loraSerial.print("distance");
     delay (500);

   
}

