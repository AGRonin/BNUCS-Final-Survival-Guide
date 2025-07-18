//
//  main.c
//  杨辉三角
//
//  Created by 杨博文 on 2023/11/4.
//

#include <stdio.h>
/*用函数编程计算并输出如图1-5所示的杨辉三角形。使用二维数组存储并输出
 输入1个数n（n<20）。表示杨辉三角有几行。
 输出输出n行杨辉三角。两数之间用空格隔开。*/
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int hang=n,lie=n,sanjiao[hang][lie];
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<=j;i++)
        {
            if(i==0 || i==j)
                sanjiao[j][i]=1;
            else
                sanjiao[j][i]=sanjiao[j-1][i-1]+sanjiao[j-1][i];
        }
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<=j;i++)
        {
            if(i==j && j!=n-1)
                printf("%d\n",sanjiao[j][i]);
            else if(i==j)
                printf("%d",sanjiao[j][i]);
            else
                printf("%d ",sanjiao[j][i]);
        }
    }
    return 0;
}
