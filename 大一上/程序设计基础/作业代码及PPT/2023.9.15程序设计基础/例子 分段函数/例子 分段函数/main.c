//
//  main.c
//  例子 分段函数
//
//  Created by 杨博文 on 2023/9/15.
//

#include <stdio.h>
int main(void)
{
    double x, y;
    printf("Enter x (x>=0):\n");  /* 输入提示 */
    scanf("%lf", &x);                  /* 调用scanf函数输入数据 */
    if(x <= 15)                        /*  if – else语句 */
         y = 4 * x / 3;
    else if (x>15)
         y = 2.5 * x - 10.5;
    printf("y = f(%.2f) = %.2f\n", x, y);
    return 0;
}

