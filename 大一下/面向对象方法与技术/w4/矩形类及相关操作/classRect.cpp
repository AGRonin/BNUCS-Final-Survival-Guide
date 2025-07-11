//
//  classRect.cpp
//  矩形类及相关操作
//
//  Created by 杨博文 on 2024/3/13.
//

#include "classPoint.hpp"
#include "classRect.hpp"

auto abs(auto x)
{
    if(x<0)
    {
        return -x;
    }
    return x;
}
Rect::Rect(double x1, double y1, double x2, double y2)
{
    _p1.Setxy(x1, y1);
    _p2.Setxy(x2, y2);
}
Rect::Rect(Point p1,Point p2)
{
    _p1=p1;
    _p2=p2;
}
void Rect::SetRect(double x1, double y1, double x2, double y2)
{
    _p1.Setxy(x1, y1);
    _p2.Setxy(x2, y2);
}
int Rect::ifRect()
{
    if(_p1.Getx()==_p2.Getx() || _p1.Gety()==_p2.Gety())
    {
        return 0;
    }
    return 1;
}
void Rect::ShowAll()
{
    if(ifRect()==0)
    {
        std::cout << _p1.Getx() << " " << _p1.Gety() << " " << _p2.Getx() << " " << _p2.Gety() << " Can’t construct rectangle." << std::endl;
    }
    else
    {
        _area=abs(_p2.Getx()-_p1.Getx())*abs(_p2.Gety()-_p1.Gety());
        _perimeter=2*(abs(_p2.Getx()-_p1.Getx())+abs(_p2.Gety()-_p1.Gety()));
        std::cout << "Rect(" << _p1.Getx() << " " << _p1.Gety() << " " << _p2.Getx() << " " << _p2.Gety() << ") area=" << _area << " perimeter=" << _perimeter << std::endl;
    }
}
void Rect::ShowPoint()
{
    std::cout << "Rect(" << _p1.Getx() << " " << _p1.Gety() << " " << _p2.Getx() << " " << _p2.Gety() << ")\n";
}
Rect Rect::Move(double Movex, double Movey)
{
    Rect Rect1(_p1.Getx()+Movex,_p1.Gety()+Movey,_p2.Getx()+Movex,_p2.Gety()+Movey);
    return Rect1;
}
