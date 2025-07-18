//
//  main.c
//  生成阶乘表
//
//  Created by 杨博文 on 2023/9/22.
//

#include <stdio.h>

/* 自定义函数的声明 */
double fact(int n)        /* 函数首部 */
{   int i;  double product;
    product = 1;
    for (i = 1; i <= n; i++)
        product = product * i;
 return  product;  /* 将结果回送主函数 */
}

int main(void)
{   int i, n;
    double result;
    printf("Enter n:");
    scanf("%d", &n);
    for (i = 0; i <= n ; i++)
    {
        result = fact(i);        /* 调用自定义函数fact(i)计算i! */
        printf("%d!=%.0f\n", i, result);
    }
   return 0;
}

