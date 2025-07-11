//
//  classWorldClock.hpp
//  世界时钟
//
//  Created by 杨博文 on 2024/4/4.
//

#ifndef classWorldClock_hpp
#define classWorldClock_hpp

#include "classClock.hpp"
extern std::string WorldCityName[17];
extern std::string WorldCityShortName[17];
extern int WorldCityHour[17];
class WorldClock:public Clock
{
private:
    std::string _city;
public:
    WorldClock(std::string city="Beijing",int h=0,int m=0,int s=0);//默认值北京时间Beijing 0:0:0
    void Set(std::string city,int h,int m,int s);
    std::string GetCity() const;
    void Show() const;
    WorldClock Con(std::string ConversionCity) const;
    WorldClock Sub(const WorldClock& c) const;
};

#endif /* classWorldClock_hpp */
