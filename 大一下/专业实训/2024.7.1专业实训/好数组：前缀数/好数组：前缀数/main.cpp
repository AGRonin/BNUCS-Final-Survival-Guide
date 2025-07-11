//
//  main.cpp
//  好数组：前缀数
//
//  Created by 杨博文 on 2024/7/1.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int m,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        long long A[m],max=0,sum=0;
        int count=0;
        for(int j=0;j<m;j++)
        {
            cin>>A[j];
            sum+=A[j];
            if(max<A[j])
            {
                max=A[j];
            }
            if(max*2==sum)
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
