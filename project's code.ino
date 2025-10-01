/*
  ------------------------------------------------------------------------------
  © 2025 Javier Siliacay | USTP Autotronics - All Rights Reserved.

  This source code is the intellectual property of the author and is provided 
  for educational and non-commercial use only. Unauthorized copying, modification, 
  distribution, or use of this code for commercial purposes is strictly prohibited 
  without prior written consent from the author.

  Violation of these terms may result in legal action under applicable intellectual 
  property laws.

  For permissions, contact: github.com/javiersiliacay
  ------------------------------------------------------------------------------
*/

//pH Detection Sensor with RGB Led
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define PH_PIN A0  // Analog pin for pH sensor
#define R 2
#define G 3
#define B 4

void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  lcd.setCursor(0, 1);
  lcd.print(" -pH Detection-");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(PH_PIN);
  float voltage = sensorValue * (5.0 / 1023.0);
  float pH = 7 + ((2.5 - voltage) / 0.18);  // Adjust as needed

  Serial.print("Analog Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V | pH: ");
  Serial.println(pH, 2);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("pH: ");
  lcd.print(pH, 2);

  if (pH < 6.8) {       //Value for Acidic
    lcd.setCursor(0, 1);
    lcd.print("Red - Acidic");
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  } else if (pH >= 6.8 && pH <= 7.9) {       //Value for Neutral
    lcd.setCursor(0, 1);
    lcd.print("Green - Neutral");
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
  } else {              //Value for Basic
    lcd.setCursor(0, 1);
    lcd.print("Blue - Basic");
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
  }

  delay(1000);
}
