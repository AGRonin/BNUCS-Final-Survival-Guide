//
//  classDeposit.cpp
//  一个小小的银行
//
//  Created by 杨博文 on 2024/3/22.
//

#include "classDeposit.hpp"

float Deposit::_rate=0.50/100;
int Deposit::_numTotal=0;
Deposit::Deposit(std::string name, int password, float balance, int year, int month):_name(name),_password(password),_balance(balance),_year(year),_month(month)
{
    _time=std::to_string(_year)+"-"+std::to_string(_month)+"-1";
    _number= ++_numTotal;
}
void Deposit::payInterest()
{
    _balance=int(_balance*(1+_rate)*1000);
    if(int(_balance)%10<=4)
    {
        _balance=int(_balance/10)/100.0;
    }
    else
    {
        _balance=(int(_balance/10)+1)/100.0;
    }
}
void Deposit::showAccount() const
{
    std::cout << std::left;
    std::cout <<
    std::setw(7) << std::setiosflags(std::ios::left) << _number <<
    std::setw(10) << std::setiosflags(std::ios::left) << _name <<
    std::setw(10) << std::setiosflags(std::ios::left) << _password <<
    std::fixed << std::setw(10) << std::setprecision(2) << std::setiosflags(std::ios::left) << std::setiosflags(std::ios::fixed) << _balance <<
    std::setw(4) << std::setiosflags(std::ios::left) << _rate*100 <<
    std::setw(6) << std::setiosflags(std::ios::left) << "%" <<
    std::setw(10) << std::setiosflags(std::ios::left) << _time << std::endl;
}
void Deposit::changeRate(float rate)
{
    _rate=rate;
}
int Deposit::getYear()
{
    return _year;
}
int Deposit::getMonth()
{
    return _month;
}

