//
//  main.c
//  矩阵加法
//
//  Created by 杨博文 on 2023/11/3.
//

#include <stdio.h>
/*给定两个N×M的矩阵，计算其和。其中：
 　　N和M大于等于1且小于等于100，矩阵元素的绝对值不超过1000。
 输入数据的第一行包含两个整数N、M，表示需要相加的两个矩阵的行数和列数。接下来2*N行每行包含M个数，其中前N行表示第一个矩阵，后N行表示第二个矩阵。
 输出你的程序需要输出一个N*M的矩阵，表示两个矩阵相加的结果。
 注意，输出中每行的最后不应有多余的空格，否则你的程序有可能被系统认为是Presentation Error*/
int main(int argc, const char * argv[]) {
    int m,n; //m列n行
    scanf("%d %d",&n,&m);
    double A[n*m],B[n*m];
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%lf",&A[i+j*m]);
        }
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%lf",&B[i+j*m]);
            B[i+j*m]+=A[i+j*m];
        }
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m-1;i++)
        {
            printf("%.0lf ",B[i+j*m]);
        }
        printf("%.0lf",B[j*m+m-1]);
        if(j!=n-1)
        {
            printf("\n");
        }
    }
    return 0;
}
