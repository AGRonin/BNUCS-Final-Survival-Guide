//
//  main.c
//  回文素数
//
//  Created by 杨博文 on 2023/9/22.
//
/*输入最小值最大值，最大值<=100000，输出区间内的所有回文素数，十个一行*/
#include <stdio.h>
#include <math.h>
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

int huiwenpanduan(int a)
{
    int panduan,haishipanduan;
    if(a<10)
        return 1;
    else if(a<100)
    {
        if(a%11==0)
            return 1;
    }
    else if(a<1000)
    {
        if(a/100+a/10*10==a)
            return 1;
    }
    else if(a<10000)
    {
        if(a/1000+a/10==a && (a-a/1000*1001)%110==0)
            return 1;
    }
    else if(a<100000)
    {
        if(a/10000+a/10*10==a)
        {
            panduan=(a-a/10000*10001)/10;
            if(panduan<100 && panduan%10==0)
                return 1;
            else if(panduan<100)
                return 0;
            haishipanduan=huiwenpanduan(panduan);
            return haishipanduan;
        }
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    int m,n,i,panduan1,panduan2,geshu;
    geshu=0;
    scanf("%d%d",&m,&n);
    for(i=m;i<=n;i++)
    {
        panduan1=sushupanduan(i);
        panduan2=huiwenpanduan(i);
        if(panduan1==1 && panduan2==1)
        {
            geshu=geshu+1;
            if(geshu==1)
                printf("%d",i);
            else if(geshu%10==1)
                printf("\n%d",i);
            else
                printf(" %d",i);
        }
    }
}
