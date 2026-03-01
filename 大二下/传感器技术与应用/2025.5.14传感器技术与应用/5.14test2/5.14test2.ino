#include <SoftwareSerial.h>
#include <DHT.h>

// 引脚定义
#define DHTPIN 4
#define DHTTYPE DHT11
#define RX_PIN 2   // Arduino 接收引脚
#define TX_PIN 11  // Arduino 发送引脚

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial espSerial(RX_PIN, TX_PIN); // RX, TX

#define motorIn1 9
#define motorIn2 10

bool fanOn = false;
String espResponse = "";
String mqttCommand = "";

unsigned long lastSend = 0;
const unsigned long sendInterval = 5000;

void setup() {
  Serial.begin(9600);       // PC 调试
  espSerial.begin(9600);    // 与 ESP8266 通讯
  dht.begin();

  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, LOW);

  delay(2000);
  initESP8266();
}

void loop() {
  handleESP8266Response();
  updateFan();

  if (millis() - lastSend > sendInterval) {
    publishSensorData();
    lastSend = millis();
  }
}

// 初始化WiFi与MQTT
void initESP8266() {
  sendCommand("AT+RST", 2000);
  sendCommand("AT+CWMODE=1", 1000);
  //sendCommand("AT+CWJAP=\"Mate 50\",\"yp2dwdku3a5x73k\"", 8000);  // 修改为你的WiFi
  sendCommand("AT+CWJAP=\"evol\",\"12345678\"", 8000);  // 修改为你的WiFi
  //sendCommand("AT+CWJAP=\"杨师傅的iPhone\",\"yangbowen\"", 8000);  // 修改为你的WiFi
  sendCommand("AT+MQTTUSERCFG=0,1,\"arduinoClient\",\"\",\"\",0,0,\"\"", 1000);
  sendCommand("AT+MQTTCONN=0,\"broker.emqx.io\",1883,0", 4000);  // TCP连接
  sendCommand("AT+MQTTSUB=0,\"/arduino/yangbowen/cmd\",0", 1000);          // 订阅控制主题
}

// 接收ESP8266消息
void handleESP8266Response() {
  while (espSerial.available()) {
    char c = espSerial.read();
    espResponse += c;

    // 判断是否完整接收一行
    if (espResponse.endsWith("\n")) {
      Serial.print("ESP回应: ");
      Serial.print(espResponse);  // 不加 println 更清楚格式

      if (espResponse.startsWith("+MQTTSUBRECV:")) {
        // 示例: +MQTTSUBRECV:0,"/arduino/yangbowen/cmd",6,fan_on
        // 提取最后一个逗号后面的部分（即 payload）
        int comma1 = espResponse.indexOf(',');
        int comma2 = espResponse.indexOf(',', comma1 + 1);
        int comma3 = espResponse.indexOf(',', comma2 + 1);
        if (comma3 != -1 && comma3 + 1 < espResponse.length()) {
          String payload = espResponse.substring(comma3 + 1);
          payload.trim();     // 去除换行、空格
          payload.toLowerCase();

          Serial.println("提取到指令: " + payload);

          if (payload == "fan_on") {
            fanOn = true;
            Serial.println("风扇开启指令生效");
          } else if (payload == "fan_off") {
            fanOn = false;
            Serial.println("风扇关闭指令生效");
          } else {
            Serial.println("未知指令: " + payload);
          }
        }
      }

      espResponse = ""; // 清除缓存
    }
  }
}

// 控制风扇
void updateFan() {
  if (fanOn) {
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, HIGH);
  } else {
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
  }
}

// 发送温湿度数据
void publishSensorData() {
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();

  if (isnan(temp) || isnan(humi)) {
    Serial.println("读取DHT失败！");
    return;
  }

  String payload = String(temp) + "," + String(humi) + "," + (fanOn ? "ON" : "OFF");
  String cmd = "AT+MQTTPUB=0,\"/arduino/yangbowen/data\",\"" + payload + "\",0,0";
  sendCommand(cmd, 1000);
}

// 发送命令封装
void sendCommand(String cmd, int delayMs) {
  Serial.println("发送命令: " + cmd);
  espSerial.println(cmd);
  delay(delayMs);
  while (espSerial.available()) {
    Serial.write(espSerial.read());
  }
  Serial.println();
}