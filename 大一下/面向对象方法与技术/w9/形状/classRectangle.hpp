//
//  classRectangle.hpp
//  形状
//
//  Created by 杨博文 on 2024/4/20.
//

#ifndef classRectangle_hpp
#define classRectangle_hpp

#include "classPoint.hpp"
class Rectangle:public Shape
{
private:
    Point _point1;
    Point _point2;
public:
    Rectangle(double x1=0,double y1=0,double x2=0,double y2=0);
    virtual ~Rectangle(){};
    virtual void Show() const;
    virtual double Area() const;
    virtual double Perimeter() const;
};

#endif /* classRectangle_hpp */
