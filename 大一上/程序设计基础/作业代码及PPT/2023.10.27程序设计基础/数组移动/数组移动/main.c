//
//  main.c
//  数组移动
//
//  Created by 杨博文 on 2023/10/27.
//

#include <stdio.h>
/*读入N个整数存放在数组中，将每个元素依次后移一个位置，最后一个元素移动到第一个元素的位置。
 输入 第一行，一个整数n（n不超过100） 第二行：n个整数，相邻数值之间用一个空格分隔。
 输出移动以后的结果，相邻数值之间用一个空格分隔，行末不要出现多余空格。*/
int main(int argc, const char * argv[]) {
    int geshu;
    scanf("%d",&geshu);
    int shuzu[geshu];
    for(int i=1;i<geshu+1;i++)
    {
        int x;
        scanf("%d",&x);
        shuzu[i%geshu]=x;
    }
    for(int i=0;i<geshu-1;i++)
    {
        printf("%d ",shuzu[i]);
    }
    printf("%d",shuzu[geshu-1]);
    return 0;
}
