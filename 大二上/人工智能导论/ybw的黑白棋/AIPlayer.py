import math
import random
import time
from copy import deepcopy

class MCTSNode:
    def __init__(self, board, current_player, parent=None, action=None):
        self.board = deepcopy(board)      # 当前棋盘状态
        self.current_player = current_player  # 当前玩家颜色
        self.parent = parent              # 父节点
        self.action = action              # 导致当前节点的动作
        self.children = []                # 子节点列表
        self.visits = 0                   # 访问次数
        self.wins = 0                     # 胜利次数

    def is_fully_expanded(self):
        # 检查是否所有子节点都已扩展
        return len(self.children) == len(list(self.board.get_legal_actions(self.current_player)))

    def expand(self):
        # 扩展节点，生成一个新的子节点
        actions = list(self.board.get_legal_actions(self.current_player))
        random.shuffle(actions)
        for action in actions:
            if not any(child.action == action for child in self.children):
                # 如果该动作还未被探索，则创建新节点
                new_board = deepcopy(self.board)
                new_board._move(action, self.current_player)
                next_player = 'O' if self.current_player == 'X' else 'X'
                child_node = MCTSNode(new_board, next_player, self, action)
                self.children.append(child_node)
                return child_node
        return None

    def best_child(self,exploration_weight=1.41):
        if not self.children:
            if not self.children:
                return self
        # 使用UCT公式选择最佳子节点
        return max(self.children, key=lambda child: child.wins / child.visits + math.sqrt(2 * math.log(self.visits) / child.visits))

    def backpropagate(self, result):
        # 反向传播
        self.visits += 1
        self.wins += result
        if self.parent:
            self.parent.backpropagate(result)

class AIPlayer:
    """
    AI 玩家
    """

    def __init__(self, color):
        """
        初始化AI玩家。
        :param color: 'X' 表示黑子，'O' 表示白子
        :param time_limit: 落子的时间限制，单位为秒
        """
        self.color = color
        self.time_limit = 60  # 时间限制

    def get_move(self, board):
        """
        根据当前棋盘状态获取最佳落子位置
        :param board: 棋盘
        :return: action 最佳落子位置, e.g. 'A1'
        """
        if self.color == 'X':
            player_name = '黑棋'
        else:
            player_name = '白棋'
        print("请等一会，对方 {}-{} 正在思考中...".format(player_name, self.color))

        # -----------------请实现你的算法代码--------------------------------------
        root = MCTSNode(board, self.color)
        start_time = time.time()

        # 在规定的时间内执行模拟
        while time.time() - start_time < self.time_limit:
            node = self.tree_policy(root,board)  # 在树中选择要探索的节点
            if node == root:  # 若选回根节点，随机选择一个合法落子点
                actions = list(board.get_legal_actions(self.color))
                if actions:
                    action = random.choice(actions)
                    return action
            result = self.default_policy(node)  # 在该节点执行模拟
            node.backpropagate(result)  # 将结果回传给父节点

        # 返回访问次数最多的子节点的动作，即最佳落子位置
        best_child = max(root.children, key=lambda child: child.visits)
        if best_child is None:
            return None
        return best_child.action if best_child else None


    def tree_policy(self, node, board):
        """
        树策略：根据MCTS规则在树中选择要探索的节点
        """
        while not self.is_game_over(node.board):
            if not node.is_fully_expanded():
                expanded_node = node.expand()
                if expanded_node is not None:
                    return expanded_node
            else:
                node = node.best_child()
        return node


    def default_policy(self, node):
        """
        默认策略：从指定节点开始，随机模拟至游戏结束并返回结果
        """
        board_copy = deepcopy(node.board)
        current_color = node.current_player
        while not self.is_game_over(board_copy):  # 使用 is_game_over() 方法检查游戏结束
            legal_actions = list(board_copy.get_legal_actions(current_color))
            if not legal_actions:
                break
            action = random.choice(legal_actions)  # 随机选择一个合法落子位置
            board_copy._move(action, current_color)
            current_color = 'O' if current_color == 'X' else 'X'  # 切换玩家

        # 假设游戏结束后获得赢家，如果AI赢了则返回1，输了则返回0
        winner = self.get_winner(board_copy)
        if winner == self.color:
            return 1
        elif winner is None:
            return 0.5  # 平局
        else:
            return 0


    def is_game_over(self, board):
        """
        检查游戏是否结束，替代 Game 类的 game_over 方法
        """
        # 实现你自己的游戏结束逻辑
        return len(list(board.get_legal_actions('X'))) == 0 and len(list(board.get_legal_actions('O'))) == 0


    def get_winner(self, board):
        """
        获取游戏的赢家
        """
        # 实现你自己的判断赢家逻辑
        black_count = board.count('X')
        white_count = board.count('O')
        if black_count > white_count:
            return 'X'
        elif white_count > black_count:
            return 'O'
        else:
            return None