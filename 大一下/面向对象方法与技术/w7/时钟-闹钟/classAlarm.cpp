//
//  classAlarm.cpp
//  时钟-闹钟
//
//  Created by 杨博文 on 2024/4/4.
//

#include "classAlarm.hpp"
Alarm::Alarm(int h,int m,int s,int Ah,int Am):A_h(Ah),A_m(Am)
{
    Set(h, m, s);
    Standard();
}
void Alarm::Standard()
{
    Clock::Standard();
    A_h+=(A_m-A_m%60)/60;
    A_m=A_m%60;
    A_h=A_h%24;
}
void Alarm::SetAlarmTime(int Ah,int Am)
{
    A_h=Ah;
    A_m=Am;
    Standard();
}
void Alarm::IsAlarm() const
{
    if(A_h==GetHour() && A_m==GetMinute())
    {
        std::cout << '\7';
    }
}
void Alarm::Tick()
{
    Clock::Tick();
    IsAlarm();
}
