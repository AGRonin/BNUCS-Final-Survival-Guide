//
//  main.c
//  求和
//
//  Created by 杨博文 on 2023/10/14.
//

#include <stdio.h>
/*输入一个整数n，求s=11+22+33+..+nn  (n<=9)
 输入一个整数 输出一个整数*/
int main(int argc, const char * argv[]) {
    int a,b=0,c=1;
    scanf("%d",&a);
    while(c<=a)
    {
        b=b+c*11;
        c++;
    }
    printf("%d",b);
    return 0;
}
