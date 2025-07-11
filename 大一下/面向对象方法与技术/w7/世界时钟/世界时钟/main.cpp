//
//  main.cpp
//  世界时钟
//
//  Created by 杨博文 on 2024/4/4.
//

/*1.1    基类 Clock
 成员数据（私有）：int _h, _m, _s  表示小时、分钟、秒
 成员函数（公有）：构造函数：时分秒的默认值都是0
     标准化函数：void Standard();小时的取值范围0~23 ，分钟和秒的取值范围0~59
     Set函数
     Get函数（常函数）
     显示函数（常函数）
     求2个时间值的差函数：Clock Sub(const Clock& c) const;
 1.2    派生类 WorldClock （世界时间） 公有继承Clock类
 增加成员数据（私有）：string _city
 增加成员函数（公有）：构造函数，默认值北京时间Beijing 0:0:0
     Set函数
     Get函数（常函数）
     显示函数（常函数）
     求2个时间值的差函数：WorldClock Sub(const World Clock& c) const;
 1.3    主函数实现2个功能：时间转换 和 时间差
 选项： C(c)  Conversion 表示时间转换
  S(s)  Subtraction 表示求时间差
  E(e)  End 表示程序结束
 使用枚举表示城市
 使用全局数组表示城市与时区的关系
*/

#include "classWorldClock.hpp"
std::string WorldCityName[17]={"Hawaii","Alaska","LosAngeles","Chicago","NewYork","Atlantic","Brazil","MidAtlantic","London","Berlin","Cario","Moscow","NewDelhi","Bangkok","Beijing","Tokyo","Sydney"};
std::string WorldCityShortName[17]={"ha","ak","la","ch","ny","dxy","bz","dxyz","ld","bl","ca","mo","nd","bk","bj","tk","sy"};
int WorldCityHour[17]={-10,-9,-8,-6,-5,-4,-3,-2,0,1,2,3,5,7,8,9,10};//使用数组将城市名、简写、GMT联系起来
int main(int argc, const char * argv[]) {
    char selection='0';
    while (selection!='E' && selection!='e')
    {
        std::cout << "Conversion / Subtraction / End :";
        std::cin >> selection;
        if(selection=='C'|| selection=='c')
        {
            std::string city1,city2;
            int h,m,s;
            std::cout << "Input City:";
            std::cin >> city1;
            std::cout << "Input hour minute second:";
            std::cin >> h >> m >> s;
            std::cout << "Input Conversion City:";
            std::cin >> city2;
            for(int i=0;i<17;i++)
            {
                if(city1==WorldCityShortName[i])
                {
                    city1=WorldCityName[i];
                }
                if(city2==WorldCityShortName[i])
                {
                    city2=WorldCityName[i];
                }
            }
            WorldClock c1(city1,h,m,s),c2;
            c2=c1.Con(city2);
            std::cout << "Time is:\n";
            c1.Show();
            std::cout << std::endl;
            c2.Show();
            std::cout << std::endl;
        }
        if(selection=='S'|| selection=='s')
        {
            std::string city1,city2;
            int h1,m1,s1,h2,m2,s2;
            std::cout << "Input City:";
            std::cin >> city1;
            std::cout << "Input hour minute second:";
            std::cin >> h1 >> m1 >> s1;
            std::cout << "Input City:";
            std::cin >> city2;
            std::cout << "Input hour minute second:";
            std::cin >> h2 >> m2 >> s2;
            for(int i=0;i<17;i++)
            {
                if(city1==WorldCityShortName[i])
                {
                    city1=WorldCityName[i];
                }
                if(city2==WorldCityShortName[i])
                {
                    city2=WorldCityName[i];
                }
            }
            WorldClock c1(city1,h1,m1,s1),c2(city2,h2,m2,s2),c3;
            c3=c1.Sub(c2);
            c1.Show();
            std::cout << "-";
            c2.Show();
            std::cout << "=";
            c3.Show();
            std::cout << std::endl;
        }
    }
    std::cout << "Byebye~";
    return 0;
}
