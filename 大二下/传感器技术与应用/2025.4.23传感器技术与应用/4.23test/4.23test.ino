#include <NewPing.h>

#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE 400

#define LDR_PIN A0        // 光敏电阻
#define GREEN_LED 8       // 绿灯 = 游戏进行
#define RED_LED 9         // 红灯 = 游戏结束

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

unsigned long lastPingTime = 0;
const unsigned long pingInterval = 100;
int lastldrVal=1000;

void setup() {
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
}

void loop() {
  static String cmd = "";
  unsigned long now = millis();

  // 接收PC命令控制LED
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      cmd.trim();
      if (cmd == "START") {
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, LOW);
      } else if (cmd == "GAME_OVER") {
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);
      }
      cmd = "";
    } else {
      cmd += c;
    }
  }
  // 获取超声波返回时间
  unsigned int pingTime = sonar.ping(); // 单位：微秒
  float distance=(pingTime/1000000.0)*343/2.0*100.0;//cm
  if(distance>50)
  {
    Serial.println("JUMP");
  }
  else if(distance<10)
  {
    Serial.println("CROUCH");
  }
  else
  {
    Serial.println("NONE");
  }
  // 光敏电阻：蹲下（低于阈值）
  int ldrVal = analogRead(LDR_PIN);
  if (ldrVal > 300 && lastldrVal<300) {
    Serial.println("dark");
  }
  else if(ldrVal<300 && lastldrVal>300)
  {
    Serial.println("light");
  }
  lastldrVal=ldrVal;
}