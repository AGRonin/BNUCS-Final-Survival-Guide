//
//  main.c
//  欧几里得辗转相除法
//
//  Created by 杨博文 on 2023/10/20.
//

#include <stdio.h>
/*两个正整数的最大公约数是能够整除这两个整数的最大整数。采用欧几里得算法编写计算最大公约数的函数Gcd()，在主函数中调用该函数计算并输出从键盘任意输入的两整数的最大公约数。
 欧几里得算法：也称辗转相除法。对于正整数a和b，连续进行求余运算，直到余数为0为止，此时非0的除数就是最大公约数。设r=a mod b表示a除以b的余数，若r≠0，则将b作为新的a，r作为新的b，即Gcd（a，b）=Gcd（b，r），重复a mod b运算，直到r=0时为止，此时b为所求的最大公约数。例如，50和15的最大公约数的求解过程可表示为：Gcd（5015）=Gcd（155）=Gcd（5，0）=5。
 输入2个正整数。两数之间用空格隔开。
 输出1个数。这个数是最大公约数。*/
int gcd(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a>=b)
        a=a%b;
    else
        b=b%a;
    return gcd(a,b);
}
int main(int argc, const char * argv[]) {
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",gcd(a,b));
    return 0;
}
