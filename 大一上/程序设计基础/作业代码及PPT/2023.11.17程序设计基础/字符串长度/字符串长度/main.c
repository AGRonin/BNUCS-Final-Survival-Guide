//
//  main.c
//  字符串长度
//
//  Created by 杨博文 on 2023/11/21.
//

#include <stdio.h>
/*自己写一个函数，求字符串的长度。
 在main函数中输入一个字符串，调用你写的函数，得到字符串的长度，并在main函数中输出该字符串的长度。使用指针完成。
 输入一行字符串（以回车结束），可含空格。
 输出一个整数，对应输入字符串的长度。单独占一行。*/
int main(int argc, const char * argv[]) {
    char *x,p[100];
    gets(p);
    int i=0;
    for(x=p;*x!='\0';*x++)
    {
        i++;
    }
    printf("%d",i);
    return 0;
}
