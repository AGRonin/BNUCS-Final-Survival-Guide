#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BUZZER 10
#define IR_IN 2 // 使用外部中断0（即D2）

LiquidCrystal_I2C lcd(0x27, 16, 2);

volatile unsigned long lastTime = 0;
volatile bool newCodeReceived = false;
volatile uint32_t ir_code = 0;

char num = -1;
int shortnum = 0;

bool isLongPressing = false;
unsigned long lastRepeatTime = 0;
unsigned long pressStartTime = 0;
bool hasValidStart = false;

// NEC 键码
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

void setup() {
    Serial.begin(9600);
    pinMode(BUZZER, OUTPUT);
    pinMode(IR_IN, INPUT);
    digitalWrite(BUZZER, HIGH); // 默认不响
    lcd.init();
    lcd.backlight();
    attachInterrupt(digitalPinToInterrupt(IR_IN), ir_ISR, FALLING);
}

void loop() {
    if (newCodeReceived) {
        noInterrupts();
        uint32_t code = ir_code;
        newCodeReceived = false;
        interrupts();

        Serial.print("Received IR Code: 0x");
        Serial.println(code, HEX);
        remote_deal(code);
    }

    // 如果长按中（最近收到的是重复帧），持续蜂鸣器响
    if (isLongPressing) {
        digitalWrite(BUZZER, LOW); // LOW = 响
        blink(num); // 闪烁
    } else {
        digitalWrite(BUZZER, HIGH); // HIGH = 静音
    }

    // 如果超过150ms没有收到重复帧，判定长按结束
    if (isLongPressing && (millis() - lastRepeatTime > 150)) {
        isLongPressing = false;
    }
}

void remote_deal(uint32_t code) {
    if (code == KEY_OUT) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Exiting...");
        delay(1000);
        while (true);
    }

    if (code == 0xFFFFFFFF) {
    if (hasValidStart && millis() - pressStartTime >= 200) {
        lastRepeatTime = millis();
        isLongPressing = true;
    }
    return;
} else {
    pressStartTime = millis();
    hasValidStart = true;
    isLongPressing = false;
}

    shortnum = 0;
    num = -1;

    switch (code) {
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
        default: return;
    }

    if (num != -1) {
        noBlink(num);
    }
}

void noBlink(char num) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Short Press: ");
    lcd.setCursor(0, 1);
    lcd.print(num);
}

void blink(char num) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Long Press: ");
    lcd.setCursor(0, 1);
    lcd.print(num);
    delay(200); // 避免闪烁太快
}

// 中断服务函数，解析 NEC 信号（简化版）
void ir_ISR() {
    static uint32_t lastMicros = 0;
    static uint32_t rawcode = 0;
    static int bitcount = 0;

    uint32_t duration = micros() - lastMicros;
    lastMicros = micros();

    // 识别重复帧：引导+空闲+560us，即 ~11250us
    if (duration > 10000 && duration < 12000) {
        ir_code = 0xFFFFFFFF;
        newCodeReceived = true;
        bitcount = 0;
        rawcode = 0;
        return;
    }

    if (duration > 13000) {
        bitcount = 0;
        rawcode = 0;
        return;
    }

    if (duration > 1000 && duration < 2000) { // 逻辑0
        rawcode >>= 1;
        bitcount++;
    } else if (duration >= 2000 && duration < 3000) { // 逻辑1
        rawcode >>= 1;
        rawcode |= 0x80000000;
        bitcount++;
    }

    if (bitcount == 32) {
        uint8_t addr = rawcode & 0xFF;
        uint8_t addr_inv = (rawcode >> 8) & 0xFF;
        uint8_t cmd = (rawcode >> 16) & 0xFF;
        uint8_t cmd_inv = (rawcode >> 24) & 0xFF;

        if ((addr ^ addr_inv) == 0xFF && (cmd ^ cmd_inv) == 0xFF) {
            ir_code = cmd;
        } else {
            ir_code = 0xFFFFFFFF; // 校验失败也设为重复帧
        }

        newCodeReceived = true;
        bitcount = 0;
        rawcode = 0;
    }
}