#include <Servo.h> 
#define trig 2
#define echo 3
int distance;
long duration;
int pos = 0;
Servo myservo;

void setup () {
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  myservo.attach(12);
  }

void loop () {
  
  
  long duration, distance;
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance <200) {
       
        myservo.write(180);
               
   } else {
      myservo.write(90);
   }
    
  
    
    
  
  Serial.print("cm");
  Serial.println(distance);
}
