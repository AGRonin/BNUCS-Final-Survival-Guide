//
//  classClock.hpp
//  世界时钟
//
//  Created by 杨博文 on 2024/4/4.
//

#ifndef classClock_hpp
#define classClock_hpp

#include <iostream>
class Clock
{
private:
    int _h;
    int _m;
    int _s;
public:
    Clock(int h=0,int m=0,int s=0);//时分秒的默认值都是0
    void Standard();//小时的取值范围0~23 ，分钟和秒的取值范围0~59
    void Set(int h,int m,int s);
    int GetHour() const;
    int GetMinute() const;
    int GetSecond() const;
    void Show() const;
    Clock Sub(const Clock& c) const;
};

#endif /* classClock_hpp */
