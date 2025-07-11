//
//  classShape.hpp
//  形状
//
//  Created by 杨博文 on 2024/4/20.
//

#ifndef classShape_hpp
#define classShape_hpp

#include <iostream>
#include <cmath> //由于Rectangle需要使用abs函数以及Triangle需要使用sqrt函数，引入cmath
class Shape
{
public:
    Shape(){}
    virtual ~Shape(){}
    void GetInfo() const;
    virtual void Show() const =0;//虚常函数，show为形状和坐标
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
};

#endif /* classShape_hpp */
