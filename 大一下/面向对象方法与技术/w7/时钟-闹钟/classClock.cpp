//
//  classClock.cpp
//  时钟-闹钟
//
//  Created by 杨博文 on 2024/4/4.
//

#include "classClock.hpp"
Clock::Clock(int hour, int minute, int second):_h(hour),_m(minute),_s(second)
{
    Standard();
}
void Clock::Standard()
{
    if(_s<0)
    {
        _s+=60;
        _m--;
    }
    if(_s>59)
    {
        _s-=60;
        _m++;
    }
    if(_m<0)
    {
        _m+=60;
        _h--;
    }
    if(_m>59)
    {
        _m-=60;
        _h++;
    }
    if(_h<0)
    {
        _h+=24;
    }
    if(_h>23)
    {
        _h-=24;
    }
}
void Clock::Show() const
{
    std::string sh="",sm=":",ss=":";
    if(_h<10)
    {
        sh="0";
    }
    if(_m<10)
    {
        sm=":0";
    }
    if(_s<10)
    {
        ss=":0";
    }
    sh+=std::to_string(_h);
    sm+=std::to_string(_m);
    ss+=std::to_string(_s);
    std::cout << sh << sm << ss;
}
void Clock::Tick()
{
    Set(_h,_m,_s+1);
    Standard();
}
void Clock::Set(int h, int m, int s)
{
    _h=h;
    _m=m;
    _s=s;
    Standard();
}
int Clock::GetHour() const
{
    return _h;
}
int Clock::GetMinute() const
{
    return _m;
}
