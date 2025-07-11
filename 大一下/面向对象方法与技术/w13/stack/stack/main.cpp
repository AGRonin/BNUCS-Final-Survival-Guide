//
//  main.cpp
//  stack
//
//  Created by 杨博文 on 2024/5/22.
//

#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.top()<<"\t";
    s.pop();
    s.top()=100;
    s.push(50);
    s.push(60);
    s.pop();
    while(!s.empty())
    {    cout<<s.top()<<"\t";
        s.pop();
    }
    cout<<endl;
    return 0;
}
