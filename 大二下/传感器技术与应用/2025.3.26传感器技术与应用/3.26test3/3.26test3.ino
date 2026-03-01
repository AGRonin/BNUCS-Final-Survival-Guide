#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// **LCD1602 初始化**
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define IR_RECEIVER_PIN 8  // 红外接收引脚
#define BUZZER_PIN 10      // 有源蜂鸣器引脚

volatile unsigned long irCode = 0;   // 解析出的红外码
volatile bool newCodeReceived = false; // 是否收到新的按键
bool isLongPress = false;  // 是否为长按
unsigned long lastPressTime = 0;

// **按键编码（NEC协议）**
#define KEY_1 0xFF30CF
#define KEY_2 0xFF18E7
#define KEY_3 0x2857
#define KEY_4 0xFF10EF
#define KEY_5 0xFF38C7
#define KEY_6 0x2956
#define KEY_7 0x2F50
#define KEY_8 0x2B54
#define KEY_9 0x2D52

void setup() {
  Serial.begin(9600);
  pinMode(IR_RECEIVER_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  lcd.init();
  lcd.backlight();
}

// **判断逻辑 0 或 1**
char logic_value() {
  while (!(digitalRead(IR_RECEIVER_PIN))); // 低电平等待
  unsigned int pulseWidth = micros();
  
  while (digitalRead(IR_RECEIVER_PIN)); // 高电平等待
  pulseWidth = micros() - pulseWidth;

  if (pulseWidth >= 400 && pulseWidth <= 700) return 0;  // 560us 代表逻辑 0
  if (pulseWidth >= 1400 && pulseWidth <= 1800) return 1; // 1.7ms 代表逻辑 1
  return -1; // 解析失败
}

// **接收地址码 & 命令码**
void pulse_deal() {
  int i;
  irCode = 0x00;

  // 解析 8 位地址码（一般为 0x00，不用存）
  for (i = 0; i < 8; i++) if (logic_value() != 0) return;
  for (i = 0; i < 8; i++) if (logic_value() != 1) return;
  if (logic_value() != 0) return; // NEC 固定格式
  if (logic_value() != 1) return;

  // 解析 16 位命令码
  for (i = 0; i < 16; i++) {
    if (logic_value() == 1) irCode |= (1 << i);
  }

  newCodeReceived = true;
}

// **解码 IR 信号**
void remote_decode() {
  unsigned long pulseWidth;
  
  // 等待起始信号
  while (digitalRead(IR_RECEIVER_PIN)) {
    if (micros() - lastPressTime >= 100000) {
      irCode = 0xff00;
      return;
    }
  }
  
  // 解析 NEC 起始信号
  lastPressTime = micros();
  pulseWidth = micros();
  
  while (!digitalRead(IR_RECEIVER_PIN)); // 低等待
  pulseWidth = micros() - pulseWidth;

  if (pulseWidth >= 8000 && pulseWidth <= 9500) { // 9ms
    pulseWidth = micros();
    while (digitalRead(IR_RECEIVER_PIN)); // 高等待
    pulseWidth = micros() - pulseWidth;

    if (pulseWidth >= 4000 && pulseWidth <= 5000) { // 4.5ms
      pulse_deal(); // 解析按键信号
    }
  }
}

// **LCD1602 短按显示**
void noblink(int num) {
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print(num);
}

// **LCD1602 长按闪烁**
void blink(int num) {
  for (int i = 0; i < 5; i++) {
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print(num);
    delay(300);
    lcd.clear();
    delay(300);
  }
}

// **蜂鸣器警报**
void beep() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(1000);
  digitalWrite(BUZZER_PIN, LOW);
}

// **处理 NEC 按键信号**
void remote_deal() {
  int num = -1;

  switch (irCode) {
    case KEY_1: num = 1; break;
    case KEY_2: num = 2; break;
    case KEY_3: num = 3; break;
    case KEY_4: num = 4; break;
    case KEY_5: num = 5; break;
    case KEY_6: num = 6; break;
    case KEY_7: num = 7; break;
    case KEY_8: num = 8; break;
    case KEY_9: num = 9; break;
  }

  if (num != -1) {
    unsigned long pressDuration = micros() - lastPressTime;
    if (pressDuration < 200000) { // 200ms 内算短按
      noblink(num);
    } else { // 长按
      if (!isLongPress) {
        blink(num);
        beep();
        isLongPress = true;
      }
    }
  }
}

void loop() {
  remote_decode();
  if (newCodeReceived) {
    Serial.print("IR Code: ");
    Serial.println(irCode, HEX);
    
    remote_deal();
    newCodeReceived = false;
  }
}