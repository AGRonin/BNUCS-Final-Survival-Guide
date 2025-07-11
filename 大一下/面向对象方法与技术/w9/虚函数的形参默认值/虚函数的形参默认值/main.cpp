//
//  main.cpp
//  虚函数的形参默认值
//
//  Created by 杨博文 on 2024/4/17.
//

#include <iostream>
using namespace std;

class Base
{public:
    virtual int oper(int x = 0, int y = -10);
    virtual ~Base() {}
    };
    int Base::oper(int x, int y)
    {  cout << "In Base class : " <<x << " " << y << endl;
    return x + y;
    }
    class Derived :public Base
    {public:
    int oper(int x = 100, int y = 10);
    ~Derived() {}
    };
    int Derived::oper(int x, int y)
    {  cout <<"In Derived class : " <<x << " " << y << endl;
    return x - y;
}
int main()
{  Derived d;
   Base& b = d;
   cout << b.oper() << endl;
   cout << d.oper() << endl;
   return 0;
}
