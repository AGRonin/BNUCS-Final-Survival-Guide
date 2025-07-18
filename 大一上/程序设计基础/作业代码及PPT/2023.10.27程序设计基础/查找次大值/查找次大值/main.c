//
//  main.c
//  查找次大值
//
//  Created by 杨博文 on 2023/10/27.
//

#include <stdio.h>
/*首先从键盘输入一个正整数n（1<n<=100,代表数组元素个数），接着输入n个整数（代表数组元素）。然后查找并输出数组元素中的次大值（即第二大值，不包括并列元素）。
 输入 10 48 97 77 52 79 51 28 76 70 29
 输出 79 */
int main(int argc, const char * argv[]) {
    int geshu,max,second;
    scanf("%d",&geshu);
    int shuzu[geshu];
    for(int i=0;i<geshu;i++)
    {
        int x;
        scanf("%d",&x);
        shuzu[i]=x;
        if(i==0)
        {
            max=x;
            second=x;
        }
        if(x>max)
        {
            second=max;
            max=x;
        }
        if(second<x && x!=max)
        {
            second=x;
        }
    }
    printf("%d",second);
    return 0;
}
