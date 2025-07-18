//
//  main.c
//  华氏度与摄氏度
//
//  Created by 杨博文 on 2023/9/15.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    float celsius,fahr;
    printf("请输入华氏度：");
    scanf("%f",&fahr);
    celsius = 5 * (fahr - 32)/9;
    printf("fahr=%.2f,celsius=%.2f\f",fahr,celsius);
    return 0;
}
