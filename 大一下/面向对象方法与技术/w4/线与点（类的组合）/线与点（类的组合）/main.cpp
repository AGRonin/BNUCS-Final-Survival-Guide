//
//  main.cpp
//  线与点（类的组合）
//
//  Created by 杨博文 on 2024/3/13.
//

#include <iostream>
#include <cmath>
using namespace std;
class Point
{
private:
    int _x, _y;
public:
    Point(int x = 0, int y = 0);
    Point(const Point& p);
    int getX() const;
    int getY() const;
};
Point::Point(int x, int y)
{
    _x = x;
    _y = y;
}
Point::Point(const Point& p)
{
    _x = p._x;
    _y = p._y;
    cout << " Calling the copy constructor of Point " << endl;
}
int Point::getX() const
{
    return _x;
}
int Point::getY() const
{
    return _y;
}
class Line
{
private:
    Point _p1, _p2;
    double _len;
public:
    Line(Point p1, Point p2);
    Line(int x1, int y1, int x2, int y2);
    Line(const Line& l);
    double getLen() const;
};
//组合类的构造函数，调用点类的拷贝构造函数
Line::Line(Point p1, Point p2): _p1(p1),_p2(p2)
{
    cout << " Calling constructor of Line " << endl;
    double x = (double)_p1.getX() - (double)_p2.getX();
    double y = (double)_p1.getY() - (double)_p2.getY();
    _len = sqrt(x*x + y*y);
}
//避免使用拷贝构造函数，直接使用Point的第一个构造函数
Line::Line(int x1, int y1, int x2, int y2):_p1(x1,y1),_p2(x2,y2)
{
    cout << " Calling constructor of Line " << endl;
}
//组合类的拷贝构造函数
Line::Line(const Line& l): _p1(l._p1), _p2(l._p2)
{
    cout << " Calling copy constructor of Line " << endl;
    _len = l._len;
}
double Line::getLen() const
{
    return _len;
}

int main()
{
    Point myp1(1, 1), myp2(4, 5);
    Line line(myp1, myp2);
    Line line2(line);
    cout << "The length of line is : " << line.getLen() << endl;
    cout << "The length of line2 is : " << line2.getLen() << endl;
    return 0;
}
