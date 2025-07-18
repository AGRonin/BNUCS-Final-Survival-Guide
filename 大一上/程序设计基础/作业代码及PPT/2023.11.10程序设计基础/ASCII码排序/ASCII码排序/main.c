//
//  main.c
//  ASCII码排序
//
//  Created by 杨博文 on 2023/11/11.
//

#include <stdio.h>
/*众所周知，字符在C语言中是使用ASCII码进行表示的。现要求输入3个字符（可以重复）后，按各字符的ASCII码从小到大的顺序输出这3个字符。
 输入第一行输入一个数N,表示有N组测试数据。后面的N行输入多组数据，每组输入数据都是占一行，有三个字符组成，之间无空格。
 输出对于每组输入数据，输出一行，字符中间用一个空格分开。*/
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d \n",&n);
    char zu[n][3];
    for(int i=0;i<n;i++)
    {
        scanf("%c%c%c \n",&zu[i][0],&zu[i][1],&zu[i][2]);
    }
    for(int i=0;i<n;i++)
    {
        char a,b,c;
        char x=zu[i][0],y=zu[i][1],z=zu[i][2];
        if(x>=y)
        {
            if(y>=z)
            {
                a=z;b=y;c=x;
            }
            else if(x>=z)
            {
                a=y;b=z;c=x;
            }
            else
            {
                a=y;b=x;c=z;
            }
        }
        else
        {
            if(y<=z)
            {
                a=x;b=y;c=z;
            }
            else if(x>=z)
            {
                a=z;b=x;c=y;
            }
            else
            {
                a=x;b=z;c=y;
            }
        }
        printf("%c %c %c",a,b,c);
        if(i!=n-1)
        {
            printf("\n");
        }
    }
    return 0;
}
