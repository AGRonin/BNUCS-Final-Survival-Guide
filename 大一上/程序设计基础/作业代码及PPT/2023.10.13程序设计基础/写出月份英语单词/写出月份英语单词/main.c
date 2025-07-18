//
//  main.c
//  写出月份英语单词
//
//  Created by 杨博文 on 2023/10/13.
//

#include <stdio.h>
/*输入月份数字(1-12)，输出相应英语单词。
   一月：January
   二月：February
   三月：March
   四月：April
   五月：May
   六月：June
   七月：July
   八月：August
   九月：September
   十月：October
   十一月：November
   十二月：December
 请用switch语句实现
 输入一行：一个整数，表示月份。
 输出一行：相应月份字符串。*/
int main(int argc, const char * argv[]) 
{
    int a;
    scanf("%d",&a);
    switch(a)
    {
        case 1:
            puts("January");
            break;
        case 2:
            puts("February");
            break;
        case 3:
            puts("March");
            break;
        case 4:
            puts("April");
            break;
        case 5:
            puts("May");
            break;
        case 6:
            puts("June");
            break;
        case 7:
            puts("July");
            break;
        case 8:
            puts("August");
            break;
        case 9:
            puts("September");
            break;
        case 10:
            puts("October");
            break;
        case 11:
            puts("November");
            break;
        case 12:
            puts("December");
            break;
    }
    return 0;
}
