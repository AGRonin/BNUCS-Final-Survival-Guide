//
//  classFraction.hpp
//  各种数的加法
//
//  Created by 杨博文 on 2024/4/21.
//

#ifndef classFraction_hpp
#define classFraction_hpp

#include "classSum.hpp"
class Fraction:public Sum
{
private:
    int _num;
    int _den;
public:
    Fraction(int num=0,int den=1);//如果是负数，符号写在分子上
    int Gen(int x,int y);
    void Standard();//化简函数使得分子分母互质
    virtual ~Fraction(){};
    int geta();
    int getb();
    virtual void Show();
    virtual void Add(Sum *num);
};

#endif /* classFraction_hpp */
