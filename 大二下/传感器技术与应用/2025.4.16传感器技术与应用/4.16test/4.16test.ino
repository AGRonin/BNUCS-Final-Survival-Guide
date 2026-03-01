#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#include <OneWire.h>
#include <DallasTemperature.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define BUZZER_PIN 4
#define ONE_WIRE_BUS 7
#define MAX_DISTANCE 400
NewPing sonar(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// === 时间控制变量 ===
unsigned long lastTempTime=-5000;
const unsigned long tempInterval=5000;//温度更新频率
unsigned long lastPingTime=-50;
const unsigned long pingInterval=50;//距离更新频率
unsigned int uS,pingTime,distance;
float tempC,vt;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN,HIGH);
  sensors.begin();
}

void loop() {
  unsigned long now=millis();
  if(now-lastTempTime>=tempInterval)
  {
    lastTempTime=now;
    sensors.requestTemperatures();
    tempC=sensors.getTempCByIndex(0);
    Serial.print(tempC);
    Serial.println("°C");
    lcd.setCursor(0,1);
    lcd.print("Temp.    ");
    lcd.print(tempC);
    lcd.print(char(223));
    lcd.print("C");
  }
  if(now-lastPingTime>=pingInterval)
  {
    lastPingTime=now;
    uS=sonar.ping();
    vt=331.45*sqrt((273.15+tempC)/273.15);
    pingTime=sonar.ping();//微秒
    distance=(pingTime/1000000.0)*vt/2.0*100.0;//cm
    Serial.print(distance);
    Serial.println("cm");
    lcd.setCursor(0,0);
    lcd.print("Distance      cm");
    lcd.setCursor(11,0);
    lcd.print(distance);
    if (distance<20)
    {
      digitalWrite(BUZZER_PIN,LOW);
    }
    else {
      digitalWrite(BUZZER_PIN,HIGH);
    }
  }
}
