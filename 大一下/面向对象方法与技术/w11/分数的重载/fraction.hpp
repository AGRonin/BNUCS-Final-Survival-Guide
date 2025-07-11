//
//  fraction.hpp
//  分数的重载
//
//  Created by 杨博文 on 2024/5/8.
//

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
using namespace std;

class fraction
{
    long _num;                               //∑÷◊”
    long _den;                               //∑÷ƒ∏
    long gcd() const;                //«Û◊Ó¥Ûπ´‘º ˝
    void standardize();                //∑÷ ˝±Í◊ºªØ∫Ø ˝
public:
    fraction(long n = 0, long d = 1);            //ππ‘Ï∫Ø ˝
    operator long() const;            //¿‡–Õ◊™ªª∫Ø ˝£¨÷ªƒ‹ «≥…‘±∫Ø ˝£¨∫Ø ˝∂®“Â ±≤ª–Ë“™∑µªÿ÷µ
    fraction operator-() const;            //∏∫∫Ø ˝£¨«Ûœ‡∑¥ ˝
    fraction& operator=(const fraction& f);        //∏≥÷µ∫Ø ˝£¨÷ªƒ‹ «≥…‘±∫Ø ˝
    bool operator>(const fraction& f) const;        //±»Ωœ∫Ø ˝£®>)
    //fraction operator+(const fraction&) const;        //‘ÀÀ„+, ≥…‘±∫Ø ˝
    friend fraction operator+(const fraction& f1, const fraction& f2);  //‘ÀÀ„+£¨”—‘™∫Ø ˝
    fraction operator*(const fraction&) const;        //‘ÀÀ„*, ≥…‘±∫Ø ˝
    friend fraction& operator+=(fraction&, const fraction&);     //‘ÀÀ„+=£¨”—‘™∫Ø ˝
    fraction& operator++();                //«∞◊∫++£¨≥…‘±∫Ø ˝
    //friend fraction& operator++(fraction& f);        //«∞◊∫++, ”—‘™∫Ø ˝
    fraction operator++(int);                //∫Û◊∫++, ≥…‘±∫Ø ˝£¨int «“ª∏ˆ–Èƒ‚≤Œ ˝
    //friend fraction operator++(fraction& f,int);    //∫Û◊∫++, ”—‘™∫Ø ˝£¨int «“ª∏ˆ–Èƒ‚≤Œ ˝  void Show() const;
    friend istream& operator>>(istream&, fraction&);    //Ã·»°‘ÀÀ„∑˚£¨÷ªƒ‹ «”—‘™∫Ø ˝
    friend ostream& operator<<(ostream&, const fraction&);//≤Â»Î‘ÀÀ„∑˚£¨÷ªƒ‹ «”—‘™∫Ø ˝
    void Show() const;
};
#endif
