//
//  main.c
//  回文字符串
//
//  Created by 杨博文 on 2023/11/21.
//

#include <stdio.h>
#include <string.h>
/*给出一个长度不超过1000的字符串，判断它是不是回文（顺读，逆读均相同）的。
 输入 输入包括一行字符串，其长度不超过1000。
 输出 可能有多组测试数据，对于每组数据，如果是回文字符串则输出"Yes!”，否则输出"No!"。*/
int huiwenpanduan(char *p)
{
    int n;
    n=strlen(p);
    char *pj,t;
    for(pj=p+n-1; p<pj; p++, pj--)
    {
        if(*pj!=*p)
        {
            return 0;
        }
    }
    return 1;
}
int main(int argc, const char * argv[])
{
    char huiwen[5][1000];
    int n;
    for(int i=0;i<5;i++)
    {
        char *p=huiwen[i];
        gets(p);
        if(huiwen[i][0]=='\0')
        {
            n=i;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        char *p=huiwen[i];
        if(huiwenpanduan(p)==1)
            printf("Yes!");
        else
            printf("No!");
        if(i!=n-1)
            printf("\n");
    }
    return 0;
}
