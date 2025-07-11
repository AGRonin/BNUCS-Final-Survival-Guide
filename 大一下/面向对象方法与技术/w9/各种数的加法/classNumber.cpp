//
//  classNumber.cpp
//  各种数的加法
//
//  Created by 杨博文 on 2024/4/21.
//

#include "classNumber.hpp"
Number::Number(double x)
{
    _data=x;
}
void Number::Show()
{
    std::cout << _data;
}
double Number::get()
{
    return _data;
}
void Number::Add(Sum *num)
{
    Number* x=dynamic_cast<Number*>(num);
    Number add(_data+x->get());
    add.Show();
}
