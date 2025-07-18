//
//  main.c
//  同构数
//
//  Created by 杨博文 on 2023/9/16.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*同构数是这样一种数：它出现在它的平方数的右端。例如：5的平方是25，5就是同构数，25的平方是625，25也是构数。找出1~N之间（包括N）的全部同构数。
     输入 正整数N，N<＝32767。
     输出 1~N之间的全部同构数，从小到大排列，用空格隔开。*/
    int n,i,weishu,zancun;
    scanf("%d",&n);
    zancun=1;
    for(i=2;i<=n;i++)
    {
        if(i>=1 && i<10)
            weishu=10;
        if(i>=10 && i<100)
            weishu=100;
        if(i>=100 && i<1000)
            weishu=1000;
        if(i>=1000 && i<10000)
            weishu=10000;
        if(i>=10000 && i<100000)
            weishu=100000;
        if((i*i-i)%weishu==0)
        {
            printf("%d ",zancun);
            zancun=i;
        }
    }
    printf("%d",zancun);
    return 0;
}
