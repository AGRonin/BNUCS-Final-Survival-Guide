//
//  classPerson.cpp
//  查找模版
//
//  Created by 杨博文 on 2024/5/16.
//

#include "classPerson.hpp"
bool Person::operator== (const Person& p)
{
    if(_name==p._name && _age==p._age)
    {
        return true;
    }
    return false;
}
std::ostream& operator<<(std::ostream& o,const Person& p)
{
    return o<<"Person(\"" << p._name << "\"," << p._age << ")";
}
