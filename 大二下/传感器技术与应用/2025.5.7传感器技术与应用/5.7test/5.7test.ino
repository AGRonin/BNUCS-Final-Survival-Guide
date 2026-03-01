#include <DHT.h>

#define DHTPIN 4          // DHT传感器连接的引脚
#define DHTTYPE DHT11     // 或 DHT22
DHT dht(DHTPIN, DHTTYPE);

#define motorIn1 9        // 风扇控制引脚1
#define motorIn2 10        // 风扇控制引脚2

String inputString = "";  // 串口接收缓存
bool fanOn = true;       // 当前风扇状态

void setup() {
  Serial.begin(9600);     // 开启串口
  dht.begin();            // 初始化DHT传感器

  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, LOW);
}

void loop() {
  // 检查串口命令
  if (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      inputString.trim();
      if (inputString == "fan_on") {
        fanOn = true;
      } else if (inputString == "fan_off") {
        fanOn = false;
      }
      inputString = "";
    } else {
      inputString += inChar;
    }
  }

  // 控制风扇
  if (fanOn) {
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, HIGH);  // 正转
  } else {
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);  // 停止
  }

  // 每2秒采集一次温湿度并发送
  static unsigned long lastSendTime = 0;
  if (millis() - lastSendTime > 2000) {
    float temp = dht.readTemperature();
    float humi = dht.readHumidity();
    Serial.print("{\"temperature\":");
    Serial.print(temp);
    Serial.print(",\"humidity\":");
    Serial.print(humi);
    Serial.print(",\"fan\":\"");
    Serial.print(fanOn ? "ON" : "OFF");
    Serial.println("\"}");
    lastSendTime = millis();
  }
}