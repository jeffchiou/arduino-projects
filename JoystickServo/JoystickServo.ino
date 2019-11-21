#include <Servo.h>

Servo myservo;

// Arduino pin numbers
const int SW_DPIN = 2;
const int X_APIN = 0;
const int Y_APIN = 1;

int x_val;
int y_val;
int turn_deg;
const int X_DEFAULT = 511;
const int Y_DEFAULT = 517;
const int DEAD_RANGE = 40; // half of the full deadzone range

void setup() {
  myservo.attach(9);
  pinMode(SW_DPIN, INPUT);
  digitalWrite(SW_DPIN, HIGH);
  Serial.begin(115200);  
}

void loop() {
  x_val = analogRead(X_APIN);
  if (x_val < X_DEFAULT - DEAD_RANGE || x_val > X_DEFAULT + DEAD_RANGE)
  {
    turn_deg = map(x_val, 0, 1023, 17, 180);
    myservo.write(turn_deg);
    Serial.print("Turning");
  }
  /* Debugging
  Serial.print("Switch: ");
  Serial.print(digitalRead(SW_DPIN));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_APIN));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_APIN));
  Serial.print("\n\n");
  */
  delay(250);
}
