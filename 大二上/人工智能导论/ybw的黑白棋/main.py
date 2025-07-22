# 导入黑白棋文件
from game import Game
from Human_player import HumanPlayer
from Random_player import RandomPlayer
from AIPlayer import AIPlayer

print("欢迎进入黑白棋游戏。下面请选择游戏模式。")

a=int(input("你希望黑棋的执棋者是：1.人类 2.电脑随机 3.AI  请输入数字"))
if a==1:
    black_player = HumanPlayer("X")
elif a==2:
    black_player = RandomPlayer("X")
elif a==3:
    black_player = AIPlayer("X")
else:
    print("输入错误")
    exit(1)

b=int(input("你希望白棋的执棋者是：1.人类 2.电脑随机 3.AI  请输入数字"))
if b==1:
    white_player = HumanPlayer("O")
elif b==2:
    white_player = RandomPlayer("O")
elif b==3:
    white_player = AIPlayer("O")
else:
    print("输入错误")
    exit(1)

# 游戏初始化，第一个玩家是黑棋，第二个玩家是白棋
game = Game(black_player, white_player)

# 开始下棋
game.run()