//
//  main.c
//  最大孪生素数
//
//  Created by 杨博文 on 2023/10/14.
//

#include <stdio.h>
#include <math.h>
/*如果n和n+2都是素数，则称它们是孪生素数。输入m，输出两个数均不超过m的最大孪生素数。5≤m≤1000000。例如m=20时答案是17、19，m=1000时答案是881、883。
输入正整数m，5≤m≤10000。
输出不超过m的最大孪生素数，小数在前，大数在后，中间用一个空格分隔。*/
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
    int n,m,panduan1,panduan2;
    scanf("%d",&n);
    m=(n-3)/2*2+1;
    while(1)
    {
        panduan1=sushupanduan(m);
        if(panduan1==1)
        {
            panduan2=sushupanduan(m+2);
            if(panduan2==1)
            {
                printf("%d %d",m,m+2);
                break;
            }
        }
        m=m-2;
    }
    return 0;
}
