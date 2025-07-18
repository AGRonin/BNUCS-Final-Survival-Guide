//
//  main.c
//  乘法表
//
//  Created by 杨博文 on 2023/11/3.
//

#include <stdio.h>
/*问题：读入n，输出n*n小乘法口诀表。
 输入样例：
 4
 输出样例：
 1*1=1
 2*1=2 2*2=4
 3*1=3 3*2=6 3*3=9
 4*1=4 4*2=8 4*3=12 4*4=16
 数据规模 1<= n <=9*/
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            printf("%d*%d=%d ",i,j,i*j);
        }
        printf("%d*%d=%d",i,i,i*i);
        if(i!=n)
            printf("\n");
    }
    return 0;
}
