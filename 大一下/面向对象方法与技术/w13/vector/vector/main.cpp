//
//  main.cpp
//  vector
//
//  Created by 杨博文 on 2024/5/22.
//

#include<iostream>
#include<vector>
using namespace std;
void display_pop(vector<int> &v)     //逆序显示并删除
{   while(!v.empty())
    {   cout<<v.back()<<"\t";
v.pop_back();
}
cout<<endl;
}
int main()
{   vector<int> v1;
    for(int i=0;i<10;i++)         //通过[] 访问vector内元素
        v1.push_back(i);
    v1.insert(v1.begin(),30);

    cout<<"v1:";                     // 顺序显示
    for(int i=0;i<v1.size();i++)
        cout<<v1[i]<<"\t";

    cout<<"\nv1: ";
    display_pop(v1);
    
    vector<int> v2;

    v2.assign(3,10);
    v2.resize(15);
    cout<<"v2:\t ";
    vector<int>::iterator it;  //通过迭代器访问vector内元素

    /* end为最后一个有效元素的下一个空位 */
    for(it=v2.begin();it!=v2.end();it++)
        cout<<(*it)<<"\t";
    return 0;

return 0;
}
