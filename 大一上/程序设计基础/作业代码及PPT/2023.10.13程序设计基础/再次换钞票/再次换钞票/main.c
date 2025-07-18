//
//  main.c
//  再次换钞票
//
//  Created by 杨博文 on 2023/10/13.
//

#include <stdio.h>
/*某人想将手中的一张面值100元的人民币换成10元、5元、2元和1元面值的票子。要求换正好40张，且每种票子至少一张。问：有几种换法？应适当考虑减少重复次数。
 无输入。
 输出一个数，表示共有多少种换法。*/
int main(int argc, const char * argv[]) 
{
    int a=1,b,c,d,number=0;
    while(a<=9)
    {
        b=1;
        while(b<=18)
        {
            c=1;
            while(c<=37)
            {
                d=40-a-b-c;
                if(d>=1)
                {
                    if(a*10+b*5+c*2+d==100)
                        number++;
                }
                c++;
            }
            b++;
        }
        a++;
    }
    printf("%d",number);
    return 0;
}
