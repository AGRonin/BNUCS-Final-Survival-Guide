//
//  main.cpp
//  merge
//
//  Created by 杨博文 on 2024/5/29.
//

#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
    int a1[] = { 10,20,30,40,50,60,70 };
    int a2[] = { 40,50,60 };
    int a[10];
    merge(a1, a1 + 7, a2, a2 + 3, a);    //将a1、a2合并，结果放在a数组中
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    list<int> L1, L2;
    list<int>::iterator pos;
    for (int i = 0; i < 7; i++)
    {
        L1.push_back(a1[i]);
    }
    for (int j = 0; j < 3; j++)
    {
        L2.push_back(a2[j]);
    }
    L1.merge(L2);            //用list的merge成员合并L1、L2
    for (pos = L1.begin(); pos != L1.end(); pos++)
    {
        cout << *pos << " ";
    }
    cout << endl;
    return 0;
}
