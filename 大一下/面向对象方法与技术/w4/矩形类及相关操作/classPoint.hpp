//
//  classPoint.hpp
//  矩形类及相关操作
//
//  Created by 杨博文 on 2024/3/13.
//

#ifndef classPoint_hpp
#define classPoint_hpp

#include <stdio.h>
#include <iostream>
class Point
{
private:
    double _x;
    double _y;
public:
    Point(double x=0.0, double y=0.0);
    void Setx(double x);
    void Sety(double y);
    void Setxy(double x, double y);
    double Getx() const;
    double Gety() const;
};

#endif /* classPoint_hpp */
