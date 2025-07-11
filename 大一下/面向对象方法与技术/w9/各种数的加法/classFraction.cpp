//
//  classFraction.cpp
//  各种数的加法
//
//  Created by 杨博文 on 2024/4/21.
//

#include "classFraction.hpp"
Fraction::Fraction(int num,int den)
{
    if(den<0)
    {
        den=-den;
        num=-num;
    }
    _num=num;
    _den=den;
    Standard();
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
int Fraction::geta()
{
    return _num;
}
int Fraction::getb()
{
    return _den;
}
void Fraction::Show()
{
    if(_den==1)
    {
        std::cout << _num;
        return;
    }
    std::cout << _num << "/" << _den;
}
void Fraction::Add(Sum *num)
{
    Fraction* x=dynamic_cast<Fraction*>(num);
    Fraction add(_num*x->getb()+_den*x->geta(),_den*x->getb());
    add.Show();
}
