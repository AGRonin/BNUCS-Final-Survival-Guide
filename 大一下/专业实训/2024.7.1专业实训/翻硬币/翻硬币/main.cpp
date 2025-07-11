//
//  main.cpp
//  翻硬币
//
//  Created by 杨博文 on 2024/7/1.
//
/*小明正在玩一个"翻硬币"的游戏。
 桌上放着排成一排的若干硬币。我们用 * 表示正面，用 o 表示反面（是小写字母，不是零）。
 比如，可能情形是：**oo*oooo
 如果同时翻转左边的两个硬币，则变为：oooo***oooo
 现在小明的问题是：如果已知了初始状态和要达到的目标状态，每次只能同时翻转相邻的两个硬币,那么对特定的局面，最少要翻动多少次呢？
*/
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    char A[1000],B[1000];
    char in;
    int len=0;
    int cishu=0;
    while(true)
    {
        scanf("%c",&in);
        if(in=='\n')
        {
            break;
        }
        len++;
        A[len-1]=in;
    }
    for(int i=0;i<len;i++)
    {
        scanf("%c",&in);
        B[i]=in;
    }
    int diff=0;
    for(int i=0;i<len;i++)
    {
        if(A[i]==B[i])
        {
            continue;
        }
        diff++;
        if(diff%2==0)
        {
            cishu+=i;
        }
        if(diff%2!=0)
        {
            cishu-=i;
        }
    }
    cout<<cishu;
    return 0;
}
