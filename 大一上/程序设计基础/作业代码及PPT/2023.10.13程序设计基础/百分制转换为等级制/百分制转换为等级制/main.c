//
//  main.c
//  百分制转换为等级制
//
//  Created by 杨博文 on 2023/10/13.
//

#include <stdio.h>
/*从键盘输入一百分制成绩，要求输出其所对应的等级'A', 'B', 'C', 'D'。85分以上（含）为'A'，70~84分之间为'B'，60~69分之间为'C'，60分以下为'D'。
 输入百分制成绩，保证成绩在0~100之间。
 输出百分制成绩所对应的等级，末尾输出换行。*/
int main(int argc, const char * argv[]) {
    float a;
    char b;
    scanf("%f",&a);
    if(a>=85)
        b='A';
    else if(a>=70)
        b='B';
    else if(a>=60)
        b='C';
    else
        b='D';
    printf("%c\n",b);
    return 0;
}
