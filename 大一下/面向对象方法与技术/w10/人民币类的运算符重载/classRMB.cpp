//
//  classRMB.cpp
//  人民币类的运算符重载
//
//  Created by 杨博文 on 2024/4/25.
//

#include "classRMB.hpp"
RMB::RMB(char sign,unsigned y,unsigned j,unsigned f):_sign(sign),_y(y),_j(j),_f(f)
{
    standard();
}
//利用总分数进行初始化
void RMB::standard()
{
    int x=100*_y+10*_j+_f;
    _f=x%10;
    _j=(x/10)%10;
    _y=x/100;
}
std::ostream& operator<<(std::ostream& o,const RMB& rmb1)
{
    o << rmb1._sign << rmb1._y << "元" << rmb1._j << "角" <<rmb1._f << "分";
    return o;
}
std::istream& operator>>(std::istream& i,RMB& rmb1)
{
    i >> rmb1._sign >> rmb1._y >> rmb1._j >> rmb1._f;
    rmb1.standard();
    return i;
}
//在进行加减法运算时，考虑rmb1和rmb2的正负性，通过为总分数添加正负的方式计算
RMB RMB::operator+(const RMB& rmb2)
{
    int x=100*_y+10*_j+_f;
    if(_sign=='-')
    {
        x=-x;
    }
    int y=100*rmb2._y+10*rmb2._j+rmb2._f;
    if(rmb2._sign=='-')
    {
        y=-y;
    }
    char sign='+';
    if(x+y<0)
    {
        sign='-';
        x=-x;
        y=-y;//这里的目的是让x+y变成其绝对值
    }
    return RMB(sign,0,0,x+y);//充分利用standard函数
}
RMB RMB::operator-(const RMB& rmb2)
{
    int x=100*_y+10*_j+_f;
    if(_sign=='-')
    {
        x=-x;
    }
    int y=100*rmb2._y+10*rmb2._j+rmb2._f;
    if(rmb2._sign=='-')
    {
        y=-y;
    }
    char sign='+';
    if(x-y<0)
    {
        sign='-';
        x=-x;
        y=-y;
    }
    return RMB(sign,0,0,x-y);
}
//前置++
RMB& RMB::operator++()
{
    int x=100*_y+10*_j+_f;
    if(_sign=='-')
    {
        x=-x;
    }
    x=x+1;
    //这里仍然需要判断x的正负，避免++后从-1变成0没有改变符号
    if(x>=0)
    {
        _sign='+';
    }
    else
    {
        _sign='-';
        x=-x;
    }
    _y=0;
    _j=0;
    _f=x;
    standard();
    return *this;
}
//后置++
RMB RMB::operator++(int q)
{
    RMB old(*this);
    int x=100*_y+10*_j+_f;
    if(_sign=='-')
    {
        x=-x;
    }
    x=x+1;
    if(x>=0)
    {
        _sign='+';
    }
    else
    {
        _sign='-';
        x=-x;
    }
    _y=0;
    _j=0;
    _f=x;
    standard();
    return old;
}
//前置--
RMB& operator--(RMB& rmb1)
{
    int x=100*rmb1._y+10*rmb1._j+rmb1._f;
    if(rmb1._sign=='-')
    {
        x=-x;
    }
    x=x-1;
    if(x>=0)
    {
        rmb1._sign='+';
    }
    else
    {
        rmb1._sign='-';
        x=-x;
    }
    rmb1._y=0;
    rmb1._j=0;
    rmb1._f=x;
    rmb1.standard();
    return rmb1;
}
//后置--
RMB operator--(RMB& rmb1,int q)
{
    RMB old(rmb1);
    int x=100*rmb1._y+10*rmb1._j+rmb1._f;
    if(rmb1._sign=='-')
    {
        x=-x;
    }
    x=x-1;
    if(x>=0)
    {
        rmb1._sign='+';
    }
    else
    {
        rmb1._sign='-';
        x=-x;
    }
    rmb1._y=0;
    rmb1._j=0;
    rmb1._f=x;
    rmb1.standard();
    return old;
}
