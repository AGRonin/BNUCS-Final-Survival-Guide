//
//  classDeposit.hpp
//  一个小小的银行
//
//  Created by 杨博文 on 2024/3/22.
//

#ifndef classDeposit_hpp
#define classDeposit_hpp

#include <iostream>
#include <iomanip>
class Deposit
{
private:
    int _number;
    std::string _name;
    int _password;
    float _balance;
    static float _rate;
    int _year;
    int _month;
    std::string _time;
    static int _numTotal;
public:
    Deposit(std::string name, int password, float balance, int year, int month);
    void payInterest();
    void showAccount() const;
    static void changeRate(float rate);
    int getYear();
    int getMonth();
};

#endif /* classDeposit_hpp */
