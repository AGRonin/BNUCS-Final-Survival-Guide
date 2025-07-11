//
//  classFraction.hpp
//  有理数加减乘除
//
//  Created by 杨博文 on 2024/3/29.
//

#ifndef classFraction_hpp
#define classFraction_hpp

#include <iostream>
class Fraction
{
private:
    int _num;
    int _den;
public:
    Fraction(int num=0,int den=1);
    int Gen(int x,int y);
    void Standard();//化简函数使得分子分母互质
    void Set(int p, int q);//如果是负数，符号写在分子上
    void Show() const;
    friend Fraction Add(const Fraction& f1,const Fraction& f2);
    friend Fraction Minus(const Fraction& f1,const Fraction& f2);
    friend Fraction Multiply(const Fraction& f1,const Fraction& f2);
    friend Fraction Divide(const Fraction& f1,const Fraction& f2);
    int ifZero() const;
};
#endif /* classFraction_hpp */
