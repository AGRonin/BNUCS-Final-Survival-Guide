//
//  main.cpp
//  分巧克力
//
//  Created by 杨博文 on 2024/7/3.
//

/*儿童节那天有K位小朋友到小明家做客。小明拿出了珍藏的巧克力招待小朋友们。
 小明一共有N块巧克力，其中第i块是Hi x Wi的方格组成的长方形。
 为了公平起见，小明需要从这 N 块巧克力中切出K块巧克力分给小朋友们。切出的巧克力需要满足：
 形状是正方形，边长是整数，大小相同
 例如一块6x5的巧克力可以切出6块2x2的巧克力或者2块3x3的巧克力。
 当然小朋友们都希望得到的巧克力尽可能大，你能帮小明计算出最大的边长是多少么？
 第一行包含两个整数N和K。(1 <= N, K <= 100000)
 以下N行每行包含两个整数Hi和Wi。(1 <= Hi, Wi <= 100000)
 输入保证每位小朋友至少能获得一块1x1的巧克力。
 输出切出的正方形巧克力最大可能的边长。*/
#include <iostream>
using namespace std;
int canDivideHowMany(int length,int wide,int a)
{
    return (length/a)*(wide/a);
}

int main(int argc, const char * argv[]) {
    int n,k;
    cin>>n>>k;
    int min=1,max=0,mid;
    int chocLength[n],chocWide[n];
    for(int i=0;i<n;i++)
    {
        cin>>chocLength[i]>>chocWide[i];
        if(chocLength[i]>max)
        {
            max=chocLength[i];
        }
        if(chocWide[i]>max)
        {
            max=chocWide[i];
        }
    }
    while(min<max)
    {
        mid=(min+max+1)/2;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=canDivideHowMany(chocLength[i], chocWide[i], mid);
        }
        if(sum>=k)
        {
            min=mid;
        }
        if(sum<k)
        {
            max=mid-1;
        }
    }
    cout<<max;
    return 0;
}
