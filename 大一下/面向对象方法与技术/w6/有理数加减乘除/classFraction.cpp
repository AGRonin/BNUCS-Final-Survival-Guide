//
//  classFraction.cpp
//  有理数加减乘除
//
//  Created by 杨博文 on 2024/3/29.
//

#include "classFraction.hpp"
Fraction::Fraction(int num,int den):_num(num),_den(den)
{
}
int Fraction::Gen(int x,int y)
{
    if(x==y)
        return x;
    if(x==1 || y==1)
        return 1;
    if(x==0 || y==0)
        return x+y;
    if(x<0)
        return Gen(-x,y);
    if(x<y)
        return Gen(x,y%x);
    return Gen(y,x%y);
}
void Fraction::Standard()
{
    int gen=Gen(_num,_den);
    _num=_num/gen;
    _den=_den/gen;
}
void Fraction::Set(int p, int q)
{
    if(q<0)
    {
        q=-q;
        p=-p;
    }
    _num=p;
    _den=q;
    Standard();
}
void Fraction::Show() const
{
    if(_den==1)
    {
        std::cout << _num;
        return;
    }
    std::cout << _num << "/" << _den;
}
Fraction Add(const Fraction& f1,const Fraction& f2)
{
    Fraction add;
    add.Set(f1._num*f2._den+f2._num*f1._den,f1._den*f2._den);
    return add;
}
Fraction Minus(const Fraction& f1,const Fraction& f2)
{
    Fraction minus;
    minus.Set(f1._num*f2._den-f2._num*f1._den,f1._den*f2._den);
    return minus;
}
Fraction Multiply(const Fraction& f1,const Fraction& f2)
{
    Fraction multiply;
    multiply.Set(f1._num*f2._num,f1._den*f2._den);
    return multiply;
}
Fraction Divide(const Fraction& f1,const Fraction& f2)
{
    Fraction divide;
    divide.Set(f1._num*f2._den,f1._den*f2._num);
    return divide;
}
int Fraction::ifZero() const
{
    if(_num==0)
        return 0;
    return 1;
}
