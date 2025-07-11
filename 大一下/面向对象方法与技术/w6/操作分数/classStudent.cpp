//
//  classStudent.cpp
//  操作分数
//
//  Created by 杨博文 on 2024/3/29.
//

#include "classStudent.hpp"
void Student::ShowAll()
{
    std::cout <<
    std::setw(10) << std::setiosflags(std::ios::left) << _name <<
    std::setw(10) << std::setiosflags(std::ios::left) << _credits <<
    std::setw(10) << std::setiosflags(std::ios::left) << _score << std::endl;
}
void Student::setName(std::string name)
{
    _name = name;
}
int Student::ifName(std::string name)
{
    if(name==_name)
        return 1;
    return 0;
}
