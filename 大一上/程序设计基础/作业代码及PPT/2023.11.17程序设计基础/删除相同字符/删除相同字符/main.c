//
//  main.c
//  删除相同字符
//
//  Created by 杨博文 on 2023/11/21.
//

#include <stdio.h>
#include <string.h>
/*编制函数del_char
 函数原型为 void del_char(char *str,char delete),函数的功能是删除a指向的字符串中值为ch的字符，例如从字符串"AscADef"中删除'A'后，字符串为"scDef"。
 输入 需要删除的字符ch 需要处理的字符串
 输出 处理后的字符串*/
void del_char(char *str,char delete)
{
    char jihe[80],*stry,*strx;
    strx=jihe;
    stry=str;
    for(;*stry!='\0';*stry++)
    {
        if(*stry!=delete)
        {
            *strx=*stry;
            *strx++;
        }
    }
    *strx='\0';
    strcpy(str,jihe);
}
int main(int argc, const char * argv[]) {
    char delete,str[80];
    scanf("%c",&delete);
    scanf("%s",str);
    char *strz=str;
    del_char(strz,delete);
    puts(strz);
    return 0;
}
