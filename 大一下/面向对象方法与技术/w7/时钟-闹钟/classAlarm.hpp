//
//  classAlarm.hpp
//  时钟-闹钟
//
//  Created by 杨博文 on 2024/4/4.
//
/*（2）闹钟类AlarmClock
功能基本要求：
闹钟类继承时钟类，闹钟的功能包括计时和闹铃。
设计AlarmClock(闹钟)类：
a) 增加表示闹铃时间的数据成员，闹铃时间精确到小时 : 分钟；
b) 构造函数构造新闹钟对象，初始化时钟时间和闹铃时间；
c) 成员函数Alarm()的功能是：当闹铃时间到时，增加实际的声音效果“嘀嘀嘀……”；
d) 成员函数SetAlarmTime(…)用来重新设置闹铃的时间值；
e) 重写Tick()函数，保持计时功能，增加判定是否到达闹铃时间的功能，如果到达闹铃时间则响铃（Alarm()）；*/
#ifndef classAlarm_hpp
#define classAlarm_hpp

#include "classClock.hpp"
class Alarm : public Clock
{
private:
    int A_h;
    int A_m;
public:
    Alarm(int h=0,int m=0,int s=0,int Ah=0,int Am=0);
    void Standard();
    void SetAlarmTime(int Ah,int Am);
    void IsAlarm() const;
    void Tick();
};
#endif /* classAlarm_hpp */
