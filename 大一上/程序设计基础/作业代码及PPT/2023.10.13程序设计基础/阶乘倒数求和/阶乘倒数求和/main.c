//
//  main.c
//  阶乘倒数求和
//
//  Created by 杨博文 on 2023/10/14.
//

#include <stdio.h>
/*  求s=1+1/2!+1/3!+…+1/10!
 无输入。
 输出所求的和，保留5位小数。*/
double jiecheng(double a)
{
    double i=1,result=1;
    while(i<=a)
    {
        result=result*i;
        i++;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    double a=1,b=0.0;
    while(a<=10)
    {
        b=b+1.0/jiecheng(a);
        a++;
    }
    printf("%.5f",b);
    return 0;
}
