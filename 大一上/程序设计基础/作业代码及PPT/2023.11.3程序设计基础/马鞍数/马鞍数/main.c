//
//  main.c
//  马鞍数
//
//  Created by 杨博文 on 2023/11/3.
//
#include <stdio.h>
/*马鞍数，是指数阵n*m中在行上最小而在列上最大的数。如：数阵n*m，其中 n=5 m=5
 1   6   7   8   9
 4   5   6   7   8
 3   4   5   2   1
 2   3   4   9   0
 5   6   7   6   8
 则第5行第1列的数字“5”即为该数阵的一个马鞍数。
（注意：行上最小数在一行中可能有多个哦，都需判断是否为马鞍数）

 输入 第一行两个用空格隔开的自然数n与m，表示n行m列，n,m<=100；
 接下来n行每行有m个用空格隔开的整数(最大不超过 32767)。

 输出 输出若干行：如果存在马鞍数，则输出所有马鞍数，每行一个，为行和列以及马鞍数。
 如果不存在马鞍数，则输出'no find'。*/
int main(int argc, const char * argv[]) {
    int n,m,x=0;
    scanf("%d %d",&n,&m);
    int zhen[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&zhen[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int a=0;
            for(int k=0;k<n;k++)
            {
                if(zhen[i][j]<zhen[k][j])
                {
                    a=1;
                    break;
                }
            }
            if(a==0)
            {
                for(int l=0;l<m;l++)
                {
                    if(zhen[i][j]>zhen[i][l])
                    {
                        a=1;
                        break;
                    }
                }
            }
            if(a==0)
            {
                x++;
                if(x!=1)
                    printf("\n");
                printf("%d %d %d",i+1,j+1,zhen[i][j]);
            }
        }
    }
    if(x==0)
        printf("no find");
    return 0;
}
