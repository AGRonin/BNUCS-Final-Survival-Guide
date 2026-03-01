#include <SoftwareSerial.h>

// 软件串口连接 ESP8266：D2 为 TX，D11 为 RX
SoftwareSerial espSerial(2, 11); // Arduino TX->D2, RX->D11 (接 ESP8266)

void setup1() {
  Serial.begin(9600);
  espSerial.begin(115200);  // 临时通信
  delay(2000);
  espSerial.println("AT+UART=9600,8,1,0,0");  // 改成 9600 波特率
}

void setup() {
  // 初始化串口
  Serial.begin(9600);       // PC 串口调试
  espSerial.begin(9600);    // ESP8266 通信串口
  delay(1000);
  
  Serial.println("初始化 ESP8266 ...");

  // 设置 WiFi 模式为 STA+AP 模式（模式3）
  sendCommand("AT+CWMODE=3", 1000);

  // 连接 WiFi（修改为你的 WiFi 名和密码）
  sendCommand("AT+CWJAP=\"Mate 50\",\"yp2dwdku3a5x73k\"", 5000);

  // 重启模块
  sendCommand("AT+RST", 7000);

  // 启动 TCP 客户端连接（替换为你的服务端IP和端口）
  sendCommand("AT+CIPSTART=\"TCP\",\"192.168.1.101\",10086", 2000);

  // 设置透传模式
  sendCommand("AT+CIPMODE=1", 1000);

  // 开始透传
  sendCommand("AT+CIPSEND", 1000);

  // 设置超时（可选）
  sendCommand("AT+CIPSTO=1000", 1000);

  Serial.println("ESP8266 已进入透传模式。");
}

void loop() {
  // 将串口发送的数据转发到 ESP8266
  if (Serial.available()) {
    char c = Serial.read();
    espSerial.write(c);
  }

  // 将 ESP8266 返回的数据转发到串口
  if (espSerial.available()) {
    char c = espSerial.read();
    Serial.write(c);
  }
}

// 封装发送 AT 命令函数（带延时）
void sendCommand(String command, int waitTime) {
  espSerial.println(command);
  delay(waitTime);
  // 打印返回内容（可注释掉）
  while (espSerial.available()) {
    Serial.write(espSerial.read());
  }
}