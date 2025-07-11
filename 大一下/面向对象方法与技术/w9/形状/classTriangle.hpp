//
//  classTriangle.hpp
//  形状
//
//  Created by 杨博文 on 2024/4/20.
//

#ifndef classTriangle_hpp
#define classTriangle_hpp

#include "classPoint.hpp"
class Triangle:public Shape
{
private:
    Point _point1;
    Point _point2;
    Point _point3;
public:
    Triangle(double x1=0,double y1=0,double x2=0,double y2=0,double x3=0,double y3=0);
    virtual ~Triangle(){};
    virtual void Show() const;
    virtual double Area() const;
    virtual double Perimeter() const;
};

#endif /* classTriangle_hpp */
