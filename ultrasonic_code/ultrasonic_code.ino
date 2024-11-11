#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define trigPin 7
#define echoPin 6
#define buzzer 4

LiquidCrystal_I2C lcd(0x27, 16, 2);

int sound = 250;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();=
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance > 30 || distance <= 0) {
    lcd.clear();
    lcd.print("Out of range");
    Serial.println("Out of range");
    noTone(buzzer);
  } else {
    lcd.clear();
    lcd.print(distance);
    lcd.print(" cm");
    Serial.print(distance);
    Serial.println(" cm");
    tone(buzzer, sound);
  }
  delay(500);
}
