//
//  main.c
//  计算税金
//
//  Created by 杨博文 on 2023/10/13.
//

#include <stdio.h>
/*对一批货物征收税金。价格在1万以上（含一万元）的货物征税5%，在5000元以上（含5000元），一万元以下的货物征税3%，在1000元（含1000元）以上，5000元以下的货物征税2%，1000元以下的货物免税。编程序，读入货物的价格，计算并输出应缴的税金。
 输入货物价格
 输出税金，要求保留小数点后两位小数*/
int main(int argc, const char * argv[]) 
{
    double a,b;
    scanf("%lf",&a);
    if(a>=10000)
        b=a*0.05;
    else if(a>=5000)
        b=a*0.03;
    else if(a>=1000)
        b=a*0.02;
    else if(a>=0)
        b=0;
    printf("Tax=%.2lfyuan",b);
    return 0;
}
