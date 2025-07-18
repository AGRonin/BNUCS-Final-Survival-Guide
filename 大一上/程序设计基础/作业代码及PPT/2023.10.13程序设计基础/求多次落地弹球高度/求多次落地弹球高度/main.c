//
//  main.c
//  求多次落地弹球高度
//
//  Created by 杨博文 on 2023/10/14.
//

#include <stdio.h>
/*一个球从100m的高度自由落下，每次落地后反弹回原高度的一半，再落下，再反弹。求它在第N次落地时，共经过了多少米，第N次反弹多高。
 输入一个正整数N，表示球落地的次数。
 输出
 length=球第N次落地时所经过了距离
 high=球第N次落地反弹的高度
 小数点后保留4位小数。
 注意：末尾输出换行。*/
int main(int argc, const char * argv[]) {
    int n,i=1;
    float high=100.0,length=100.0;
    scanf("%d",&n);
    while(i<=n)
    {
        length=length+high;
        high=high/2.0;
        i++;
    }
    length=length-high*2;
    printf("length=%.4f\nhigh=%.4f\n",length,high);
    return 0;
}
