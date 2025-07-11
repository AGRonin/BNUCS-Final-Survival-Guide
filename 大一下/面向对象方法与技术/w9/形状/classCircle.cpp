//
//  classCircle.cpp
//  形状
//
//  Created by 杨博文 on 2024/4/20.
//

#include "classCircle.hpp"
Circle::Circle(double x,double y,double r):_pointO(x,y)
{
    _radius=r;
}
void Circle::Show() const
{
    std::cout << "圆 ";
    _pointO.ShowPoint();
    std::cout << " " << _radius << std::endl;
}
double Circle::Area() const
{
    return PI*_radius*_radius;
}
double Circle::Perimeter() const
{
    return 2*PI*_radius;
}
