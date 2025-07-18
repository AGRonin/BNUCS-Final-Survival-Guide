//
//  main.c
//  单词缩写
//
//  Created by 杨博文 on 2023/11/17.
//

#include <stdio.h>
/*定义：一个词组中每个单词的首字母的大写组合称为该词组的缩写。
 比如，常用的EOF就是end of file的缩写。
 输入 输入的第一行是一个整数T，表示一共有T个词组。（T<100）
 接下来有T行，每行有一个词组，每个词组由一个或多个单词组成；每组的单词个数不超过10个，每个单词由一个或多个大写或小写字母组成；
 单词长度不超过20，由一个或多个空格分隔这些单词。
 输出 请为个词组输出规定的缩写，每组输出占一行。*/
int main(int argc, const char * argv[]) {
    int m;
    scanf("%d\n",&m);
    char biao[m][2000];
    for(int i=0;i<m;i++)
    {
        int j=1;
        biao[i][0]=32;
        while(1)
        {
            scanf("%c",&biao[i][j]);
            if(biao[i][j]=='\n')
            {
                break;
            }
            if(biao[i][j]>='a' && biao[i][j]<='z')
            {
                biao[i][j]=biao[i][j]-'a'+'A';
            }
            j++;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<2000;j++)
        {
            if(biao[i][j]>='A' && biao[i][j]<='Z' && biao[i][j-1]==32)
            {
                printf("%c",biao[i][j]);
            }
            if(biao[i][j]=='\n')
            {
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
