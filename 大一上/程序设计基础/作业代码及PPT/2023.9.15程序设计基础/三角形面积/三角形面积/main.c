//
//  main.c
//  三角形面积
//
//  Created by 杨博文 on 2023/9/15.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    /*输入三个正整数，若能用这三个数作为边长组成三角形，就计算并输出该三角形的面积，否则输出Can't。(组成三角形的条件为：任意两边之和大于第三边)。
    输入 三个正整数（不大于100），表示三角形的三条边。
    输出 三角形的面积（保留2位小数）或Can't。*/
    int a,b,c;
    double d,p;
    scanf("%d%d%d",&a,&b,&c);
    if((a+b-c)*(b+c-a)*(c+a-b)>0)
    {
        p=(a+b+c)/2.0;
        d=sqrt(p*(p-a)*(p-b)*(p-c));
        printf("%.2f\n",d);
    }
    else
        printf("Can't\n");
    return 0;
}
