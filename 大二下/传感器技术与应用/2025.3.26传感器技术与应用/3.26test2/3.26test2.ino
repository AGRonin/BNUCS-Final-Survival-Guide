#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// **按键编码（NEC协议）**
#define KEY_1 0xFF30CF
#define KEY_2 0xFF18E7
#define KEY_3 0xFF7A85
#define KEY_4 0xFF10EF
#define KEY_5 0xFF38C7
#define KEY_6 0xFF5AA5
#define KEY_7 0xFF42BD
#define KEY_8 0xFF4AB5
#define KEY_9 0xFF52AD

// **硬件引脚**
const int irReceiverPin = 8;  // 红外接收引脚
const int buzzerPin = 10;      // 有源蜂鸣器引脚

// **LCD1602 初始化**
LiquidCrystal_I2C lcd(0x27, 16, 2);

// **红外接收**
IRrecv irrecv(irReceiverPin); // 创建 IRrecv 对象
decode_results results;

// **长按检测**
unsigned long pressStartTime = 0;
const int LONG_PRESS_THRESHOLD = 1000; // 长按阈值（ms）
bool buttonPressed = false;  // 标记按键是否被按下

void setup() {
  pinMode(buzzerPin, OUTPUT);   // 设置蜂鸣器为输出模式
  Serial.begin(9600);           // 初始化串口
  irrecv.enableIRIn();          // 启用红外接收
  lcd.init();                   
  lcd.backlight();              // 开启 LCD 背光
}

// **短按显示**
void noblink(int num) {
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print(num);
}

// **长按显示（闪烁）**
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

// **蜂鸣器报警**
void beep() {
  digitalWrite(buzzerPin, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, LOW);
}

// **处理红外按键**
void remote_deal(unsigned long ir_code) {
  int num = -1;

  switch (ir_code) {
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
    if (!buttonPressed) { // **如果按键刚刚按下**
      pressStartTime = millis();
      buttonPressed = true;
    }
    
    unsigned long pressTime = millis() - pressStartTime;
    
    if (pressTime >= LONG_PRESS_THRESHOLD) {  // **长按**
      blink(num);
      beep();
    } else {  // **短按**
      noblink(num);
    }
  }
}

void loop() {
  if (irrecv.decode(&results)) {  // 解析红外信号
    Serial.print("irCode: ");
    Serial.print(results.value, HEX);
    Serial.print(", bits: ");
    Serial.println(results.bits);

    remote_deal(results.value);
    irrecv.resume();  // 继续接收
  }

  // **检测按键是否松开**
  if (buttonPressed && irrecv.decode(&results) == 0) {  
    buttonPressed = false;  // **按键松开，重置状态**
  }
}