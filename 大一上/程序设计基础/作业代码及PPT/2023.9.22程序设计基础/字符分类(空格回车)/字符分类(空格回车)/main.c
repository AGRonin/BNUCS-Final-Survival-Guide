//
//  main.c
//  字符分类(空格回车)
//
//  Created by 杨博文 on 2023/9/22.
//
#include <stdio.h>
/*输入10个字符，分别统计出其中空格或回车、数字和其他字符的个数。*/
int main(void)
{
    int blank, digit, i, other;
    char ch;
    blank = digit = other = 0;
    printf("Enter 10 characters: ");
    for(i = 1; i <= 10; i++)
    {
        ch = getchar();
        switch (ch)
        {
            case ' ' :
            case '\n':
                blank ++;
                break;
            case '0' : case '1' : case '2' : case '3' : case '4' :case '5' : case '6' : case '7' : case '8' : case '9' :
                   digit ++;
                   break;
            default:
                   other ++;
                   break;
        }
    }
    printf("blank=%d, digit=%d, other=%d\n", blank, digit, other);
    return 0;
}
