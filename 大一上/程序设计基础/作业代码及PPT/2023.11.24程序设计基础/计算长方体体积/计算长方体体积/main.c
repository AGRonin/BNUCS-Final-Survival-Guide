//
//  main.c
//  计算长方体体积
//
//  Created by 杨博文 on 2023/11/24.
//

#include <stdio.h>
/*需要求3个长方体的体积，请编写一个使用结构体的程序，数据成员包括length（长）、width（宽）、height（高）。要求实现以下功能：
 （1）由键盘输入长宽高；
 （2）计算体积并输出。
 输入每一行输入一个长方形的长宽高，中间有一个空格间隔。
 输出每一行输出长方体的体积。*/
struct data{
    int length;
    int width;
    int height;
}x[10];
int main(int argc, const char * argv[]) {
    int j=0;
    for(int i=0;i<10;i++)
    {
        scanf("%d %d %d",&x[i].length,&x[i].width,&x[i].height);
        char ch=getchar();
        if(ch==EOF)
        {
            j=i+1;
            break;
        }
    }
    for(int i=0;i<j;i++)
    {
        printf("%d\n",x[i].length*x[i].width*x[i].height);
    }
    return 0;
}
