//
//  classFish.hpp
//  鱼是具有相互性的关系
//
//  Created by 杨博文 on 2024/3/22.
//

#ifndef classFish_hpp
#define classFish_hpp

#include <iostream>
#include <iomanip>

class Fish
{
private:
    static int _allFishNum;
    static int _liveFishNum;
    std::string _name;
    std::string _color;
    int _weight;
    int _lastEatingDate;
    int _ifLive;
public:
    void setFish(std::string name,std::string color);
    void eating(int date);
    void hungry(int date);
    int liveOrDead();
    void showAll();
    std::string getName();
    static void setNum(int n);
    static int getNum();
};

#endif /* classFish_hpp */
