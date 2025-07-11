//
//  main.cpp
//  一个小小的银行
//
//  Created by 杨博文 on 2024/3/22.
//

/*设计活期存款类Deposit . 参考图1，每个账户有帐号（自动编号）、户名、密码、金额、月利率（静态成员）、开户时间等信息。银行每月1号要根据账户余额发给客户利息，利息被累计到客户存款余额中。银行可以更改利率。
 本月余额计算方法：    本月余额 = 上月余额 + 上月余额*月利率
 主程序中：建立以下5个账户：
 账号    户名     密码       金额   月利率  开户时间
 1        张三    123456  10000  0.5%     2020-5-1
 2        李四    112233  20000  0.5%     2020-7-1
 3        王五    111111  15000  0.5%     2021-10-1
 4        赵六    222222  58000  0.5%     2021-2-1
 5        周七    888888  50000  0.5%     2022-1-1
 说明：这里的金额指的是开户时的金额
 程序运行：
 2022-7-1，输出所有账户的信息；
 2022-8-1，输出所有账户的信息；本月调整利率为0.4%;
 2022-9-1，输出所有账户的信息；
 2022-10-1，输出所有账户的信息；
 2022-11-1，输出所有账户的信息；
 2022-12-1，输出所有账户的信息；*/

#include "classDeposit.hpp"

int main(int argc, const char * argv[]) 
{
    int year=2020,month=5;
    std::string syear,smonth,s2="-",s1="1",sAll;
    Deposit de[5]={
        Deposit("张三", 123456, 10000, 2020, 5),
        Deposit("李四", 112233, 20000, 2020, 7),
        Deposit("王五", 111111, 15000, 2021, 10),
        Deposit("赵六", 222222, 58000, 2021, 2),
        Deposit("周七", 888888, 50000, 2022, 1)};
    for(year=2020;year<2023;year++)
    {
        for(month=(year-2020)?1:5;month<13;month++)
        {
            syear=std::to_string(year);
            smonth=std::to_string(month);
            sAll=syear+s2+smonth+s2+s1;//曾试图使用字符串连接成2020-5-1的形式，通过字符串的比较达成是否计算利息的判断，后发现效果不好
            for(int i=0;i<5;i++)
            {
                if(year>de[i].getYear() || (year==de[i].getYear() && month>de[i].getMonth()))
                {
                    de[i].payInterest();
                }
            }
            if(year==2022 && month>=7)
            {
                std::cout << sAll << ",输出所有账户的信息：" << std::endl;
                std::cout <<
                std::setw(10) << std::setiosflags(std::ios::left) << "账号" <<
                std::setw(10) << std::setiosflags(std::ios::left) << "户名" <<
                std::setw(12) << std::setiosflags(std::ios::left) << "密码" <<
                std::setw(13) << std::setiosflags(std::ios::left) << "余额" <<
                std::setw(14) << std::setiosflags(std::ios::left) << "月利率" <<
                std::setw(10) << std::setiosflags(std::ios::left) << "开户时间" << std::endl;
                for(int i=0;i<5;i++)
                {
                    de[i].showAccount();
                }
                if(month == 8)
                {
                    std::cout << "本月调整利息率为0.4%" << std::endl;
                    Deposit::changeRate(0.4/100);
                }
            }
        }
    }
    return 0;
}
