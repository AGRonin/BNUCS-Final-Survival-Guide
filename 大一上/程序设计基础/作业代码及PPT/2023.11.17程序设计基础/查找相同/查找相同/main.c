//
//  main.c
//  查找相同
//
//  Created by 杨博文 on 2023/11/21.
//

#include <stdio.h>
/*编写一个函数find，其功能是在一个长度为len的整型数组中查找整数num。
 函数原型可参考如下：int  find (int *p,  int  len,  int  num);
 其中，p为指向数组首元素的指针，len为数组中的元素个数，num为待查找的整数。
 如果能找到欲查找的数，则函数返回1，找不到则返回0。
 编写程序，从键盘输入一个正整数n(1<=n<=100)，代表数据元素个数，接着输入n个整数，代表数组元素的初始值，最后输入要查找的数m，调用find函数进行查找，如果能找到该数，则输出"YES"，如果找不到，则输出"NO"。
 输入7 13 39 63 23 14 72 61 14
 输出YES*/
int find(int *p,int len,int num)
{
    int zhishi=0;
    for(int i=0;i<len;i++,p++)
    {
        if(*p==num)
            zhishi=1;
    }
    return zhishi;
}
int main(int argc, const char * argv[]) {
    int len,num;
    scanf("%d",&len);
    int shu[len];
    for(int i=0;i<len;i++)
    {
        scanf("%d",&shu[i]);
    }
    scanf("%d",&num);
    char *x=(find(shu,len,num))?"YES":"NO";
    printf(x);
    return 0;
}
