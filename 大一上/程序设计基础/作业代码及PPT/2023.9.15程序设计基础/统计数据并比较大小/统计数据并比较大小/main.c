//
//  main.c
//  统计数据并比较大小
//
//  Created by 杨博文 on 2023/9/15.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*输入二个正整数n和m(0<n<=100，0=<m<=32767)，然后读取n个正整数a1, a2, a3...an(0=<a1,a2...,an<=32767)，统计n个正整数中多少个正整数的值小于m。
     输入第一行，两个正整数n和m。第二行，n个正整数。
     输出小于m的正整数个数。*/
    int n,m,i,geshu,x;
    scanf("%d%d",&n,&m);
    geshu=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x<m)
            geshu=geshu+1;
    }
    printf("%d",geshu);
    return 0;
}
