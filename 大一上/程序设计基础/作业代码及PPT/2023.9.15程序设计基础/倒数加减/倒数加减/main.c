//
//  main.c
//  倒数加减
//
//  Created by 杨博文 on 2023/9/16.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*读入n，计算S=1-1/2+1/3-1/4+1/5-1/6+…… 1/n的值。顶格输出，保留小数点后10位。
    输入样例：6
    输出样例：0.6166666667*/
    int n,i;
    double sum;
    sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            sum=sum-1.0/i;
        }
        else
        {
            sum=sum+1.0/i;
        }
    }
    printf("%.10lf",sum);
    return 0;
}
