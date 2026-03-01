from paho.mqtt import client as mqtt
import ssl
import serial
import json
import time
import threading

# 配置 MQTT Broker
broker = 'e26320a0.ala.cn-hangzhou.emqxsl.cn'
port = 8084
TOPIC_PUB = 'arduino/data'
TOPIC_SUB = 'arduino/control'

username="bowen20041225@sina.com"
password="qogBa8-pixquz-sezqub"

ser = serial.Serial('/dev/cu.usbmodem1301', 9600)  # 修改为你实际串口号

# ---------- MQTT 回调函数 ----------
def on_connect(client, userdata, flags, rc, properties=None):
    print(f"✅ Connected with result code {rc}")
    client.subscribe(TOPIC_SUB)

def on_message(client, userdata, msg):
    command = msg.payload.decode()
    print(f"📩 Received control: {command}")
    # 发送命令给 Arduino
    ser.write((command + '\n').encode())

# ---------- MQTT 初始化 ----------
client = mqtt.Client(
    client_id="python_wss_client",
    protocol=mqtt.MQTTv5,  # 使用新版协议避免警告
    transport="websockets"  # 使用 WebSocket
)
client.on_connect = on_connect
client.on_message = on_message

client.tls_set()  # 启用 SSL/TLS
client.username_pw_set(username, password)
client.connect(broker, port, keepalive=60)

# ---------- 启动 MQTT 客户端线程 ----------
client.loop_start()

# ---------- 串口读取线程 ----------
def serial_loop():
    while True:
        try:
            line = ser.readline().decode().strip()
            if line:
                print(f"📤 From Arduino: {line}")
                # 尝试解析为 JSON，如果失败则忽略
                try:
                    data = json.loads(line)
                    client.publish(TOPIC_PUB, json.dumps(data))
                except json.JSONDecodeError:
                    print("❌ Invalid JSON, skipping.")
        except Exception as e:
            print(f"❗ Serial error: {e}")
        time.sleep(0.1)

# 启动串口读取线程
threading.Thread(target=serial_loop, daemon=True).start()

# ---------- 主循环等待 ----------
try:
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    print("🛑 Stopped by user.")
    client.loop_stop()
    ser.close()