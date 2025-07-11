//
//  classWorldClock.cpp
//  世界时钟
//
//  Created by 杨博文 on 2024/4/4.
//

#include "classWorldClock.hpp"
WorldClock::WorldClock(std::string city,int h,int m,int s):_city(city),Clock(h,m,s){}
void WorldClock::Set(std::string city,int h,int m,int s)
{
    _city=city;
    Clock::Set(h,m,s);
}
std::string WorldClock::GetCity() const
{
    return _city;
}
void WorldClock::Show() const
{
    std::cout << _city << " ";
    Clock::Show();
}
WorldClock WorldClock::Con(std::string ConversionCity) const
{
    WorldClock con;
    int i,j;
    for(i=0;i<17;i++)
    {
        if(WorldCityName[i]==ConversionCity)
        {
            break;
        }
    }
    for(j=0;j<17;j++)
    {
        if(WorldCityName[j]==GetCity())
        {
            break;
        }
    }
    con.Set(ConversionCity, GetHour()-WorldCityHour[j]+WorldCityHour[i], GetMinute(), GetSecond());
    return con;
}
WorldClock WorldClock::Sub(const WorldClock& c) const
{
    WorldClock sub,temps;
    Clock temp(GetHour(),GetMinute(),GetSecond());
    temps=c.Con(_city);
    Clock tempc(temps.GetHour(),temps.GetMinute(),temps.GetSecond());
    sub.Set(_city, temp.Sub(tempc).GetHour(), temp.Sub(tempc).GetMinute(), temp.Sub(tempc).GetSecond());
    return sub;
}
