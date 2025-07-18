//
//  main.c
//  求孪生素数
//
//  Created by 杨博文 on 2023/10/20.
//

#include "prime.h"
/*两个差为2的素数称之为孪生素数。现在输入整数n,求n以内的所有孪生素数对。要求定义并调用函数prime(m)判断m是否为素数，当m为素数时返回1，否则返回0。
输入一行：一个整数n (3<n<10000)
输出若干行，每一行为一对相差为2的素数*/
int main(int argc, const char * argv[]) 
{
    int n;
    scanf("%d",&n);
    printf("3 5");
    for(int m=5;m<=n;m=m+2)
    {
        if(prime(m)==1 && prime(m+2)==1)
        {
            printf("\n%d %d",m,m+2);
        }
    }
    return 0;
}
