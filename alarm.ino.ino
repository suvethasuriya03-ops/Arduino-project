const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 7;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Clear trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance (cm)
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Condition: object within 20 cm
  if (distance <= 20) {
    digitalWrite(ledPin, HIGH);
    
    
  } else {
    digitalWrite(ledPin, LOW);
  }
delay(100);
}