const int trig= 2;
const int echo= 3;
const int piezo = 8;

unsigned long nextBeepTime = 0;

void setup() {
}

void loop()
{
  long val= readUltrasonicDistance(trig, echo);

  unsigned long current = millis();
  
  if(val < 200) { //20cm 미터 이내
    if(current > nextBeepTime) {
      tone(piezo, 440, 100);
      nextBeepTime = millis() + val * 2;
    }
  }

  delay(50);
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH) * 1723 / 10000; // mm
}
