//
//  main.c
//  平均分
//
//  Created by 杨博文 on 2023/9/15.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    /*从键盘输入三个学生的数学考试成绩，计算它们的平均分，保留两位小数。
     输入
     三个整数，数学成绩。
     输出
     平均分，保留2位小数。*/
    int a,b,c;
    float d;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    d=(a+b+c)/3.0;
    printf("%.2f\n",d);
    return 0;
}
