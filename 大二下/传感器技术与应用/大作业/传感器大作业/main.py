import serial
import time
import datetime
import subprocess
from openai import OpenAI
import psycopg2
import psutil
import threading

#DeepSeek连接
DEEPSEEK_API_KEY = ""
client = OpenAI(api_key=DEEPSEEK_API_KEY, base_url="https://api.deepseek.com")

#串口信息
ser = serial.Serial('/dev/cu.usbmodem1301', 9600)
ser.flush()

#数据库信息
conn = psycopg2.connect(
    database="finance01",
    user="python01_user28",
    password="python01_user28@123",
    host="110.41.115.206",
    port=8000
)
cursor = conn.cursor()

#全局变量信息
temperature = None
humidity = None
light = None
study_time = None
current_mode = "MODE_HOME"

#询问DeepSeek
def ask_gpt(prompt: str):
    try:
        response = client.chat.completions.create(
            model="deepseek-chat",
            messages=[{"role": "user", "content": prompt}],
            stream=False
        )
        return response.choices[0].message.content.strip()
    except Exception as e:
        print(f"[GPT] 错误: {e}")
        return "GPT 出错了，请检查网络或 API key。"


#词语接龙-是否是合法英文单词
def is_valid_word(word):
    prompt = f"Is '{word}' a valid English word? Only answer 'yes' or 'no'."
    reply = ask_gpt(prompt)
    return reply.lower() == "yes"

#数据库-插入新的值
def insert_word(word, round_num, speaker):
    try:
        cursor.execute(
            "INSERT INTO word_chain (word, round, player) VALUES (%s, %s, %s)",
            (word.lower(), round_num, speaker)
        )
        conn.commit()
        return True
    except psycopg2.Error:
        conn.rollback()
        return False

#数据库-查询已有值的其他数据
def get_word_info(word):
    cursor.execute("SELECT round, player FROM word_chain WHERE word = %s", (word,))
    return cursor.fetchone()

#CPU-检测占用率并发送
def monitor_cpu():
    while True:
        cpu_percent = psutil.cpu_percent(interval=1)
        try:
            ser.write(f"TOP {cpu_percent*100}\n".encode())
        except Exception as e:
            print(f"[串口写入错误] {e}")

#各模式函数
#点按：回家
def MODE_HOME():
    pass

#上：与DS对话
def MODE_CHAT():
    global current_mode
    now = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    prompt = (
        f"现在的温度是{temperature}度，湿度是{humidity}%，灯光是{light}，"
        f"已学习时间{study_time}分钟，现在的实时时间是：{now}。"
        "请你生成一句鼓励我学习的话作为与我对话的开场白，内容可以和上面有关但是不要太僵硬，并且为我选择一个合适的小灯泡颜色。这个小灯泡颜色应当与现在的环境比较相配。"
        "你的回答结果不需要有其他的内容，只应当给出一句话，后面有三个数字，分别代表R、G、B，以空格隔开，与前面的内容也要用空格隔开"
        "回答示例如下：时间已经很晚啦，把灯光调稍微暗一些吧～ 255 255 255"
    )
    reply = ask_gpt(prompt)

    try:
        *message_parts, r, g, b = reply.strip().split()
        message = " ".join(message_parts)
        r, g, b = int(r), int(g), int(b)
    except Exception as e:
        print(f"[GPT 回复解析错误] {e}")
        message = reply
        r, g, b = 255, 255, 255  #默认白光防出错

    print("[GPT 鼓励语与开场白] " + message)

    #向串口发送灯光颜色
    ser.write(f"LED {r} {g} {b}\n".encode())

    #退出逻辑，这一部分实际上可以使用别的方式完成，比如将串口读入改为thread监测，但时间不够就不实现了
    while current_mode == "MODE_CHAT":
        user_input = input("你：")
        if current_mode != "MODE_CHAT":
            break
        gpt_reply = ask_gpt(user_input)
        print("GPT：" + gpt_reply)
        # 接下来在2秒内监听串口
        start_time = time.time()
        found_message = False
        while time.time() - start_time < 2:
            if ser.in_waiting:
                msg = ser.readline().decode().strip()
                if msg == "MODE_HOME":
                    current_mode = "MODE_HOME"
                    print("退出聊天模式，切换到主菜单")
                    found_message = True
                    break
                else:
                    print("收到串口消息:", msg)  # 可选处理其他消息
            time.sleep(0.1)

        # 如果没有收到消息，就继续下一轮聊天输入
        if current_mode != "MODE_CHAT" or found_message:
            break

#右：调用小恐龙游戏
def MODE_GAME():
    print("[系统] 启动小恐龙游戏...")
    subprocess.run(["python", "dinosaur.py"])

#下：词语接龙游戏
def MODE_WORD():
    #首先，创建数据库
    cursor.execute("""
        DROP TABLE IF EXISTS word_chain;
        CREATE TABLE word_chain (
            word VARCHAR(20) PRIMARY KEY,
            round INT,
            player VARCHAR(10)
        );
    """)
    conn.commit()

    print("让我们开始词语接龙游戏吧，这个游戏的要求是你和我（DeepSeek）依次说一个英文单词，")
    print("这个英文单词应该长于3个字母，少于15个字母。")
    print("你的第一个字母要与我的最后一个字母相同，我的第一个字母也要和你的最后一个字母相同。你先来～")

    round_num = 1
    last_word = None

    while True:
        print("\n你：", end="")
        user_word = input().strip().lower()

        if len(user_word) < 4 or len(user_word) > 14:
            print("输入不符合长度要求。请重新输入。")
            continue
        if last_word and user_word[0] != last_word[-1]:
            print(f"你的单词必须以 '{last_word[-1]}' 开头。请重新输入。")
            continue
        if not is_valid_word(user_word):
            print("这个词不是合法的英文单词，请重新输入。")
            continue
        ser.write(f"WORD {user_word}\n".encode())
        if not insert_word(user_word, round_num, "Player"):
            r, p = get_word_info(user_word)
            print(f"这个词第{r}轮由{p}说过。你输了！")
            cursor.execute("DROP TABLE word_chain;")
            conn.commit()
            break

        # DeepSeek 回合
        prompt = f"你是一个玩英文词语接龙游戏的高手。请给出一个以'{user_word[-1]}'开头、长度大于3小于15个字母的英文单词，只回答这个词，不要输出其他内容。"
        ds_word = ask_gpt(prompt).lower()
        print("DeepSeek：", ds_word)
        ser.write(f"WORD {ds_word}\n".encode())

        if len(ds_word) < 4 or len(ds_word) > 14 or ds_word[0] != user_word[-1]:
            print("DeepSeek 接龙失败，你赢了！")
            cursor.execute("DROP TABLE word_chain;")
            conn.commit()
            break
        if not is_valid_word(ds_word):
            print("DeepSeek 给出的不是合法单词，你赢了！")
            cursor.execute("DROP TABLE word_chain;")
            conn.commit()
            break
        if not insert_word(ds_word, round_num, "DeepSeek"):
            r, p = get_word_info(ds_word)
            print(f"这个词第{r}轮由{p}说过。你赢了！")
            cursor.execute("DROP TABLE word_chain;")
            conn.commit()
            break

        last_word = ds_word
        round_num += 1

    print(f"游戏一共进行了 {round_num} 轮。")

#左：记录喝水
def MODE_WATER():
    pass

#串口读取、解析
def read_serial():
    global temperature, humidity, light, study_time, current_mode

    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode().strip()
            print(f"[串口] 收到: {line}")

            if line.startswith("TEMP:"):
                try:
                    temperature = float(line.split(":")[1])
                except Exception as e:
                    print(f"[TEMP 解析错误] {e}")

            elif line.startswith("HUM:"):
                try:
                    humidity = float(line.split(":")[1])
                except Exception as e:
                    print(f"[HUM 解析错误] {e}")

            elif line.startswith("LIGHT:"):
                try:
                    light = int(line.split(":")[1])
                except Exception as e:
                    print(f"[LIGHT 解析错误] {e}")

            elif line.startswith("STUDY:"):
                try:
                    study_time = int(line.split(":")[1])
                except Exception as e:
                    print(f"[STUDY 解析错误] {e}")

            elif line.startswith("MODE_"):
                current_mode = line
                print(f"[系统] 当前模式切换为：{current_mode}")

                if current_mode == "MODE_HOME":
                    MODE_HOME()
                elif current_mode == "MODE_CHAT":
                    MODE_CHAT()
                elif current_mode == "MODE_GAME":
                    MODE_GAME()
                elif current_mode == "MODE_WORD":
                    MODE_WORD()
                elif current_mode == "MODE_WATER":
                    MODE_WATER()

#程序入口
if __name__ == "__main__":
    print("🎉 Python 控制系统已启动，等待串口指令...")

    # 启动 CPU 监测线程
    cpu_thread = threading.Thread(target=monitor_cpu, daemon=True)
    cpu_thread.start()

    read_serial()