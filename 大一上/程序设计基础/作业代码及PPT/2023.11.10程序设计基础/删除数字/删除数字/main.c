//
//  main.c
//  删除数字
//
//  Created by 杨博文 on 2023/11/17.
//

#include <stdio.h>
/*请把字符串中的数字删除，并输出。
 输入：my56fr14ind
 输出：myfrind */
int main(int argc, const char * argv[]) 
{
    char yuan[10000];
    gets(yuan);
    for(int i=0;yuan[i]!=0;i++)
        if(yuan[i]<'0' || yuan[i]>'9')
            putchar(yuan[i]);
    return 0;
}
