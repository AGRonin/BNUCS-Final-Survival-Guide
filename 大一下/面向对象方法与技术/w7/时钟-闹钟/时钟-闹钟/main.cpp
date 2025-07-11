//
//  main.cpp
//  时钟-闹钟
//
//  Created by 杨博文 on 2024/4/4.

/*在时钟类Clock的基础上派生闹钟类AlarmClock
 （1）时钟类Clock
 Clock类设计如下，请实现成员函数。
 class  Clock
 { private:
        int _h,_m,_s;        //24小时制的时间数据
  public:
        Clock(int hour, int minute, int second);
        void Show() const;                //显示时间功能
     void Tick();                    //计时功能，每一次Tick，时间向前走1秒
     void Set(int h, int m, int s);        //重新设定时间值
  };
 （2）闹钟类AlarmClock
 功能基本要求：
 闹钟类继承时钟类，闹钟的功能包括计时和闹铃。
 设计AlarmClock(闹钟)类：
 a) 增加表示闹铃时间的数据成员，闹铃时间精确到小时 : 分钟；
 b) 构造函数构造新闹钟对象，初始化时钟时间和闹铃时间；
 c) 成员函数Alarm()的功能是：当闹铃时间到时，增加实际的声音效果“嘀嘀嘀……”；
 d) 成员函数SetAlarmTime(…)用来重新设置闹铃的时间值；
 e) 重写Tick()函数，保持计时功能，增加判定是否到达闹铃时间的功能，如果到达闹铃时间则响铃（Alarm()）；
 （3）主程序
 使用AlarmClock类
 a)创建AlarmClock类的对象，给它初始时间值（比如：23：59：30），闹铃时间值（比如： 00：01 表示0点1分）和它要走的时长（比如：2分15秒），发出启动命令后，让它一秒一秒地走起来，并且显示它的每个时间值（包含时：分：秒）
 b)当到达闹铃时间时，增加实际的声音效果“嘀嘀嘀……”。
 c)等到预订的时长完成时，输出计时结束信息
 d)以上的计时过程可以重复多次
*/
//在此文件中，使用<unistd.h>库（在classClock.hpp中被include）中的sleep函数以代替<windows.h>库中的Sleep函数，此处sleep函数的单位是秒，而非毫秒

#include "classAlarm.hpp"
int main(int argc, const char * argv[]) 
{
    char IfContinue='Y';
    while(IfContinue=='Y'||IfContinue=='y')
    {
        int a,b,c,d,e,f,g;
        std::cout << "请输入初始时间（时 分 秒）：";
        std::cin >> a >> b >> c;
        std::cout << "请输入闹铃时间（时 分）  ：";
        std::cin >> d >> e;
        std::cout << "请输入计时时长（分 秒）  ：";
        std::cin >> f >> g;
        Alarm alarm(a,b,c,d,e);
        for(int i=0;i<=f*60+g;i++)
        {
            alarm.Show();
            std::cout << '\r';
            alarm.Tick();
            sleep(1);//此处sleep函数的单位是秒，而非毫秒；可替换为Sleep(1000)
        }
        std::cout << "计时结束，还要继续吗（Y/N）？";
        std::cin >> IfContinue;
    }
    std::cout <<"Press any key to continue\n";
    return 0;
}
