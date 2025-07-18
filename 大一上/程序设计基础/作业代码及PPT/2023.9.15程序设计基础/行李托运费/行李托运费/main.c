//
//  main.c
//  行李托运费
//
//  Created by 杨博文 on 2023/9/15.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*乘坐飞机时，当乘客行李小于等于20公斤时，按每公斤1.68元收费，大于20公斤时，按每公斤1.98元收费，编程计算收费(保留2位小数)。
     输入一个数，表示行李重量（单位：公斤）
     输出行李托运费，保留2位小数。*/
    float weight,price;
    scanf("%f",&weight);
    if(weight<=20)
    {
        price=weight*1.68;
        printf("%.2f",price);
    }
    else
    {
        price=weight*1.98;
        printf("%.2f",price);
    }
    return 0;
}
