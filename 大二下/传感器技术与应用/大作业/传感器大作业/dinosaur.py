import pygame
import serial
import threading
import random
import time
import os

#参数
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 400
FPS = 30
SERIAL_PORT = "/dev/cu.usbmodem1301"
ASSET_DIR = "./assets"

#初始化
pygame.init()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
clock = pygame.time.Clock()

#加载图像
dino_run = [pygame.image.load(os.path.join(ASSET_DIR, "dino_run1.png")),
            pygame.image.load(os.path.join(ASSET_DIR, "dino_run2.png"))]
dino_jump = pygame.image.load(os.path.join(ASSET_DIR, "dino_jump.png"))
dino_crouch = [pygame.image.load(os.path.join(ASSET_DIR, "dino_crouch1.png")),
               pygame.image.load(os.path.join(ASSET_DIR, "dino_crouch2.png"))]

cactus_img = pygame.image.load(os.path.join(ASSET_DIR, "cactus.png"))
bird_img = pygame.image.load(os.path.join(ASSET_DIR, "bird.png"))

#串口
ser = serial.Serial(SERIAL_PORT, 9600)
serial_command = "NONE"

#初始白天
background_color = (255, 255, 255)
font_color = (0, 0, 0)

#读串口
def read_serial():
    global serial_command, background_color, font_color
    valid_commands = {"JUMP", "CROUCH", "NONE", "dark", "light", "MODE_HOME"}

    while True:
        if ser.in_waiting:
            try:
                msg = ser.readline().decode().strip()
                if msg not in valid_commands:
                    continue

                if msg == "dark":
                    background_color = (30, 30, 30)
                    font_color = (255, 255, 255)
                elif msg == "light":
                    background_color = (255, 255, 255)
                    font_color = (0, 0, 0)
                else:
                    serial_command = msg

            except Exception as e:
                print(f"[串口读取错误] {e}")

threading.Thread(target=read_serial, daemon=True).start()

#恐龙类
class Dinosaur:
    def __init__(self):
        self.x = 50
        self.y = 300
        self.vel_y = 0
        self.gravity = 1
        self.jump_power = -15
        self.is_jumping = False
        self.is_crouching = False
        self.run_anim_index = 0

    def update(self, command):
        if command == "MODE_HOME":
            mode = "MDOE_HOME"
            return
        if command == "JUMP" and not self.is_jumping:
            self.vel_y = self.jump_power
            self.is_jumping = True
        elif command == "CROUCH" and not self.is_jumping:
            self.is_crouching = True
        else:
            self.is_crouching = False

        # 位置更新
        self.y += self.vel_y
        self.vel_y += self.gravity
        if self.y >= 300:
            self.y = 300
            self.is_jumping = False
            self.vel_y = 0

    def draw(self, screen):
        if self.is_jumping:
            screen.blit(dino_jump, (self.x, self.y))
        elif self.is_crouching:
            screen.blit(dino_crouch[self.run_anim_index // 5 % 2], (self.x, self.y + 20))
        else:
            screen.blit(dino_run[self.run_anim_index // 5 % 2], (self.x, self.y))
        self.run_anim_index += 1

    def get_mask_and_offset(self):
        if self.is_jumping:
            mask = pygame.mask.from_surface(dino_jump)
            offset_y = 0
        elif self.is_crouching:
            frame = self.run_anim_index // 5 % 2
            mask = pygame.mask.from_surface(dino_crouch[frame])
            offset_y = 15
        else:
            frame = self.run_anim_index // 5 % 2
            mask = pygame.mask.from_surface(dino_run[frame])
            offset_y = 0
        return mask, (int(self.x), int(self.y + offset_y))


#障碍类
class Obstacle:
    def __init__(self):
        self.x = SCREEN_WIDTH
        self.speed = 10
        self.type = random.choice(["cactus", "bird"])
        if self.type == "cactus":
            self.image = cactus_img
            self.y = 300
        else:
            self.image = bird_img
            self.y = 275

        self.mask = pygame.mask.from_surface(self.image)

    def move(self):
        self.x -= self.speed

    def draw(self, screen):
        screen.blit(self.image, (self.x, self.y))

    def collide(self, dino):
        dino_mask, dino_pos = dino.get_mask_and_offset()
        offset = (int(self.x - dino_pos[0]), int(self.y - dino_pos[1]))
        return dino_mask.overlap(self.mask, offset) is not None

#游戏主程序
def main():
    dino = Dinosaur()
    obstacles = []
    score = 0
    game_over = False
    mode = "MDOE_GAME"

    ser.write(b"START\n")

    while True:
        screen.fill(background_color)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                return

        if not game_over:
            # 更新恐龙状态
            dino.update(serial_command)
            if(mode=="MODE_HOME"):
                pygame.quit()
                return
            dino.draw(screen)

            # 障碍物更新
            if random.randint(0, 100) < 2:
                obstacles.append(Obstacle())

            for obstacle in obstacles:
                obstacle.move()
                obstacle.draw(screen)
                if obstacle.collide(dino):
                    game_over = True
                    ser.write(b"GAME_OVER\n")

            # 移除出界障碍
            obstacles = [o for o in obstacles if o.x > -50]

            # 分数更新
            score += 1
            pygame.display.set_caption(f"Dino Game - Score: {score}")

        else:
            font = pygame.font.SysFont(None, 60)
            text = font.render("Game Over!", True, font_color)
            screen.blit(text, (SCREEN_WIDTH // 2 - 150, SCREEN_HEIGHT // 2))

        pygame.display.update()
        clock.tick(FPS)

if __name__ == "__main__":
    main()