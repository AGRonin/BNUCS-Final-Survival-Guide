#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BUZZER 10       // 蜂鸣器引脚
#define IR_IN 8         // 红外接收器引脚

LiquidCrystal_I2C lcd(0x27, 16, 2); // 初始化 LCD1602，I2C 地址 0x27

int Pulse_Width = 0;   // 存储脉宽
int ir_code = 0x00;    // 存储解析出的命令码
char num=-1;
int shortnum=0;

// **按键编码（NEC协议）**
#define KEY_0 0x16
#define KEY_1 0x0C
#define KEY_2 0x18
#define KEY_3 0x5E
#define KEY_4 0x08
#define KEY_5 0x1C
#define KEY_6 0x5A
#define KEY_7 0x42
#define KEY_8 0x52
#define KEY_9 0x4A
#define KEY_OUT 0x45

// 初始化定时器
void timer1_init() {
    TCCR1A = 0X00;
    TCCR1B = 0X05; // 设置时钟源
    TCCR1C = 0X00;
    TCNT1 = 0X00;
    TIMSK1 = 0X00; // 禁止溢出中断
}

// **解析 NEC 协议逻辑位 0 或 1**
char logic_value() {
    while (!digitalRead(IR_IN)); // 等待低电平结束
    Pulse_Width = TCNT1;
    TCNT1 = 0;
    
    if (Pulse_Width >= 7 && Pulse_Width <= 10) { // 560us 低电平
        while (digitalRead(IR_IN)); // 等待高电平结束
        Pulse_Width = TCNT1;
        TCNT1 = 0;

        if (Pulse_Width >= 7 && Pulse_Width <= 10) { // 560us 高电平 -> 逻辑 0
            return 0;
        } else if (Pulse_Width >= 25 && Pulse_Width <= 27) { // 1.7ms 高电平 -> 逻辑 1
            return 1;
        }
    }
    return -1; // 无效信号
}

// **解析红外命令码**
void pulse_deal() {
    int i;
    ir_code = 0x00;

    // 解析地址码（8位+8位反码）
    for (i = 0; i < 8; i++) if (logic_value() != 0) return;
    for (i = 0; i < 8; i++) if (logic_value() != 1) return;

    // 解析命令码（8位+8位反码）
    for (i = 0; i < 8; i++) {
        if (logic_value() == 1) ir_code |= (1 << i);
    }

    for (i = 0; i < 8; i++) if (logic_value() != (ir_code >> i & 1)) return; // 确保反码正确
}

// **解析 NEC 信号**
void remote_decode() {
    TCNT1 = 0X00;
    while (digitalRead(IR_IN)) { // 等待低电平开始
        if (TCNT1 >= 1563) { // 无按键按下（高电平 > 100ms）
            ir_code = 0xff00;
            return;
        }
    }

    // 检测引导码（9ms 低电平 + 4.5ms 高电平）
    TCNT1 = 0X00;
    while (!digitalRead(IR_IN));
    Pulse_Width = TCNT1;
    TCNT1 = 0;

    if (Pulse_Width >= 140 && Pulse_Width <= 141) { // 9ms
        while (digitalRead(IR_IN));
        Pulse_Width = TCNT1;
        TCNT1 = 0;

        if (Pulse_Width >= 68 && Pulse_Width <= 72) { // 4.5ms
            pulse_deal();
        } else if (Pulse_Width >= 34 && Pulse_Width <= 36) { // 2.25ms（长按检测）
            ir_code = 0xFFFF; // 识别为长按重复码
        }
    }
}

// **执行接收到的信号**
void remote_deal() {
    Serial.print("Received IR Code: 0x");
    Serial.println(ir_code, HEX); // 输出16进制

    // 判断是否为退出按键
    if (ir_code == KEY_OUT) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Exiting...");
        delay(1000); // 显示退出提示
        while (true); // 进入死循环，停止程序
    }
    
    if(ir_code==0xFFFFFFFF)
    {
      shortnum+=1;
      if(shortnum<10)
      {
        noBlink(num);
        return;
      }
    }
    else
    {
      shortnum=0;
      num=-1;
    }
    switch (ir_code) {
        case KEY_0: num = '0'; break;
        case KEY_1: num = '1'; break;
        case KEY_2: num = '2'; break;
        case KEY_3: num = '3'; break;
        case KEY_4: num = '4'; break;
        case KEY_5: num = '5'; break;
        case KEY_6: num = '6'; break;
        case KEY_7: num = '7'; break;
        case KEY_8: num = '8'; break;
        case KEY_9: num = '9'; break;
        case 0xFFFFFFFF: // 长按检测
            if (num != -1) {
                tone(BUZZER, 2000, 2000); // 蜂鸣器响 2 秒
                blink(num);
            }
            return;
        default:
            return;
    }

    if (num != -1) {
        noBlink(num);
    }
}

// **短按显示数字（不闪烁）**
void noBlink(char num) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Short Press: ");
    lcd.setCursor(0, 1);
    lcd.print(num);
}

// **长按显示数字（闪烁）**
void blink(char num) {
    for (int i = 0; i < 5; i++) {
        lcd.clear();
        delay(300);
        lcd.setCursor(0, 0);
        lcd.print("Long Press: ");
        lcd.setCursor(0, 1);
        lcd.print(num);
        delay(300);
    }
}

void setup() {
    Serial.begin(9600);
    pinMode(BUZZER, OUTPUT);
    pinMode(IR_IN, INPUT);
    lcd.init();
    lcd.backlight();
}

void loop() {
    timer1_init();
    remote_decode();
    remote_deal();
}