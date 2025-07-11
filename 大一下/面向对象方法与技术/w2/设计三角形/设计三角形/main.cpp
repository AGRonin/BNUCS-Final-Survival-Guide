//
//  main.cpp
//  设计三角形
//
//  Created by 杨博文 on 2024/2/29.
//

/*设计三角形类Triangle
成员数据（private）:
边长1（len1）、边长2（len2）、边长3（len3），数据类型double
成员函数（public）：
设置边长函数SetLen ，给3条边长赋值（函数参数表，返回值类型请自己设计）
判定是否构成三角形函数IsTriangle（函数参数表，返回值类型请自己设计）
判定是否是等边三角形函数Equilateral（函数参数表，返回值类型请自己设计）
判定是否是等腰三角形函数Isosceles（函数参数表，返回值类型请自己设计）
判定是否是直角三角形函数RightTriangle（函数参数表，返回值类型请自己设计）
计算面积函数Area（函数参数表，返回值类型请自己设计）
计算周长函数Perimeter（函数参数表，返回值类型请自己设计）
main函数：
main函数中要使用类Triangle的对象，完成对三角形的各种操作。
具体要求如下：
输入3边长，判定是否构成三角形。
如果不能正确构造三角形，继续输入3边长，直到可以正确构成三角形。
如果正确构成三角形，输出是否是等边三角形、是否是等腰三角形、是否是直角三角形，并输出面积、周长。*/

#include <iostream>
#include <cmath>
#include <iomanip>

class Point
{
private:
    double _x;
    double _y;
public:
    Point(double x,double y):_x(x),_y(y){}
    double getx(){return _x;}
    double gety(){return _y;}
};

class Triangle
{
private:
    double len1,len2,len3;
public:
    void SetLen(double len_1,double len_2,double len_3);
    void SetLen(Point p1,Point p2,Point p3);
    int IsTriangle();
    int Equilateral();
    int Isosceles();
    int RightTriangle();
    double Area();
    double Perimeter();
};

inline void Triangle::SetLen(double len_1,double len_2,double len_3)
{
    len1=len_1;
    len2=len_2;
    len3=len_3;
}

void Triangle::SetLen(Point p1, Point p2, Point p3)
{
    len1=sqrt(pow(p1.getx()-p2.getx(),2)+pow(p1.gety()-p2.gety(),2));
    len2=sqrt(pow(p2.getx()-p3.getx(),2)+pow(p2.gety()-p3.gety(),2));
    len3=sqrt(pow(p3.getx()-p1.getx(),2)+pow(p3.gety()-p1.gety(),2));
}

inline int Triangle::IsTriangle()
{
    if(len1+len2>len3 && len1+len3>len2 && len2+len3>len1)
        return 1;
    return 0;
}

inline int Triangle::Equilateral()
{
    if(len1==len2 && len2==len3)
        return 1;
    return 0;
}

inline int Triangle::Isosceles()
{
    if(len1==len2 || len2==len3 || len3==len1)
        return 1;
    return 0;
}

inline int Triangle::RightTriangle()
{
    if(len1*len1==len2*len2+len3*len3 || len2*len2==len3*len3+len1*len1 || len3*len3==len1*len1+len2*len2)
        return 1;
    return 0;
}

double Triangle::Area()
{
    double area,halfPerimeter;
    halfPerimeter=Perimeter()/2;
    area=sqrt((halfPerimeter-len1)*(halfPerimeter-len2)*(halfPerimeter-len3)*halfPerimeter);
    return area;
}

inline double Triangle::Perimeter()
{
    return len1+len2+len3;
}

int main(int argc, const char * argv[]) {
    Triangle triangle_1;
    double len_1,len_2,len_3;
    while(true)
    {
        std::cout << "input 3 lengths: ";
        std::cin >> len_1 >> len_2 >> len_3 ;
        triangle_1.SetLen(len_1, len_2, len_3);
        if(triangle_1.IsTriangle()==1)
            break;
        else
            std::cout << "can't consturct Triangle!\n";
    }
    if(triangle_1.Equilateral()==1)
        std::cout << "It is an equilateral triangle.\n";
    else
        std::cout << "It isn't an equilateral triangle.\n";
    if(triangle_1.Isosceles()==1)
        std::cout << "It is an isosceles triangle.\n";
    else
        std::cout << "It isn't an isosceles triangle.\n";
    if(triangle_1.RightTriangle()==1)
        std::cout << "It is a right triangle.\n";
    else
        std::cout << "It isn't a right triangle.\n";
    std::cout << "area = " << triangle_1.Area() << std::endl;
    std::cout << "perimeter = " << triangle_1.Perimeter() << std::endl;
    
    return 0;
}
