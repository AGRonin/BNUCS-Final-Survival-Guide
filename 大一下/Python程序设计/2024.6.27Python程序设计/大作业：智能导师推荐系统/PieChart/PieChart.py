def PieChart_function():
    import matplotlib.pyplot as plt
    import pandas as pd
    from PIL import Image
    plt.rcParams['font.sans-serif'] = ['STFangsong']#设置成仿宋字体
    # 选择一组好看的颜色
    colors = ['#BE9AF9', '#F99ACF', '#CD81F9', '#9D9EF5', '#9DE1F5', '#9CC3E8', '#4EC8F5', '#4EF5A3', '#66FA0A', '#FDFF00','#E7B200']
    csv_file = '人工智能学院各个研究方向导师.csv'
    df = pd.read_csv(csv_file)
    Number_tutor = df['导师数量'].tolist()
    Research_direction = df['研究方向'].tolist()
    total = sum(Number_tutor)
    percentages = [number/total*100 for number in Number_tutor]
    fig,ax = plt.subplots()
    ax.pie(percentages, labels=Research_direction, autopct='%1.1f%%', startangle=90, colors = colors)
    ax.axis('equal')  # 确保饼图是圆形的
    plt.title('人工智能学院各个研究方向导师分布百分比')
    # 保存图片为.jpg格式
    output_file = 'PieChart/PieChart.jpg'
    plt.savefig(output_file, bbox_inches='tight')  # bbox_inches='tight' 用于去掉多余的空白
    plt.savefig(output_file, dpi=300, bbox_inches='tight')  # dpi设置图片分辨率
    #调整文件大小
    img = Image.open('PieChart/PieChart.jpg')
    img_resized = img.resize((500, 400))
    # 保存调整大小后的词云图像
    img_resized.save('PieChart/PieChart_500*400.jpg')