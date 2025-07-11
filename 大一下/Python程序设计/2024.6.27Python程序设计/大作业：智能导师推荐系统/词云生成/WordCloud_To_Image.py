def WordCloud_To_Image_function(folder_path) :
    import jieba
    from collections import Counter
    from wordcloud import WordCloud
    from PIL import Image

    # 读取文件
    with open(folder_path+'/文本信息.txt', 'r', encoding='utf-8') as f:
        content = f.read()

    # 使用jieba进行分词
    words = jieba.lcut(content)

    # 去除可能的单个字符的词（可选）
    filtered_words = [word for word in words if len(word) > 1]

    # 统计词频
    word_counts = Counter(filtered_words)

    # 创建词云对象
    wordcloud = WordCloud(font_path='/System/Library/Fonts/PingFang.ttc',  # 设置字体文件路径，确保支持中文
                          background_color='white',  # 设置背景颜色
                          max_words=100,  # 最多显示的词数
                          max_font_size=100,  # 字体最大值
                          min_font_size=10  # 字体最小值
                          ).generate_from_frequencies(word_counts)

    # 将词云保存为临时文件（可以使用较大的尺寸以获得更好的质量）
    wordcloud.to_file(folder_path+'/wordcloud_temp.png')

    # 使用PIL/Pillow加载并调整图像大小
    from PIL import Image

    img = Image.open(folder_path+f'/wordcloud_temp.png')
    img_resized = img.resize((300, 150))

    # 保存调整大小后的词云图像
    img_resized.save(folder_path+f'/wordcloud.png')