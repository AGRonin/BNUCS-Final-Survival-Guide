//
//  classRectangle.cpp
//  形状
//
//  Created by 杨博文 on 2024/4/20.
//

#include "classRectangle.hpp"
Rectangle::Rectangle(double x1,double y1,double x2,double y2):_point1(x1,y1),_point2(x2,y2)
{
}
void Rectangle::Show() const
{
    std::cout << "矩形 ";
    _point1.ShowPoint();
    std::cout << " ";
    _point2.ShowPoint();
    std::cout << std::endl;
}
double Rectangle::Area() const
{
    return abs((_point1.getx()-_point2.getx())*(_point1.gety()-_point2.gety()));
}
double Rectangle::Perimeter() const
{
    return 2*(abs(_point1.getx()-_point2.getx())+abs(_point1.gety()-_point2.gety()));
}
