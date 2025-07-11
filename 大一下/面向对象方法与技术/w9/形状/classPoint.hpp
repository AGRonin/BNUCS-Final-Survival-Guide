//
//  classPoint.hpp
//  形状
//
//  Created by 杨博文 on 2024/4/20.
//

#ifndef classPoint_hpp
#define classPoint_hpp

#include "classShape.hpp"
class Point:public Shape
{
private:
    double _x;
    double _y;
public:
    Point(double x=0,double y=0);
    virtual ~Point(){};
    virtual void Show() const;
    virtual double Area() const;
    virtual double Perimeter() const;
    void ShowPoint() const;
    double getx() const;
    double gety() const;
};

#endif /* classPoint_hpp */
