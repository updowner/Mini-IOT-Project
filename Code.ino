// defines pins numbers
const int trigPin = 12; //6
const int echoPin = 15; //8
const int trigPin2 = 13;
const int echoPin2 = 14;
// defines variables
long duration;
int distance;
long duration2;
int distance2;

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "d770f555226841c79903cf8cd111313b";

BlynkTimer timer;

void myTimerEvent()
{
 // Clears the trigPin
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration2 = pulseIn(echoPin2, HIGH);
// Calculating the distance
distance2= duration2*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance2: ");
Serial.println(distance2);
delay(10);

Blynk.virtualWrite(2, distance);
  }
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
Blynk.begin(auth, "am", "00009999", "blynk-cloud.com", 8442);
timer.setInterval(5000L, myTimerEvent);
}


int data()
{
 // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(10);



Blynk.virtualWrite(1, distance);
return(distance);


}


void loop()
{
   Blynk.run();
   data();
   timer.run();
}