//
//  main.c
//  线性表的删除
//
//  Created by 杨博文 on 2023/12/1.
//

#include <stdio.h>
/*输入一个正整数序列，遇负数时停止，建立一个线性链表存储读入的数据，然后从键盘读入一数据x，在该链表中删除比x大的数据后输出。
 样例输入
 1 2 3 4 5 -1
 3
 样例输出
 1 2 3 */
int main(int argc, const char * argv[]) {
    int shuzu[1000],jishu=0,x,kongge=0;
    for(jishu=0;1;jishu++)
    {
        scanf("%d",&shuzu[jishu]);
        if(shuzu[jishu]<0)
        {
            break;
        }
    }
    scanf("%d",&x);
    for(int j=0;j<jishu;j++)
    {
        if(shuzu[j]<=x)
        {
            if(kongge==1)
            {
                printf(" ");
            }
            kongge=1;
            printf("%d",shuzu[j]);
        }
    }
    return 0;
}
