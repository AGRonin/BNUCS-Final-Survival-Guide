//
//  main.c
//  递增数列的插入
//
//  Created by 杨博文 on 2023/10/27.
//

#include <stdio.h>
/*将一个整数X插入到N个有序的数列中，插入后数列仍然有序。
 输入共三行，第一行一个整数n（n<100000），表示有n个有序的整数（小于32767）；第二行n个有序的整数序列（从小到大）；第三行，插入有序序列中的整数X。
 输出一行，插入整数X后的有序序列。*/
int main(int argc, const char * argv[])
{
    int geshu,charu,i=0,jiance=0;
    scanf("%d",&geshu);
    int shuzu[geshu];
    for(i=0;i<geshu;i++)
    {
        int x;
        scanf("%d",&x);
        shuzu[i]=x;
    }
    scanf("%d",&charu);
    for(i=0;i<geshu;i++)
    {
        if(shuzu[i]<charu)
            printf("%d",shuzu[i]);
        else if(jiance==0)
        {
            printf("%d %d",charu,shuzu[i]);
            jiance=1;
        }
        else
            printf("%d",shuzu[i]);
        if(i!=geshu-1)
            printf(" ");
    }
    if(jiance==0)
        printf(" %d",charu);
    return 0;
}
