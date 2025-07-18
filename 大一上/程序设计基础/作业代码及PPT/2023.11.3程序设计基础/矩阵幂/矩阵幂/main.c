//
//  main.c
//  矩阵幂
//
//  Created by 杨博文 on 2023/11/3.
//

#include <stdio.h>
/*给定一个N阶矩阵A，输出A的M次幂（M是非负整数）
 输入第一行是一个正整数N、M（1<=N<=30, 0<=M<=5），表示矩阵A的阶数和要求的幂数
 　　接下来N行，每行N个绝对值不超过10的非负整数，描述矩阵A的值
 输出输出共N行，每行N个整数，表示A的M次幂所对应的矩阵。相邻的数之间用一个空格隔开*/
int main(int argc, const char * argv[]) {
    int n,o;
    scanf("%d %d",&n,&o);
    int m=n;
    int A[m*n],B[m*n],C[m*n];
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d",&A[i+j*m]);
            C[i+j*m]=B[i+j*m]=A[i+j*m];
        }
    }
    for(int k=1;k<o;k++)
    {
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                int sum=0;
                for(int l=0;l<n;l++)
                {
                    sum+=A[i+l*m]*B[j*m+l];
                }
                C[i+j*m]=sum;
            }
        }
        for(int i=0;i<n*m;i++)
            A[i]=C[i];
    }
    if(o==0)
    {
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                C[i+j*m]=(i==j)?1:0;
            }
        }
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m-1;i++)
        {
            printf("%d ",C[i+j*m]);
        }
        printf("%d",C[j*m+m-1]);
        if(j!=n-1)
        {
            printf("\n");
        }
    }
    return 0;
}
