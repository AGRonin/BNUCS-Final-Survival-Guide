//
//  main.c
//  华氏-摄氏温度转换表
//
//  Created by 杨博文 on 2023/9/15.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    //输入2个整数lower和 upper，输出一张华氏－摄氏温度转换表，华氏温度的取值范围是[lower, upper]，每次增加1°F。
    int fahr, lower, upper;
    double celsius;
    printf("Enter lower:");
    scanf("%d", &lower);
    printf("Enter upper:");
    scanf("%d", &upper);
    printf("fahr  celsius\n");
    // 温度重复转换：华氏温度从lower开始，到upper结束，每次增加1°F
    for (fahr = lower; fahr <= upper; fahr ++)
    {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%d %6.1f\n", fahr, celsius);
    }
    return 0;

}
