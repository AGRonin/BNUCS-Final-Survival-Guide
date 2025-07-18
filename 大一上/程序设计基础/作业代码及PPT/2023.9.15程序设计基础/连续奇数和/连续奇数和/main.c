//
//  main.c
//  连续奇数和
//
//  Created by 杨博文 on 2023/9/15.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*问题：读入奇数a1，an， 求a1+a2+……an的和，其中a1,a2……an是a1至an的连续奇数。
    输入样例：1 9
    输出样例：25 */
    int a1,an,sum,i;
    sum=0;
    scanf("%d%d",&a1,&an);
    for(i=a1;i<=an;i=i+2)
    {
        sum=sum+i;
    }
    printf("%d",sum);
    return 0;
}
