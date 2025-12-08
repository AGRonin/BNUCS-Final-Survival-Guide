//大作业Arduino程序
//引库
#include <DHT.h>
#include <NewPing.h>
#include <LiquidCrystal_I2C.h>

//接口定义、基础设置
#define PS2_VRX A0
#define PS2_VRY A1
#define PS2_SW  2

#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define LDR_PIN A3

#define TRIG_PIN 4
#define ECHO_PIN 5
#define MAX_DISTANCE 400
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

#define BUZZER_PIN 6
#define LED_R 9
#define LED_G 10
#define LED_B 11

LiquidCrystal_I2C lcd(0x27, 16, 2);
//这里，lcd两个口连A4、A5

//状态定义
enum Mode {
  MODE_HOME,
  MODE_CHAT,
  MODE_GAME,
  MODE_WORD,
  MODE_WATER
};
Mode currentMode = MODE_HOME;

//全局变量
unsigned long lastWaterCheck = 0;
bool waterReminderActive = false;
bool inSubMode = false;
unsigned long gameStartTime = 0;
int lastldrVal=1000;
unsigned long lastPingTime = 0;
const unsigned long pingInterval = 100;

//一堆初始化
void setup() {
  Serial.begin(9600);
  pinMode(PS2_SW, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_R, INPUT);
  pinMode(LED_G, INPUT);
  pinMode(LED_B, INPUT);
  dht.begin();
  digitalWrite(BUZZER_PIN, HIGH);
  setLED(0,0,0);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("System Ready");
}

//主循环
void loop() {
  if (currentMode == MODE_GAME) {
    game();//如果游戏模式调用游戏
  }
  handleJoystick();
  checkWaterReminder();

  // 串口命令处理
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    //一直显示CPU占用率
    if (input.startsWith("TOP ")) {
      int val;
      int parsed = sscanf(input.c_str(), "TOP %d", &val);
      if (parsed == 1) {
        lcd.setCursor(0, 0);
        lcd.print("                ");
        lcd.setCursor(0, 0);
        lcd.print("TOP Value:");
        val=val/100;
        lcd.print(val);
        lcd.print("%");
        Serial.println("[LCD已显示CPU占用率]");
      } else {
        Serial.println("[TOP格式错误]");
      }
    }

    //聊天模式改灯的颜色
    else if (currentMode == MODE_CHAT && input.startsWith("LED ")) {
      int r, g, b;
      int parsed = sscanf(input.c_str(), "LED %d %d %d", &r, &g, &b);
      if (parsed == 3) {
        setLED(r, g, b);
        Serial.println("[LED已设置]");
      } else {
        Serial.println("[LED格式错误]");
      }
    }

    //聊天模式改灯的颜色
    else if (currentMode == MODE_WORD && input.startsWith("WORD ")) {
      String word = input.substring(5);  // 提取WORD后的词
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print(word);
      Serial.println("[已显示接龙单词]");
    }
  }
}

//手柄输入处理
void handleJoystick() {
  int x = analogRead(PS2_VRX);
  int y = analogRead(PS2_VRY);
  bool press = digitalRead(PS2_SW) == LOW;

  if (press) {
    currentMode = MODE_HOME;
    inSubMode = false;
    stopBuzzer();
    Serial.println("MODE_HOME");
    return;
  }

  if (inSubMode) return; // 处于子模式中，忽略切换请求

  if (y < 100) {
    currentMode = MODE_CHAT;
    inSubMode = true;
    sendSensorStatus();
    Serial.println("MODE_CHAT");
  } else if (x > 900) {
    currentMode = MODE_GAME;
    inSubMode = true;
    gameStartTime = millis();
    Serial.println("MODE_GAME");
  } else if (y > 900) {
    currentMode = MODE_WORD;
    inSubMode = true;
    sendSensorStatus();
    Serial.println("MODE_WORD");
  } else if (x < 100) {
    currentMode = MODE_WATER;
    lastWaterCheck = millis();
    inSubMode = true;
    waterReminderActive = false;
    stopBuzzer();
    Serial.println("MODE_WATER");
  }
}

//游戏函数
void game(){
    // 获取超声波返回时间
  unsigned int pingTime = sonar.ping();
  float distance=(pingTime/1000000.0)*343/2.0*100.0;
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

//发送传感器状态
void sendSensorStatus() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int light = analogRead(LDR_PIN);
  unsigned long studyDuration = (millis() - gameStartTime) / 60000;
  Serial.print("TEMP:"); Serial.println(temp);
  Serial.print("HUM:"); Serial.println(hum);
  Serial.print("LIGHT:"); Serial.println(light);
  Serial.print("STUDY:"); Serial.println(studyDuration);
}

//喝水提醒
void checkWaterReminder() {
  unsigned long now = millis();
  if (now - lastWaterCheck > 3600000UL) {
    waterReminderActive = true;
    buzz();
    Serial.println("REMIND_WATER");
  }
}

//蜂鸣器叫
void buzz() {
  digitalWrite(BUZZER_PIN, LOW);
}

//蜂鸣器不叫
void stopBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH);
}

//设置LED颜色
void setLED(int r, int g, int b) {
  analogWrite(LED_R, r);
  analogWrite(LED_G, g);
  analogWrite(LED_B, b);
}
