//
//  fraction.cpp
//  分数的重载
//
//  Created by 杨博文 on 2024/5/8.
//

#include "fraction.hpp"
//«Û◊Ó¥Ûπ´‘º ˝
long fraction::gcd() const
{
    long m, m1(_num), m2(_den);
    while (m2)
    {
        m = m1;
        m1 = m2;
        m2 = m % m2;
    }
    return labs(m1);
}

//∑÷ ˝±Í◊ºªØ∫Ø ˝
void fraction::standardize()
{
    if (_num == 0L || _den == 0L)     //»∑±£∑÷ƒ∏≤ªŒ™0
    {
        _num = 0L;
        _den = 1L;
        return;
    }
    if (_den < 0L)              //∑÷ ˝µƒ∑˚∫≈”√∑÷◊”µƒ∑˚∫≈±Ì æ
    {
        _num = -_num;
        _den = -_den;
    }
    long g = gcd();            //◊‹±Ì æŒ™◊ÓºÚ∑÷ ˝
    _num /= g;
    _den /= g;
}
//ππ‘Ï∫Ø ˝
fraction::fraction(long n, long d) :_num(n), _den(d)
{
    standardize();
}

void fraction::Show() const
{
    int n = _num / gcd();
    int d = _den / gcd();
    cout << n << '/' << d;
}
//∏∫∫Ø ˝£¨«Ûœ‡∑¥ ˝£¨≥…‘±∫Ø ˝
fraction fraction::operator-() const
{
    return fraction(-_num, _den);
}
//∏∫∫Ø ˝£¨«Ûœ‡∑¥ ˝£¨”—‘™∫Ø ˝
/*friend fraction operator-(const fraction& f)
{
    return fraction(-f._num, f._den);
}
*/
//‘ÀÀ„+£¨≥…‘±∫Ø ˝
/*fraction fraction::operator+(const fraction& f) const
{
    fraction result;
    result._num = _num * f._den + _den * f._num;
    result._den = _den * f._den;
    result.standardize();
    return result;
    //return fraction(_num *f._den+_den *f._num,_den *f._den);
}
*/
//‘ÀÀ„+£¨”—‘™∫Ø ˝
fraction operator+(const fraction& f1, const fraction& f2)
{
    return fraction(f1._num * f2._den + f1._den * f2._num, f1._den * f2._den);
}
//‘ÀÀ„*, ≥…‘±∫Ø ˝
fraction fraction::operator*(const fraction& f) const
{
    return fraction(_num * f._num, _den * f._den);
}
//‘ÀÀ„*, ”—‘™∫Ø ˝
/*fraction fraction::operator*(const fraction& f1, const fraction& f2) {
    return fraction(f1._num * f2._num, f1._den * f2._den);
}
*/
//«∞◊∫++
fraction& fraction::operator++()
{
    _num += _den;
    return *this;
}
//∫Û◊∫++,int–Õ–Èƒ‚≤Œ ˝
fraction fraction::operator++(int)
{
    _num += _den;
    return fraction(_num - _den, _den);
}
//«∞◊∫++, ”—‘™∫Ø ˝
/*fraction& operator++(fraction& f)
{
    f._num += f._den£∫
        return f;
}
*/
//∫Û◊∫++,int–Õ–Èƒ‚≤Œ ˝, ”—‘™∫Ø ˝
/*fraction operator++(fraction& f, int x)
{
    f._num += f._den;
    return fraction(f._num - f._den, f._den);
}
*/
//¿‡–Õ◊™ªª∫Ø ˝£¨÷ªƒ‹ «≥…‘±∫Ø ˝£¨∫Ø ˝∂®“Â ±≤ª–Ë“™∑µªÿ÷µ
fraction::operator long() const
{
    return _num / _den;
}
//∏≥÷µ∫Ø ˝£¨÷ªƒ‹ «≥…‘±∫Ø ˝
fraction& fraction::operator=(const fraction& f)
{
    _num = f._num;
    _den = f._den;
    return *this;
}
//∏¥∫œ∏≥÷µ‘ÀÀ„∑˚+=
fraction& operator+=(fraction& f1, const fraction& f2)
{
    f1 = f1 + f2;
    return f1;
}
//±»Ωœ∫Ø ˝(>)
bool fraction::operator>(const fraction& f) const
{
    return _num * f._den > f._num * _den;
}
// ‰»Î∫Ø ˝£¨÷ªƒ‹ «”—‘™∫Ø ˝
istream& operator>>(istream& is, fraction& f)
{
    char c;
    is >> f._num >> c >> f._den;
    f.standardize();
    return is;
}

// ‰≥ˆ∫Ø ˝£¨÷ªƒ‹ «”—‘™∫Ø ˝
ostream& operator<<(ostream& os, const fraction& f)
{
    os << f._num << '/' << f._den;
    return os;
}

