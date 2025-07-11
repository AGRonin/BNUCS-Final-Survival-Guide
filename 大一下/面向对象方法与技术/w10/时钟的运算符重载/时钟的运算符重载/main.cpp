//
//  main.cpp
//  时钟的运算符重载
//
//  Created by 杨博文 on 2024/4/24.
//

//时钟类：   成员函数+ -       友元函数<< >>
#include <iostream>
using namespace std;
class Clock
{
private:
    int _h, _m, _s;
public:
    void Format();
    Clock(int h = 0, int m = 0, int s = 0);
    Clock operator + (const Clock& c) const;
    Clock operator - (const Clock& c) const;
    Clock& operator++();
    Clock operator++(int);
    friend istream& operator>>(istream& i, Clock& c);
    friend ostream& operator<<(ostream& o, const Clock& c);
};
Clock::Clock(int h, int m, int s)
{
    _h = h;
    _m = m;
    _s = s;
    Format();
}
void Clock::Format()
{
    if (_h < 0 || _m < 0 || _s < 0)
    {
        _s = _h * 3600 + _m * 60 + _s;
        _h = 0;
        _m = 0;
        while (_s < 0)
        {
            _s = 24 * 3600 + _s;
        }
    }
    if (_s >= 60)
    {
        _m += _s / 60;
        _s %= 60;
    }
    if (_m >= 60)
    {
        _h += _m / 60;
        _m %= 60;
    }
    if (_h >= 24)
    {
        _h %= 24;
    }
}
//成员函数：重载加法运算符+
Clock Clock::operator + (const Clock& c) const
{
    Clock temp;
    temp._h = _h + c._h;
    temp._m = _m + c._m;
    temp._s = _s + c._s;
    temp.Format();
    return temp;
    //return Clock(_h+c._h,_m+c._m,_s+c._s);
}
//成员函数：重载减法运算符-
Clock Clock::operator - (const Clock& c) const
{
    int nc1, nc2, nc3;
    nc1 = _h * 3600 + _m * 60 + _s;
    nc2 = c._h * 3600 + c._m * 60 + c._s;
    nc3 = nc1 - nc2;
    while (nc3<0)
    {
        nc3 = 24 * 3600 + nc3;
    }
    Clock temp(0, 0, nc3);
    return temp;
}
//成员函数：重载前置++运算符
Clock& Clock::operator++()
{
    _s++;
    Format();
    return *this;
}
//成员函数：重载后置++运算符
Clock Clock::operator++(int i)
{
    Clock old(*this);
    _s++;
    Format();
    return old;
}
//重载提取运算符>> (输入运算符)
istream& operator>>(istream& i, Clock& c)
{
    char ch;
    i >> c._h >> ch >> c._m >> ch >> c._s;
    c.Format();
    return i;
}
//重载插入运算符<<  (输出运算符)
ostream& operator<<(ostream& o, const Clock& c)
{
    o << c._h << ":" << c._m << ":" << c._s;
    return o;
}
int main()
{
    Clock c1(1, 2, 3), c2(4, 5, 6), c3;
    cout << "overloaded \"operator+ \" and \"operator<< \":\n";
    c3 = c1 + c2;
    cout << c1 << " + " << c2 << " = " << c3 << endl;
    cout << "overloaded \"operator- \" and \"operator<< \":\n";
    c3 = c1 - c2;
    cout << c1 << " - " << c2 << " = " << c3 << endl;
    cout << "overloaded operator>> :\n";
    cout << "Please input c1 c2 c3 ( h:m:s ):\n";
    cin >> c1 >> c2 >> c3;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl;
    
    Clock c4(1, 2, 3), c5;
    cout << "overloaded \"operator ++c1 \" \n";
    cout << "after c5 = ++c4; \n";
    c5 = ++c4;
    cout << "c5=" << c5 << endl;
    cout << "c4=" << c4 << endl;
    cout << "overloaded \"operator c4++ \" \n";
    cout << "after c5 = c4++; \n";
    c5 = c4++;
    cout << "c5=" << c5 << endl;
    cout << "c4=" << c4 << endl;
    cout << "********************************\n";
    cout << "after c5 = ++(++c4); \n";
    c5 = ++(++c4);
    cout << "c5=" << c5 << endl;
    cout << "c4=" << c4 << endl;
    cout << "overloaded \"operator c4++ \" \n";
    cout << "after c5 = (c4++)++; \n";
    c5 = (c4++)++;
    cout << "c5=" << c5 << endl;
    cout << "c4=" << c4 << endl;
    return 0;
}
