//
//  main.c
//  输出质数
//
//  Created by 杨博文 on 2023/10/14.
//

#include <stdio.h>
#include <math.h>
/*输入一个整数n 输出N以内的所有素数
 Input 一个整数n
 Output 由小到大输出N以内的所有素数 每行一个数 */
int sushupanduan(int a)
{
    int b;
    float sqrta;
    sqrta=sqrt(a);
    for(b=2;b<=sqrta;b++)
    {
        if(a%b==0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    int n,i=3;
    scanf("%d",&n);
    printf("2\n");
    while(i<=n)
    {
        int a;
        a=sushupanduan(i);
        if(a==1)
            printf("%d\n",i);
        i=i+2;
    }
    return 0;
}
