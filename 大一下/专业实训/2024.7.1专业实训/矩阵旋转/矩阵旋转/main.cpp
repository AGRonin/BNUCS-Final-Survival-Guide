//
//  main.cpp
//  矩阵旋转
//
//  Created by 杨博文 on 2024/7/1.
//

#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int j=m-1;j>=0;j--)
    {
        for(int i=0;i<n;i++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}
