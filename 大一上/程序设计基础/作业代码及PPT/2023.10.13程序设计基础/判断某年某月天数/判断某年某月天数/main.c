//
//  main.c
//  判断某年某月天数
//
//  Created by 杨博文 on 2023/10/13.
//

#include <stdio.h>
/*输入年，月，然后告诉该月有多少天。
 请用switch语句实现。
 输入 只有一行，包括2个整数。中间用一个空格隔开。
 输出 输出只有一行（这意味着末尾有一个回车符号），包括1个整数。*/

int runnianpanduanhanshu(int a)
{
    if(a%400==0)
        return 1;
    else
    {
        if(a%100==0)
            return 0;
        else
        {
            if(a%4==0)
                return 1;
            else
                return 0;
        }
    }
}
int main(int argc, const char * argv[])
{
    int a,b,c;
    scanf("%d%d",&a,&b);
    switch(b)
    {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            c=31;
            break;
        case 2:
            if(runnianpanduanhanshu(a)==1)
                c=29;
            else
                c=28;
            break;
        default:
            c=30;
            break;
    }
    printf("%d\n",c);
    return 0;
}
