//
//  main.c
//  组合数计算
//
//  Created by 杨博文 on 2023/9/16.
//

#include <stdio.h>

int jiecheng(int x)
{
    int i,ji;
    ji=1;
    for(i=1;i<=x;i++)
    {
        ji=ji*i;
    }
    return ji;
}

float fact(int m,int n)
{
    float result;
    result=jiecheng(m)/jiecheng(n)/jiecheng(m-n);
    return result;
}

int main(int argc, const char * argv[]) {
    /*编制程序，输入m,n(M>=n>=0)后,计算下列表达式的值并输出：
             m!/n! (m-n)!
    要求将计算阶乘运算的函数写为fact(n),函数返回值的类型为float
    输入m n
    输出对应表达式的值*/
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%.0f",fact(m,n));
    return 0;
}
