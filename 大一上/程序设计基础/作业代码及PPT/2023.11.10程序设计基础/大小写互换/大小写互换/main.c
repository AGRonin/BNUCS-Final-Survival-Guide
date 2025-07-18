//
//  main.c
//  大小写互换
//
//  Created by 杨博文 on 2023/11/11.
//

#include <stdio.h>
/*现在给出了一个只包含大小写字母的字符串，不含空格和换行，要求把其中的大写换成小写，小写换成大写，然后输出互换后的字符串。
 输入第一行只有一个整数m（m<=10),表示测试数据组数。接下来的m行，每行有一个字符串（长度不超过100）。
 输出输出互换后的字符串，每组输出占一行。*/
int main(int argc, const char * argv[]) {
    int m;
    scanf("%d\n",&m);
    char biao[m][1000];
    for(int i=0;i<m;i++)
    {
        int j=0;
        while(1)
        {
            scanf("%c",&biao[i][j]);
            if(biao[i][j]=='\n')
            {
                break;
            }
            else if(biao[i][j]>='a' && biao[i][j]<='z')
            {
                biao[i][j]=biao[i][j]-'a'+'A';
            }
            else
            {
                biao[i][j]=biao[i][j]-'A'+'a';
            }
            j++;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<100;j++)
        {
            printf("%c",biao[i][j]);
            if(biao[i][j]=='\n')
                break;
        }
    }
    return 0;
}
