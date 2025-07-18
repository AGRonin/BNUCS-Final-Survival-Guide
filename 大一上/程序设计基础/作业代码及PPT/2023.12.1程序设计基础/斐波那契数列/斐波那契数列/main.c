//
//  main.c
//  斐波那契数列
//
//  Created by 杨博文 on 2023/12/1.
//

#include <stdio.h>
/*斐波那契数列0,1,1,2,3,5,8,13,21,34,55……前三项分别是0,1,1。从第四项起，每一项都是紧挨着的前两项的和。写出计算斐波那契数列任意一个数据项的程序。
 输入 所求项数，保证＜70
 输出 数据项的值*/
unsigned long long fibonacci(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n<=2)
    {
        return 1;
    }
    else if(n%2==0)
    {
        return (fibonacci(n/2-1)+fibonacci(n/2+1))*fibonacci(n/2);
    }
    else
    {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    printf("%llu",fibonacci(n-1));
    return 0;
}
