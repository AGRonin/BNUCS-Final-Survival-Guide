//
//  classStudent.cpp
//  学生的成绩
//
//  Created by 杨博文 on 2024/5/10.
//

#include "classStudent.hpp"
std::ostream& operator<<(std::ostream& o,const student& s)
{
    o << s._name <<" "<< s._id <<" "<< s._scoreLanguage <<" "<< s._scoreMath <<" "<< s._scoreEnglish<<"\n";
    return o;
}
std::istream& operator>>(std::istream& i,student& s)
{
    i >> s._name >> s._id >> s._scoreLanguage >> s._scoreMath >> s._scoreEnglish;
    return i;
}
bool student::operator>(const student& s) const
{
    if(_scoreLanguage+_scoreMath+_scoreEnglish>s._scoreLanguage+s._scoreMath+s._scoreEnglish)
    {
        return true;
    }
    if(_scoreLanguage+_scoreMath+_scoreEnglish<s._scoreLanguage+s._scoreMath+s._scoreEnglish)
    {
        return false;
    }
    if(_scoreLanguage>s._scoreLanguage)
    {
        return true;
    }
    if(_scoreLanguage<s._scoreLanguage)
    {
        return false;
    }
    if(_scoreMath>s._scoreMath)
    {
        return true;
    }
    return false;
}
bool student::operator==(const student& s) const
{
    return (_scoreLanguage==s._scoreLanguage && _scoreMath==s._scoreMath && _scoreEnglish==s._scoreEnglish);
}
bool student::operator<(const student& s) const
{
    if(*this>s || *this==s)
    {
        return false;
    }
    return true;
}
