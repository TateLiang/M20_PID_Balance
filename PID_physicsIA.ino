#include <Servo.h>

const int trigPin = 12;
const int echoPin = 11;

long duration;
double time;
int period = 50; //50ms aka 20Hz

double distance;
double error;
double previous_error;
double desire=15; 
double P;
double I;
double D;

double kp=8;
double ki=0.1;
double kd=2000;
double total;

Servo myservo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);  
  myservo.attach(9); 
  time = millis();
}

int count = 0;
void loop() {
  
  if (millis() > time+period) {
    time = millis();    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
   
    if (distance > 50) {
      distance = 50;
    }
    
    error = desire - distance;   
    P = kp * error;
    D = kd*((error - previous_error) / period);
      
    if(-3 < error && error < 3) {
      I = I + (ki * error);
    }
    else {
      I = 0;
    }
  
    total = P + I + D;
    total = map(total, -150, 150, 0, 130);
  
    if(total < 20) {total = 20;}
    if(total > 140) {total = 140;} 

    if (count <= 200) { //stop everything after 10 seconds
      //Serial.print("Distance: ");
      Serial.println(distance);
      //Serial.print("       Total: ");
      //Serial.println(total+50);
      myservo.write(total+50);  
    }
    
    previous_error = error;
    count++;
  }
}
