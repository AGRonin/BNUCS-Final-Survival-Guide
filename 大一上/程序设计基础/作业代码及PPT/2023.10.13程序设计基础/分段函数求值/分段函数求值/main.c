//
//  main.c
//  分段函数求值
//
//  Created by 杨博文 on 2023/10/13.
//

#include <stdio.h>
    /*有一个函数y=f(x)的表达式如下：
     当x<1时，y=x
     当1<=x<10时，y=2x-1
     当x>=10时，y=3x-11
     输入x的值，输出y相应的值（保留两位小数）。
     末尾换行。*/
int main()
{
    float x,y;
    scanf("%f",&x);
    if(x<1)
        y=x;
    else if(x>=10)
        y=3*x-11;
    else
        y=2*x-1;
    printf("y=%.2f\n",y);
    return 0;
}
