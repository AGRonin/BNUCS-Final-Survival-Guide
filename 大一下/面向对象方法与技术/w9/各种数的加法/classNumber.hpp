//
//  classNumber.hpp
//  各种数的加法
//
//  Created by 杨博文 on 2024/4/21.
//

#ifndef classNumber_hpp
#define classNumber_hpp

#include "classSum.hpp"
class Number:public Sum
{
private:
    double _data;
public:
    Number(double x=0);
    virtual ~Number(){};
    virtual void Show();
    double get();
    virtual void Add(Sum *num);
};

#endif /* classNumber_hpp */
