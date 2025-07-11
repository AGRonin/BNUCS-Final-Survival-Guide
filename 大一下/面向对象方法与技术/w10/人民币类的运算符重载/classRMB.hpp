//
//  classRMB.hpp
//  人民币类的运算符重载
//
//  Created by 杨博文 on 2024/4/25.
//

#ifndef classRMB_hpp
#define classRMB_hpp

#include <iostream>
class RMB
{
private:
    char _sign;
    unsigned _y;
    unsigned _j;
    unsigned _f;
public:
    RMB(char sign='+',unsigned y=0,unsigned j=0,unsigned f=0);
    void standard();
    friend std::ostream& operator<<(std::ostream& o,const RMB& rmb1);
    friend std::istream& operator>>(std::istream& i,RMB& rmb1);
    RMB operator+(const RMB& rmb2);
    RMB operator-(const RMB& rmb2);
    RMB& operator++();//前置++
    RMB operator++(int q);//后置++
    friend RMB& operator--(RMB& rmb1);//前置--
    friend RMB operator--(RMB& rmb1,int q);//后置--
};

#endif /* classRMB_hpp */
