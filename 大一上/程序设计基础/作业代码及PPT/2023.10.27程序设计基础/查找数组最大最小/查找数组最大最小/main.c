//
//  main.c
//  查找数组最大最小
//
//  Created by 杨博文 on 2023/10/27.
//

#include <stdio.h>
/*从键盘上读入n个整数，从这n个整数中找出最大值和最小值，以及最大值和最小值的位置。
 输入
 第一行一个整数n（n<100)；
 第二行n个以空格相隔的整数（每个数在[1,1000])。
 输出
 第一行最大值和最大值的位置，它们之间以空格相隔；
 第二行最小值和最小值的位置，它们之间以空格相隔;
 如果最值重复出现，则位置之间按照位置由前到后的顺序以空格相隔。*/
int main(int argc, const char * argv[]) {
    int geshu,j,k;
    scanf("%d",&geshu);
    int shuzu[geshu];
    int max=1,min=1000;
    for(int i=0;i<geshu;i++)
    {
        int x;
        scanf("%d",&x);
        shuzu[i]=x;
        if(x>=max)
        {
            max=x;
            j=i;
        }
        if(x<=min)
        {
            min=x;
            k=i;
        }
    }
    printf("%d ",max);
    for(int i=0;i<j;i++)
    {
        if(shuzu[i]==max)
        {
            printf("%d ",i+1);
        }
    }
    printf("%d\n",j+1);
    printf("%d ",min);
    for(int i=0;i<k;i++)
    {
        if(shuzu[i]==min)
        {
            printf("%d ",i+1);
        }

    }
    printf("%d",k+1);
    return 0;
}
