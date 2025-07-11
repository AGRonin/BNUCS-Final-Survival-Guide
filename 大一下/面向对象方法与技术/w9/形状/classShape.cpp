//
//  classShape.cpp
//  形状
//
//  Created by 杨博文 on 2024/4/20.
//

#include "classShape.hpp"
void Shape::GetInfo() const
{
    std::cout<<"这是一个";
    Show();
    std::cout<<"它的面积是"<<Area();
    std::cout<<std::endl<<"它的周长是"<<Perimeter()<<std::endl;
}
