//
//  classTriangle.cpp
//  形状
//
//  Created by 杨博文 on 2024/4/20.
//

#include "classTriangle.hpp"
Triangle::Triangle(double x1,double y1,double x2,double y2,double x3,double y3):_point1(x1,y1),_point2(x2,y2),_point3(x3,y3)
{
}
void Triangle::Show() const
{
    std::cout << "三角形 ";
    _point1.ShowPoint();
    std::cout << " ";
    _point2.ShowPoint();
    std::cout << " ";
    _point3.ShowPoint();
    std::cout << std::endl;
}
double Triangle::Area() const
{
    double a=sqrt(pow((_point1.getx()-_point2.getx()),2)+pow((_point1.gety()-_point2.gety()),2));
    double b=sqrt(pow((_point2.getx()-_point3.getx()),2)+pow((_point2.gety()-_point3.gety()),2));
    double c=sqrt(pow((_point3.getx()-_point1.getx()),2)+pow((_point3.gety()-_point1.gety()),2));
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
double Triangle::Perimeter() const
{
    double a=sqrt(pow((_point1.getx()-_point2.getx()),2)+pow((_point1.gety()-_point2.gety()),2));
    double b=sqrt(pow((_point2.getx()-_point3.getx()),2)+pow((_point2.gety()-_point3.gety()),2));
    double c=sqrt(pow((_point3.getx()-_point1.getx()),2)+pow((_point3.gety()-_point1.gety()),2));
    return a+b+c;
}
