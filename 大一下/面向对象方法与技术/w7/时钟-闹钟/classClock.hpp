//
//  classClock.hpp
//  时钟-闹钟
//
//  Created by 杨博文 on 2024/4/4.
//

#ifndef classClock_hpp
#define classClock_hpp

#include <iostream>
#include <unistd.h>
class Clock
{
private:
    int _h;
    int _m;
    int _s;
public:
    Clock(int hour=0, int minute=0, int second=0);
    void Standard();
    void Show() const;//显示时间功能
    void Tick();//计时功能，每一次Tick，时间向前走1秒
    void Set(int h, int m, int s);//重新设定时间值
    int GetHour() const;
    int GetMinute() const;
};
#endif /* classClock_hpp */
