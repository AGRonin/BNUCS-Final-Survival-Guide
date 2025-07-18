//
//  main.c
//  交换数字
//
//  Created by 杨博文 on 2023/12/15.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a,b;
    scanf("%d%d",&a,&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("%d %d",a,b);
    return 0;
}
