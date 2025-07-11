//
//  main.cpp
//  货仓选址
//
//  Created by 杨博文 on 2024/7/2.
//

/*在一条数轴上有N家商店，它们的坐标为Ai。
 现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。
 为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。*/

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int len;
    cin>>len;
    int A[len];
    int less[int((len+1)/2)];//5则3，4则2
    int less_max=0,less_index=0,sum=0;
    for(int i=0;i<len;i++)
    {
        cin>>A[i];
        
        sum+=A[i];
        if(i<int((len+1)/2))
        {
            less[i]=A[i];
            if(less_max<A[i])
            {
                less_max=A[i];
                less_index=i;
            }
            continue;
        }
        if(A[i]<less_max)
        {
            less[less_index]=A[i];
            less_max=0;
            less_index=0;
            for(int j=0;j<int((len+1)/2);j++)
            {
                if(less[j]>less_max)
                {
                    less_index=j;
                    less_max=less[j];
                }
            }
        }
    }
    if(len%2!=0)
    {
        sum+=less_max;
    }
    for(int i=0;i<int((len+1)/2);i++)
    {
        sum-=2*less[i];
    }
    cout<<sum;
    return 0;
}
