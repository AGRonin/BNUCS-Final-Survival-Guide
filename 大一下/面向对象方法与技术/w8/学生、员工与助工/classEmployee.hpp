//
//  classEmployee.hpp
//  学生、员工与助工
//
//  Created by 杨博文 on 2024/4/11.
//

#ifndef classEmployee_hpp
#define classEmployee_hpp

#include "classPerson.hpp"
class Employee: virtual public Person
{
private:
    int _employeeID;
    std::string _department;
public:
    void setEmployeeID(int id);
    void setDepartment(std::string depart);
    int getEmployeeID();
    std::string getDepartment();
};

#endif /* classEmployee_hpp */
