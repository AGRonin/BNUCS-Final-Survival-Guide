//
//  main.cpp
//  list
//
//  Created by 杨博文 on 2024/5/22.
//

#include <iostream>
#include <list>
using namespace std;
int main()
{   
    list<char> v1;
    list<char>::iterator iter1;
    list<char>::iterator iter2;
    v1.push_back('m');
    v1.push_back('n');
    v1.push_back('o');
    v1.push_back('p');
    cout << "v1.front() = " << v1.front() << endl;
    cout << "v1.back() = " << v1.back() << endl;
    iter1 = v1.begin();
    cout << *iter1 << endl;
    iter2 = v1.end();           //注意v1.end()指向最后一个元素的下一个位置，
    cout << *(--iter2) << endl; //所以访问最后一个元素的正确操作为 *(--iter2)
    
    int a1[]={10,20,30,40,50,60,70};
    int a2[]={40,50,60};
    list<int> L1,L2;
    for(int i=0;i<7;i++)
        L1.push_back(a1[i]);
    for(int j=0;j<3;j++)
        L2.push_back(a2[j]);
    list<int>::iterator pos;   //通过迭代器访问List中元素
    for(pos=L1.begin();pos!=L1.end();pos++)
        cout<<*pos<<"\t";
    cout<<endl;
    for(pos=L2.begin();pos!=L2.end();pos++)
        cout<<*pos<<"\t";
    cout<<endl;
    L1.merge(L2);
    for(pos=L1.begin();pos!=L1.end();pos++)
        cout<<*pos<<"\t";
    cout<<endl;
    return 0;
}
