#include <Servo.h>

Servo myservo;
int light, turn, sum, avglight, skip;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
  myservo.attach(3);

  sum=0;
  avglight=512;
  skip = 30;  // Πόσα λεπτά κλείνουμε την τέντα
}

void loop()
{
  delay(60000);
  
  if (skip <= 0) {
  	light = analogRead(A0);
  	sum = sum - sum/30;
  	sum = sum + light;
    
  	if (sum/30 > avglight) { // κλείνουμε
  		skip = 30;               // για 30 λεπτά
  		sum = 0;
  		myservo.write(90);
  	}
  }
    else {
      skip = skip - 1;
      if (skip==0) myservo.write(0);  // Ανοίγει τέντα
    }
}