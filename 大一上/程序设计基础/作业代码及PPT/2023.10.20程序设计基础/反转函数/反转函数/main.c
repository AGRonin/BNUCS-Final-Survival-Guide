//
//  main.c
//  反转函数
//
//  Created by 杨博文 on 2023/10/20.
//

#include <stdio.h>
/*数字反转：
 编写一个函数reverse，其功能是将一个正整数反转。如123可以反转为321，3682可以反转为2863，1200可以反转为21。
 reverse函数的原型可以参考如下：返回值类型 reverse (int num);其中num为要反转的数，函数的返回值为反转后的数。
 从键盘上输入一个正整数n，代表要反转的数的个数，接着输入n个正整数，将这些正整数依次反转并输出。输出的数据之间用空格分隔。
 输入8 24367 19791 6759 18283 13165 18027 14290 5675
 输出76342 19791 9576 38281 56131 72081 9241 5765 */

void reverse(int num,int jishu)
{
    if(num!=0)
    {
        if(num%10==0 && jishu==0);
        else
        {
            printf("%d",num%10);
            jishu=1;
        }
        num=num/10;
        reverse(num,jishu);
    }
}

int main(int argc, const char * argv[]) 
{
    int n;
    scanf("%d",&n);
    int liebiao[n];
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&liebiao[i-1]);
    }
    for(int i=1;i<=n;i++)
    {
        int jishu=0;
        reverse(liebiao[i-1],jishu);
        if(i!=n)
            printf(" ");
    }
    return 0;
}
