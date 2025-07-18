//
//  main.c
//  删除数组中的x
//
//  Created by 杨博文 on 2023/10/27.
//

#include <stdio.h>
/*在读入的包括n个整数的数组中查找，是否有元素等于读入的Ｘ，如果没有找到则输出“no”，如果找到，那么将数组中所有的的X删除，然后输出删除后的新数组。
 输入 包括三行，第一行有一个整数n；第二行有n个整数；第三行有一个整数X，为要查找的数。
 输出 如果没有找到则输出“no”，如果找到，那么将数组中所有的的X删除，然后输出删除后的新数组。*/
void dayin(int shuzu[],int geshu)
{
    for(int i=0;i<geshu-1;i++)
    {
        printf("%d ",shuzu[i]);
    }
    printf("%d",shuzu[geshu-1]);
}

int main(int argc, const char * argv[]) {
    int geshu,shanchu,i=0,k=0;
    scanf("%d",&geshu);
    int shuzu[geshu],genggai[geshu];
    for(i=0;i<geshu;i++)
    {
        int x;
        scanf("%d",&x);
        shuzu[i]=x;
    }
    scanf("%d",&shanchu);
    int kongge=0;
    i=0;
    while(i<geshu)
    {
        if(shuzu[i]!=shanchu)
        {
            genggai[i-k]=shuzu[i];
        }
        else
        {
            k++;
        }
        i++;
    }
    if(k==0)
        printf("no");
    else
    {
        dayin(genggai,geshu-k);
    }
    return 0;
}
