//
//  main.c
//  输出月份英文
//
//  Created by 杨博文 on 2023/12/1.
//

#include <stdio.h>
/*从键盘任意输入整型数表示的月份值，用指针数组编程输出该月份的英文表示，输入的月份值不在1~12之间，则输出“Illegal month"。
 输入 输入的第一行为一个正整数n（1<=n<=15），表示测试样例的个数。接下来n行，每行输入一个整型数。
 输出 对应的n行输出*/
void yuefendayin(int a)
{
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
        default:
            puts("Illegal month");
            break;
    }
}
void shuchu(int *p,int n)
{
    for(int i=0;i<n;i++,p++)
    {
        yuefendayin(*p);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int shuzu[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&shuzu[i]);
    }
    shuchu(shuzu,n);
    return 0;
}
