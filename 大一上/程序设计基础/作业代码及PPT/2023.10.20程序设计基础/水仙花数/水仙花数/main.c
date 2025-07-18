//
//  main.c
//  水仙花数
//
//  Created by 杨博文 on 2023/10/20.
//

#include <stdio.h>
/*求100－999中的水仙花数，（若三位数abc，abc＝a^3+b^3+c^3， 则称abc为水仙花数。如153，1^3+5^3+3^3=1+125+27=153，则153是水仙花数）
 
 要求定义并调用函数is(number)判断number的各位数字之立方和是否等于其自身。
 无输入
 输出每行一个整数*/
int is(int a)
{
    int b,c,d;
    b=a/100;
    c=(a-100*b)/10;
    d=a-100*b-10*c;
    if(a==b*b*b+c*c*c+d*d*d)
        return 1;
    return 0;
}
int main(int argc, const char * argv[]) 
{
    for(int i=100;i<=999;i++)
    {
        if(is(i)==1)
            printf("%d\n",i);
    }
    return 0;
}
