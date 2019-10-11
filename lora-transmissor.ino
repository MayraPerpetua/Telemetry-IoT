#include <SoftwareSerial.h>
#include  <HCSR04.h>

SoftwareSerial loraSerial(2, 3); // TX, RX
String water = "water";
String no_water = "no_water";

// Initialize sensor that uses digital pins 13 and 12.
int triggerPin = 13;
int echoPin = 12;
UltraSonicDistanceSensor distanceSensor (triggerPin, echoPin);


void setup() {  
  
  Serial.begin(9600);  
  loraSerial.begin(9600);
  
}

void loop() {  

  float estado = analogRead (A5);
  Serial.println(estado);
  delay(10);

  if(estado > 300) {    
  loraSerial.print(water);    
  while(analogRead(A5) > 300);    
  delay(50);  
  }  
  else if(estado <= 200) {    
  loraSerial.print(no_water);    
  while(analogRead(A5) <= 200);    
  delay(50); 
  }

  // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
  double distance = distanceSensor.measureDistanceCm();
  Serial.println(distance);
  delay(500);
  loraSerial.print(distance);
  delay(500);
}
