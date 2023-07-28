const int trigPin = 2;   
const int echoPin = 3;    
const int ledPin = 13;    

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance_cm = duration * 0.034 / 2;
  float threshold_distance_cm = 20.0;
  bool is_parking_spot_vacant = (distance_cm > threshold_distance_cm);
  if (is_parking_spot_vacant) {
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW); 
  }
  Serial.print("Distance (cm): ");
  Serial.print(distance_cm);
  Serial.print(", Parking spot vacant: ");
  Serial.println(is_parking_spot_vacant);
  delay(1000);
}
