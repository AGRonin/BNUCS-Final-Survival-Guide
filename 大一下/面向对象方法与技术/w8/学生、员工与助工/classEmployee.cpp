//
//  classEmployee.cpp
//  学生、员工与助工
//
//  Created by 杨博文 on 2024/4/11.
//

#include "classEmployee.hpp"
void Employee::setEmployeeID(int id)
{
    _employeeID=id;
}
void Employee::setDepartment(std::string depart)
{
    _department=depart;
}
int Employee::getEmployeeID()
{
    return _employeeID;
}
std::string Employee::getDepartment()
{
    return _department;
}
