//
//  classPoint.cpp
//  形状
//
//  Created by 杨博文 on 2024/4/20.
//

#include "classPoint.hpp"
Point::Point(double x,double y)
{
    _x=x;
    _y=y;
}
void Point::Show() const
{
    std::cout << "点 ";
    ShowPoint();
    std::cout << std::endl;
}
double Point::Area() const
{
    return 0;
}
double Point::Perimeter() const
{
    return 0;
}
void Point::ShowPoint() const
{
    std::cout << _x << " " << _y;
}
double Point::getx() const
{
    return _x;
}
double Point::gety() const
{
    return _y;
}
