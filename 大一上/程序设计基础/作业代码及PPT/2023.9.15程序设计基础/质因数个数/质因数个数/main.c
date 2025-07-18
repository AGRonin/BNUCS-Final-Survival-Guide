//
//  main.c
//  质因数个数
//
//  Created by 杨博文 on 2023/9/16.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]){
    /*任给一个自然数n，求出这个自然数不同因数的个数。
     如：n=6时，因为1，2，3，6这四个数均是6的因数，故输出为4。
     输入 一个自然数n，不超过2147483647。
     输出 n的因数个数。*/
    int n,i,yinshugeshu;
    float sqrtn;
    scanf("%d",&n);
    yinshugeshu=0;
    sqrtn=sqrt(n);
    for(i=1;i<=sqrtn;i++)
    {
        if(n%i==0)
            yinshugeshu=yinshugeshu+2;
        if(i==sqrtn)
            yinshugeshu=yinshugeshu-1;
    }
    printf("%d",yinshugeshu);
    return 0;
}
