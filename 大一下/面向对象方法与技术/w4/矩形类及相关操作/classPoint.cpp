//
//  classPoint.cpp
//  矩形类及相关操作
//
//  Created by 杨博文 on 2024/3/13.
//

#include "classPoint.hpp"
#include <iostream>

Point::Point(double x, double y):_x(x),_y(y){}
void Point::Setx(double x)
{
    _x=x;
}
void Point::Sety(double y)
{
    _y=y;
}
void Point::Setxy(double x, double y)
{
    Setx(x);
    Sety(y);
}
double Point::Getx() const
{
    return _x;
}
double Point::Gety() const
{
    return _y;
}
