const int TRIG_PIN = 5;
const int ECHO_PIN = 8;
const int LED_PIN1 = 11;
const int LED_PIN2 = 9;
const int LED_PIN3 = 13;
const int DISTANCE_THRESHOLD1 = 10;
const int DISTANCE_THRESHOLD2 = 20;
const int DISTANCE_THRESHOLD3 = 30;
float duration_us, distance_cm;
void setup() {
Serial.begin(9600);
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
pinMode(LED_PIN1, OUTPUT);
pinMode(LED_PIN2, OUTPUT);
pinMode(LED_PIN3, OUTPUT);
}
void loop() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration_us=pulseIn(ECHO_PIN,HIGH);
  distance_cm = 0.017 * duration_us;
if(distance_cm<= DISTANCE_THRESHOLD2) {
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, LOW);
}
else {
digitalWrite(LED_PIN1, LOW);
}
if(distance_cm <= DISTANCE_THRESHOLD2 and distance_cm >= DISTANCE_THRESHOLD1) {
  digitalWrite(LED_PIN2, HIGH);
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN3, LOW);
}
else {
  digitalWrite(LED_PIN2, LOW);
}
if(distance_cm <= DISTANCE_THRESHOLD3 and distance_cm >= DISTANCE_THRESHOLD2) {
  digitalWrite(LED_PIN3, HIGH);
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
}
else {
  digitalWrite(LED_PIN3, LOW);
}
Serial.print("distance: ");
Serial.println("distance_cm");
Serial.println("cm");
delay(1000);
}



