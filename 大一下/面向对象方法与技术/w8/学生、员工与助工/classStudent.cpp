//
//  classStudent.cpp
//  学生、员工与助工
//
//  Created by 杨博文 on 2024/4/11.
//

#include "classStudent.hpp"
void Student::setMajor(std::string major)
{
    _major=major;
}
void Student::setStudentID(int id)
{
    _studentID=id;
}
std::string Student::getMajor()
{
    return _major;
}
int Student::getStudentID()
{
    return _studentID;
}
