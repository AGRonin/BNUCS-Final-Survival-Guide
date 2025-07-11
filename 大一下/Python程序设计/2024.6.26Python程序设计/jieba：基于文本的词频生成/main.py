import jieba
from collections import Counter

# 读取文件
with open('WORD.txt', 'r', encoding='utf-8') as f:
    content = f.read()

# 使用jieba进行分词
words = jieba.lcut(content)

# 去除可能的单个字符的词（可选）
filtered_words = [word for word in words if len(word) > 1]

# 统计词频
word_counts = Counter(filtered_words)


# 将词频统计结果写入新的txt文件
def write_word_frequency_to_file(word_counts, output_file_path):
    with open(output_file_path, 'w', encoding='utf-8') as file:
        for word, count in word_counts.most_common():
            file.write(f'{word}:{count}\n')

write_word_frequency_to_file(word_counts,'output.txt')