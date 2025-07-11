//
//  main.cpp
//  特化test
//
//  Created by 杨博文 on 2024/5/29.
//

#include <iostream>
using namespace std;

template <typename T>  //(a) 模板函数f(T) : 基础模板
void f(T)
{
    cout << "template f(T)" << endl;
}

template <typename T>  //(c) 模板函数f(T)的重载
void f(T*)
{
    cout << "template f(T *)" << endl;
}

template<>             //(b)模板函数f(T)特化，即(a)的特化
void f<int>(int*)//经测试，在这里如果没有指定<>，按照顺序如果在第二个就是a的特化，第三个就是c的特化
//如果有<>，按照指定的进行匹配，如果是<int>，匹配为c的特化，如果是<int*>，匹配为a的特化
{
    cout << "specialization template f(T)" << endl;
}

void f(int x)
{
    cout << "function f(int)" << endl;
}     // (d): 函数

int main()
{
    int x = 10;
    float y=10.0f;
    f(x);
    f(y);
    f(&x);
    return 0;
}
