//
//  mystring.cpp
//  分数的重载
//
//  Created by 杨博文 on 2024/5/8.
//

#include "mystring.hpp"
//ππ‘Ï∫Ø ˝, str("abc")
STRING::STRING(const char* c)
{
    if (c == NULL)
        _p = NULL;
    else
    {
        _p = new char[strlen(c) + 1];
        strcpy(_p, c);
    }
}
//Œˆππ∫Ø ˝
STRING::~STRING()
{
    if (_p)
    {
        delete[] _p;
        _p = NULL;
    }
}
//‘ÀÀ„= £¨str=str2
STRING& STRING::operator=(const STRING& s)
{
    if (&s == this)
        return *this;
    if (_p)
    {
        delete[] _p;
        _p = NULL;
    }
    if (s._p == NULL)
        _p = NULL;
    else
    {
        _p = new char[strlen(s._p) + 1];
        strcpy(_p, s._p);
    }
    return *this;
}
//‘ÀÀ„= , str="abc"
STRING& STRING::operator=(const char* s)
{
    *this = STRING(s);
    return *this;
}
//øΩ±¥ππ‘Ï, str(str1)
STRING::STRING(const STRING& s)
{
    if (s._p == NULL)
        _p = NULL;
    else
    {
        _p = new char[strlen(s._p) + 1];
        strcpy(_p, s._p);
    }
}
// ‰≥ˆ∫Ø ˝
ostream& operator<<(ostream& o,const STRING& s)
{
    return o << s._p;
}
