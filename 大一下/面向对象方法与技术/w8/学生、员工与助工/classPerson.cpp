//
//  classPerson.cpp
//  学生、员工与助工
//
//  Created by 杨博文 on 2024/4/11.
//

#include "classPerson.hpp"
void Person::setName(std::string name)
{
    _name=name;
}
void Person::setAge(int age)
{
    _age=age;
}
std::string Person::getName()
{
    return _name;
}
int Person::getAge()
{
    return _age;
}
