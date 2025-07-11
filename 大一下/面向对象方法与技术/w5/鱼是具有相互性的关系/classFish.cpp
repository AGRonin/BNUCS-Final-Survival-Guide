//
//  classFish.cpp
//  鱼是具有相互性的关系
//
//  Created by 杨博文 on 2024/3/22.
//

#include "classFish.hpp"
int Fish::_allFishNum;
int Fish::_liveFishNum;
void Fish::setFish(std::string name,std::string color)
{
    _name=name;
    _color=color;
    _weight=100;
    _lastEatingDate=0;
    _ifLive=1;
}
void Fish::eating(int date)
{
    _weight=_weight+10;
    _lastEatingDate=date;
    liveOrDead();
}
void Fish::hungry(int date)
{
    if((date-_lastEatingDate)%5==0 && date!=_lastEatingDate && _ifLive==1)
    {
        _weight=_weight-10;
        liveOrDead();
    }
}
int Fish::liveOrDead()
{
    if((_weight==0 || _weight==300) && _ifLive!=0)
    {
        _ifLive=0;
        _liveFishNum=_liveFishNum-1;
    }
    return _ifLive;
}
void Fish::showAll()
{
    if(_ifLive==0)
    {
        return ;
    }
    int a=_weight>=100?3:2;
    std::cout <<
    std::setw(10) << std::setiosflags(std::ios::left) << _name <<
    std::setw(10) << std::setiosflags(std::ios::left) << _color <<
    std::setw(a) << std::setiosflags(std::ios::left) << _weight <<
    std::setw(10-a) << std::setiosflags(std::ios::left) << "g" <<
    std::setiosflags(std::ios::unitbuf) << "第" << _lastEatingDate << "天" << std::endl;
}
std::string Fish::getName()
{
    return _name;
}
void Fish::setNum(int n)
{
    _allFishNum=n;
    _liveFishNum=n;
}
int Fish::getNum()
{
    if(_liveFishNum==0)
    {
        std::cout <<"抱歉，所有的鱼都死了，养鱼失败了，程序结束。" <<std::endl;
    }
    return _liveFishNum;
}
