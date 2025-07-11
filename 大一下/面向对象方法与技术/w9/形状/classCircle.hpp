//
//  classCircle.hpp
//  形状
//
//  Created by 杨博文 on 2024/4/20.
//

#ifndef classCircle_hpp
#define classCircle_hpp

#include "classPoint.hpp"
#define PI 3.14
class Circle:public Shape
{
private:
    Point _pointO;
    double _radius;
public:
    Circle(double x=0,double y=0,double r=0);
    virtual ~Circle(){};
    virtual void Show() const;
    virtual double Area() const;
    virtual double Perimeter() const;
};

#endif /* classCircle_hpp */
