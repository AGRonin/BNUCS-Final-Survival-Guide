//
//  main.c
//  移0
//
//  Created by 杨博文 on 2023/11/17.
//

#include <stdio.h>
/*编写一个函数myMove，其功能是将一个数组中的所有为0的元素移至数组末尾，并保持数组非0元素的相对顺序不变。
 函数原型可参考如下：
 void  myMove(int *p, int len);
 其中，p为指向数组首元素的指针，len为数组中的元素个数。
 如，数组中的原始数据为:1，0，3，4，0，2，5。则经过函数处理后的数组元素为:1，3，4，2，5，0，0。
 编写程序，从键盘输入一个正整数n(1<=n<=100)，代表数据元素个数，接着输入n个整数（其中包含若干个0），代表数组元素的初始值，调用myMove函数处理完毕后，输出最终的数据元素，元素之间用空格分隔。*/
void myMove(int *p,int len)
{
    int *px,j=0,k;
    px=p;
    for(int i=0;i<len;i++)
    {
        k=*px;
        if(k!=0)
        {
            j++;
            *p=k;
            *p++;
        }
        *px++;
    }
    for(;j<len;j++)
    {
        *p=0;
        *p++;
    }
}
int main(int argc, const char * argv[]) {
    int len;
    scanf("%d",&len);
    int su[len];
    for(int i=0;i<len;i++)
    {
        scanf("%d",&su[i]);
    }
    myMove(su, len);
    for(int i=0;i<len-1;i++)
    {
        printf("%d ",su[i]);
    }
    printf("%d",su[len-1]);
    return 0;
}
