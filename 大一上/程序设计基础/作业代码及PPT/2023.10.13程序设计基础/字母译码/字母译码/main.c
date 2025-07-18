//
//  main.c
//  字母译码
//
//  Created by 杨博文 on 2023/10/14.
//

#include <stdio.h>
/*编写一个译码程序，把一个英语句子（包含大小写英文字母）译成数字代码。译码规则是以数字1代替字母a，数字2代替字母b，……，26代替字母z；大写字母也按相同规则处理，即用1~26代替A~Z，如遇空格则打印一个星号‘*’，英文句子以‘.‘结束。
 输入一行英文句子（只含大小写字母、空格），以‘.’结束。
 输出一行，译码后的数字代码。
 样例输入
 LuXiZhongXue.
 样例输出
 12212492681514724215 */
int main(int argc, const char * argv[]) 
{
    char ch;
    int a=0;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='.')
            break;
        else if(ch==' ')
        {
            ch='*';
            printf("%c",ch);
        }
        else if(ch<='Z' && ch>='A')
            a=ch-64;
        else if(ch<='z' && ch>='a')
            a=ch-96;
        if(a!=0)
            printf("%d",a);
        a=0;
    }
    return 0;
}
