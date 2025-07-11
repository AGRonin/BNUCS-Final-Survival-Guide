//
//  classComplex.hpp
//  各种数的加法
//
//  Created by 杨博文 on 2024/4/21.
//

#ifndef classComplex_hpp
#define classComplex_hpp

#include "classSum.hpp"
class Complex:public Sum
{
private:
    double _real;
    double _imag;
public:
    Complex(double a=0,double b=0);
    virtual ~Complex(){};
    virtual void Show();
    double geta();
    double getb();
    virtual void Add(Sum *num);
};

#endif /* classComplex_hpp */
