//
//  main.c
//  水果批发
//
//  Created by 杨博文 on 2023/9/15.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*水果商店批发桔子，100千克或100千克以下，每千克2元。超过100千克，超过部分每千克1元。输入批发重量求批发价格。
     输入一行，一个整数，代表水果重量
     输出一行，一个整数，代表水果价钱*/
    int weight,price;
    scanf("%d",&weight);
    if(weight<=100)
    {
        price=weight*2;
        printf("%d",price);
    }
    else
    {
        price=weight+100;
        printf("%d",price);
    }
    return 0;
}
