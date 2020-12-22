#include <Arduino.h>
#line 1 "C:\\Users\\DELL\\Documents\\Arduino\\Parking_Sensor\\newp\\newp.ino"
#line 1 "C:\\Users\\DELL\\Documents\\Arduino\\Parking_Sensor\\newp\\newp.ino"
// defines pins numbers
#define IN4  4
const int trigPin = 5;
const int echoPin = 6;

long duration;
int distance = 0;
#line 8 "C:\\Users\\DELL\\Documents\\Arduino\\Parking_Sensor\\newp\\newp.ino"
void setup();
#line 14 "C:\\Users\\DELL\\Documents\\Arduino\\Parking_Sensor\\newp\\newp.ino"
void loop();
#line 8 "C:\\Users\\DELL\\Documents\\Arduino\\Parking_Sensor\\newp\\newp.ino"
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(4, OUTPUT);
Serial.begin(9600); 
}
void loop() {
if ((distance <7 )&&(distance > 0))
  {
  digitalWrite(IN4, HIGH);   // turn the LED on (HIGH is the voltage level)
}
else if ((distance > 51)&&(distance < 75))
  {
  digitalWrite(IN4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10*(distance-50));  
  digitalWrite(IN4, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(10*(distance-50));// wait for a set time
  }
else if ((distance > 151)&&(distance < 200)) {
  digitalWrite(IN4, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  
  digitalWrite(IN4, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
}
else if (distance > 200){
  digitalWrite(IN4, LOW);
}
delayMicroseconds(10);
// Clears the trigPin
digitalWrite(trigPin, HIGH);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance); //distance is the returned integer, it is the distance in cm
}

