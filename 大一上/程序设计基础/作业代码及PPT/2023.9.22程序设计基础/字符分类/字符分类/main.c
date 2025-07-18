//
//  main.c
//  字符分类
//
//  Created by 杨博文 on 2023/9/22.
//

#include <stdio.h>
int main(void)
{
    int digit, i, letter, other;
    char ch;
    digit = letter = other = 0;
    printf("Enter 10 characters: ");
    for(i = 1; i <= 10; i++)
    {
        ch = getchar();     /* 从键盘输入一个字符，赋值给变量 ch */
        if((ch >= 'a' && ch <= 'z' ) || ( ch >= 'A' && ch <= 'Z'))
            letter ++;
        else if(ch >= '0' && ch <= '9')   /* 如果ch是数字字符 */
            digit ++;
        else
            other ++;
    }
    printf("letter=%d,digit=%d,other=%d\n",letter,digit,other);
    return 0;
}
