//
//  main.c
//  求数字和
//
//  Created by 杨博文 on 2023/9/15.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    /*对于一个任意的三位自然数X，编程计算其各个数位上的数字之和S。
    输入一行，只有一个整数x(100<=x<=999)
    输出只有一行，包括1个整数*/
    int a,sum;
    scanf("%d",&a);
    sum=a%10+(a/10)%10+a/100%10;
    printf("%d",sum);
    return 0;
}
