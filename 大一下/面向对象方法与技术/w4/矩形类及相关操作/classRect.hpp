//
//  classRect.hpp
//  矩形类及相关操作
//
//  Created by 杨博文 on 2024/3/13.
//

#ifndef classRect_hpp
#define classRect_hpp

#include "classPoint.hpp"
auto abs(auto x);
class Rect
{
private:
    Point _p1;
    Point _p2;
    double _area;
    double _perimeter;
public:
    Rect(double x1=0, double y1=0, double x2=0, double y2=0);
    Rect(Point p1,Point p2);
    void SetRect(double x1, double y1, double x2, double y2);
    int ifRect();
    void ShowAll();
    void ShowPoint();
    Rect Move(double Movex, double Movey);
};

#endif /* classRect_hpp */
