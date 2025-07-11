import io
import wx
import random
from PIL import Image


class Bubble(wx.Control):#本代码基于文心大模型4.0生成，有所改动
    def __init__(self, parent, label, pos, size):
        super().__init__(parent, pos=pos, size=size)
        self.label = label #方向
        self.Bind(wx.EVT_PAINT, self.on_paint)
        self.Bind(wx.EVT_LEFT_DOWN, self.on_click)

    def on_paint(self, event):
        dc = wx.PaintDC(self)
        gc = wx.GraphicsContext.Create(dc)

        # 绘制圆形气泡
        gc.SetPen(wx.Pen('#BCA5F2', 2))
        gc.SetBrush(wx.Brush('#D0A5F2'))
        w, h = self.GetSize()
        radius = min(w, h) // 2
        gc.DrawEllipse(0, 0, w, h)

        # 绘制居中文本
        gc.SetFont(wx.Font(14, wx.FONTFAMILY_SWISS, wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_NORMAL), 'white')
        text_width, text_height = gc.GetTextExtent(self.label)
        text_x = (w - text_width) // 2
        text_y = (h ) // 2  # 修正后的垂直居中计算
        gc.DrawText(self.label, text_x, text_y)

    def on_click(self, event):
        Direction_Sub_Page(self.GetParent(), self.label,teacher_info_dictionary[self.label]).Show()


class PersonPanel(wx.Panel):
    def __init__(self, parent, photo_path, bio_path, wordcloud_path,new_page_text_path):
        super().__init__(parent)
        self.new_page_text_path=new_page_text_path

        # 创建一个垂直的布局管理器
        sizer = wx.BoxSizer(wx.VERTICAL)

        # 加载图片并添加到sizer
        image = wx.Image(photo_path, wx.BITMAP_TYPE_ANY)
        bitmap = image.ConvertToBitmap()
        image_ctrl = wx.StaticBitmap(self, wx.ID_ANY, bitmap)
        sizer.Add(image_ctrl, 0, wx.ALIGN_CENTER | wx.ALL, 10)

        # 加载文本并添加到sizer（使用TextCtrl以支持滚动）
        with open(bio_path, 'r', encoding='utf-8') as file:
            text_content = file.read()
        text_ctrl = wx.TextCtrl(self, wx.ID_ANY, text_content, style=wx.TE_READONLY | wx.TE_MULTILINE)
        text_ctrl.Bind(wx.EVT_LEFT_DOWN, self.OnTextLeftDown) # 绑定点击事件
        sizer.Add(text_ctrl, 1, wx.EXPAND | wx.ALL, 10)

        # 加载词云图并添加到sizer
        wordcloud_image = wx.Image(wordcloud_path, wx.BITMAP_TYPE_ANY)
        wordcloud_bitmap = wordcloud_image.ConvertToBitmap()
        wordcloud_ctrl = wx.StaticBitmap(self, wx.ID_ANY, wordcloud_bitmap)
        sizer.Add(wordcloud_ctrl, 0, wx.ALIGN_CENTER | wx.ALL, 10)

        # 设置面板的sizer
        self.SetSizer(sizer)

    def OnTextLeftDown(self, event):
        # 创建一个新页面（或窗口），并显示从某txt文件中接收到的文本信息
        with open(self.new_page_text_path, 'r', encoding='utf-8') as file:
            new_page_text = file.read()

            # 创建一个新的wx.Frame或wx.Dialog来显示文本
        new_frame = wx.Frame(None, title="新页面", size=(1200, 900))
        new_text_ctrl = wx.TextCtrl(new_frame, wx.ID_ANY, new_page_text, style=wx.TE_READONLY | wx.TE_MULTILINE)
        sizer = wx.BoxSizer(wx.VERTICAL)
        sizer.Add(new_text_ctrl, 1, wx.EXPAND | wx.ALL, 10)
        new_frame.SetSizer(sizer)
        new_frame.Show()
        new_frame.CenterOnScreen()


class Direction_Sub_Page(wx.Frame):
    def __init__(self, parent, text, people_info_list):
        super().__init__(parent, title=f"方向：{text}", size=(1200, 900))
        self.SetBackgroundColour('white')

        # 创建滚动窗口
        self.scrolled_window = wx.ScrolledWindow(self)
        self.scrolled_window.SetScrollRate(20, 20)  # 设置滚动速度，而不是滚动条参数

        # 创建一个GridSizer，每行3个元素
        grid_sizer = wx.GridSizer(rows=0, cols=3, hgap=10, vgap=10)

        # 添加欢迎文本
        static_text = wx.StaticText(self.scrolled_window, label=f"欢迎选择{text}作为方向！下面是本方向的一些导师：")
        # 为了GridSizer能正常工作，你可能需要将欢迎文本也放入一个sizer中，或者在这里简单设置位置

        # 假设people_info是一个列表，每个元素包含(photo_path, bio_path, wordcloud_path,new_page_text_path)
        for info in people_info_list:
            person_panel = PersonPanel(self.scrolled_window, *info)
            grid_sizer.Add(person_panel, 0, wx.EXPAND | wx.ALL, 5)

        grid_sizer.SetMinSize(400, 1000)

        # 如果需要，可以添加一个额外的sizer来包裹欢迎文本，但在这个例子中我们简单设置位置
        static_text_sizer = wx.BoxSizer(wx.VERTICAL)
        static_text_sizer.Add(static_text, 0, wx.ALIGN_CENTER | wx.ALL, 10)

        # 创建一个垂直sizer来管理欢迎文本和GridSizer
        vertical_sizer = wx.BoxSizer(wx.VERTICAL)
        vertical_sizer.Add(static_text_sizer, 0, wx.EXPAND | wx.ALL, 10)
        vertical_sizer.Add(grid_sizer, 1, wx.EXPAND | wx.ALL, 10)

        # 设置滚动窗口的sizer
        self.scrolled_window.SetSizer(vertical_sizer)
        self.scrolled_window.Layout()

        # 创建一个外层sizer来管理滚动窗口
        outer_sizer = wx.BoxSizer(wx.VERTICAL)
        outer_sizer.Add(self.scrolled_window, 1, wx.EXPAND | wx.ALL, 10)

        # 设置frame的sizer
        self.SetSizer(outer_sizer)
        self.CenterOnScreen()

        # 设置滚动窗口的最小大小，以便在内容少时也能滚动
        self.scrolled_window.SetMinSize((grid_sizer.GetMinSize()[0], grid_sizer.GetMinSize()[1]))

class ImagePanel(wx.Panel):
    def __init__(self, parent, image_path):
        super().__init__(parent)
        self.image_path = image_path
        self.Bind(wx.EVT_PAINT, self.OnPaint)

    def OnPaint(self, event):
        dc = wx.PaintDC(self)

        # 加载图片
        image = wx.Image(self.image_path, wx.BITMAP_TYPE_ANY)
        # 将图片转换为位图
        bitmap = image.ConvertToBitmap()

        # 绘制位图到面板上
        dc.DrawBitmap(bitmap, 350, 250)

class MainFrame(wx.Frame):#本代码基于文心大模型4.0生成，有所改动
    def __init__(self):
        super().__init__(parent=None, title='北京师范大学人工智能学院导师查询',size=(1200, 900))
        panel = ImagePanel(self, '/Users/yangbowen/Desktop/PieChart_500*400.jpg')
        self.SetBackgroundColour('white')
        self.CenterOnScreen()

        title_label = wx.StaticText(panel, -1, "你想学习的方向是", pos=(530, 30))
        font = wx.Font(18, wx.FONTFAMILY_SWISS, wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_NORMAL)
        title_label.SetFont(font)



        # 设定气泡的最小半径、最大半径和边距
        self.margin = 20
        self.bubbles = [{"label": "PieChart", "pos": (350,250), "size": (500,400)}]

        # 尝试放置气泡，直到所有气泡都成功放置
        for label in direction_list:
            dc=wx.ClientDC(self)
            dc.SetFont(wx.Font(14,wx.FONTFAMILY_SWISS,wx.FONTSTYLE_NORMAL,wx.FONTWEIGHT_BOLD))
            text_width,text_height=dc.GetTextExtent(label)
            self.min_radius = max(30,text_width,text_height)  # 最小半径
            self.max_radius = self.min_radius+30  # 最大半径
            while True:
                # 随机生成位置和半径，确保半径在最小和最大之间，自己写的
                radius = random.randint(self.min_radius, self.max_radius)  # 使用min_radius确保最小大小
                x = random.randint(self.margin+radius, self.GetSize()[0] - self.margin - 2 * radius)
                y = random.randint(self.margin+radius, self.GetSize()[1] - 2*self.margin - 2 * radius)
                size = (radius * 2, radius * 2)  # 气泡的宽和高都是直径
                pos = (x, y)

                # 检查新气泡是否与现有气泡重叠
                if not self.check_overlap(pos, size):
                    break

                if not self.check_overlap(pos, size):
                    break

            self.bubbles.append({"label": label, "pos": pos, "size": size})

        # 创建气泡控件
        for bubble_data in self.bubbles:
            if bubble_data["label"]!="PieChart":
                Bubble(panel, **bubble_data)

    def check_overlap(self, new_pos, new_size):
        """检查新气泡是否与现有气泡重叠"""
        new_x, new_y = new_pos
        new_width, new_height = new_size

        for bubble in self.bubbles:
            x, y = bubble['pos']
            width, height = bubble['size']

            if (new_x < x + width and new_x + new_width > x and
                    new_y < y + height and new_y + new_height > y):
                return True

        return False

#导师信息列表，手写
direction_list=['计算机图形学','计算机视觉','脑科学','图像视频处理','模式识别','自然语言处理','人工智能','计算机教育','机器学习','虚拟现实','深度学习']
teacher_info_dictionary={}
for direction in direction_list:
    teacher_info_dictionary[direction]=[('/Users/yangbowen/Desktop/pic.png','/Users/yangbowen/Desktop/WORD.txt','/Users/yangbowen/Desktop/wordcloud_300x150.png','/Users/yangbowen/Desktop/WORD.txt')]
    for i in range(5):
        teacher_info_dictionary[direction].append((('/Users/yangbowen/Desktop/pic.png','/Users/yangbowen/Desktop/WORD.txt','/Users/yangbowen/Desktop/wordcloud_300x150.png','/Users/yangbowen/Desktop/WORD.txt')))



app = wx.App(False)
frame = MainFrame()
frame.Show()
app.MainLoop()