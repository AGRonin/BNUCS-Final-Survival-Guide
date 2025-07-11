//
//  main.cpp
//  牛牛之怒
//
//  Created by 杨博文 on 2024/7/3.
//

/*农夫约翰建造了一座有 n 间牛舍的小屋，牛舍排在一条直线上，第 i 间牛舍在 xi 的位置，但是约翰的 m 头牛对小屋很不满意，因此经常互相攻击。约翰为了防止牛之间互相伤害，因此决定把每头牛都放在离其它牛尽可能远的牛舍。也就是要最大化最近的两头牛之间的距离。
 牛们并不喜欢这种布局，而且几头牛放在一个隔间里，它们就要发生争斗。为了不让牛互相伤害。John 决定自己给牛分配隔间，使任意两头牛之间的最小距离尽可能的大，那么，这个最大的最小距离是多少呢？*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,i;
    cin>>n>>m;
    int house[n];
    for(i=0;i<n;i++)
    {
        cin>>house[i];
    }
    sort(house,house+n);
    int min=1,max=house[n-1];
    while(min<max)
    {
        int mid=(min+max+1)/2;
        int count=1;
        int index=0;
        for(int x=1;x<n;x++)
        {
            if(house[x]-house[index]>=mid)
            {
                count++;
                index=x;
                if(count>=m)
                {
                    break;
                }
            }
        }
        if(count<m)
        {
            max=mid-1;
        }
        else
        {
            min=mid;
        }
    }
    cout<<min;
    return 0;
}
