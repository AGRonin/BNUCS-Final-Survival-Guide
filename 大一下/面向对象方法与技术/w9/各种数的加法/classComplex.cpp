//
//  classComplex.cpp
//  各种数的加法
//
//  Created by 杨博文 on 2024/4/21.
//

#include "classComplex.hpp"
Complex::Complex(double a,double b)
{
    _real=a;
    _imag=b;
}
void Complex::Show()
{
    std::cout << _real << "+" << _imag << "i";
}
double Complex::geta()
{
    return _real;
}
double Complex::getb()
{
    return _imag;
}
void Complex::Add(Sum *num)
{
    Complex* x=dynamic_cast<Complex*>(num);
    Complex add(_real+x->geta(),_imag+x->getb());
    add.Show();
}
