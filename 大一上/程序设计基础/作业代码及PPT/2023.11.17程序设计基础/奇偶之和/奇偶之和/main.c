//
//  main.c
//  奇偶之和
//
//  Created by 杨博文 on 2023/11/21.
//

#include <stdio.h>
/*编写一个函数mySum，其功能是计算一个数组中的所有奇数之和与偶数之和。
 函数原型可参考如下：void  mySum(int *p,  int len,  int *sumOdd,  int *sumEven);
 其中，p为指向数组首元素的指针，len为数组中的元素个数，sumOdd为指向所求奇数之和的指针，sumEven为指向所求偶数之和的指针。
 编写程序，从键盘输入一个正整数n(1<=n<=100)，代表数据元素个数，接着输入n个整数，代表数组元素的初始值，调用mySum函数处理完毕后，在主函数中输出计算出的奇数之和与偶数之和。输出的两个数据之间用空格分隔。
 输入6 3 10 5 6 9 4
 输出17 20*/
void mySum(int *p,int len,int *sumOdd, int *sumEven)
{
    for(int i=0;i<len;i++,*p++)
    {
        if(*p%2==0)
        {
            *sumOdd+=*p;
        }
        else
        {
            *sumEven+=*p;
        }
    }
}
int main(int argc, const char * argv[]) {
    int len,*sumOdd,*sumEven;
    int sumodd=0,sumeven=0;
    sumOdd=&sumodd;
    sumEven=&sumeven;
    scanf("%d",&len);
    int shu[len];
    for(int i=0;i<len;i++)
    {
        scanf("%d",&shu[i]);
    }
    mySum(shu,len,sumOdd,sumEven);
    printf("%d %d",*sumEven,*sumOdd);
    return 0;
}
