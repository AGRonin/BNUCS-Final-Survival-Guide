//
//  main.cpp
//  垦田计划
//
//  Created by 杨博文 on 2024/7/3.
//
/*顿顿总共选中了n块区域准备开垦田地，由于各块区域大小不一，开垦所需时间也不尽相同。
 据估算，其中第i块（1≤i≤n）区域的开垦耗时为ti天。
 这n块区域可以同时开垦，所以总耗时tTotal取决于耗时最长的区域，即：
 为了加快开垦进度，顿顿准备在部分区域投入额外资源来缩短开垦时间。
 具体来说：
 在第i块区域每投入ci单位资源，便可将其开垦耗时缩短 1 天；
 耗时缩短天数以整数记，即第i块区域投入资源数量必须是ci的整数倍；
 在第i块区域最多可投入ci*(ti-k)单位资源，将其开垦耗时缩短为k天；
 这里的k表示开垦一块区域的最少天数，满足o<k<=min{ti}
 换言之，如果无限制地投入资源，所有区域都可以用k天完成开垦。
 现在顿顿手中共有m单位资源可供使用，试计算开垦n块区域最少需要多少天？
 输入共n+1行。
 输入的第一行包含空格分隔的三个正整数n,m,k，分别表示待开垦的区域总数、顿顿手上的资源数量和每块区域的最少开垦天数。
 接下来n行，每行包含空格分隔的两个正整数ti和ci，分别表示第i块区域开垦耗时和将耗时缩短1天所需资源数量。
 输出一个整数，表示开垦n块区域的最少耗时。*/
#include <iostream>
using namespace std;
bool canShortToXDays(int* C,int* T,int n,long long m,int t)
{
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        if(T[i]>t)
        {
            sum+=(T[i]-t)*C[i];
        }
        if(sum>m)
        {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int n,k;
    long long m;
    cin>>n>>m>>k;
    int C[n],T[n];
    int min=k,max=0,mid;
    for(int i=0;i<n;i++)
    {
        cin>>T[i]>>C[i];
        if(T[i]>max)
        {
            max=T[i];
        }
    }
    while(min<max)
    {
        mid=(min+max)/2;
        if(!canShortToXDays(C, T, n, m,mid))
        {
            min=mid+1;
        }
        else
        {
            max=mid;
        }
    }
    cout<<min;
    return 0;
}
