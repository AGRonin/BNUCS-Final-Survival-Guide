#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int digitalPin=7;
int analogPin=A0;
const int redPin=13;
const int greenPin=12;
boolean Dstate=0;
int Astate=0;
int tim=5000;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(digitalPin,INPUT);
  pinMode(analogPin,INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  Astate=analogRead(analogPin);
  Dstate=digitalRead(digitalPin);
  Serial.print("D0:");
  Serial.println(Dstate);
  Serial.print("A0:");
  Serial.println(Astate);
  lcd.setCursor(0,0);
  lcd.println(Astate);
  if(Dstate==LOW)
  {
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
    lcd.print("WARNING! HOT!");
  }
  else
  {
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
    lcd.print("COOL! Continue!");
  }
  delay(tim);
  lcd.clear();
}
