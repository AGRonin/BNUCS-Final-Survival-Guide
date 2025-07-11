//
//  classTeacher.cpp
//  操作分数
//
//  Created by 杨博文 on 2024/3/29.
//

#include "classTeacher.hpp"
int Teacher::ifName(std::string name)
{
    if(name==_name)
        return 1;
    return 0;
}
void Teacher::setName(std::string name)
{
    _name=name;
}
void Teacher::addAll(Student& stu)
{
    int a,b;
    std::cout << "请输入要增加的学分：";
    std::cin >> a;
    std::cout << "教师" << this->_name << "给学生" << stu._name << "增加" << a << "学分，操作成功。\n";
    stu._credits += a;
    std::cout << "请输入要增加的总成绩：";
    std::cin >> b;
    std::cout << "教师" << this->_name << "给学生" << stu._name << "增加总成绩" << b << "，操作成功。\n";
    stu._score += b;
}
