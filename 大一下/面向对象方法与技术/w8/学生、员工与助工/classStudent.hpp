//
//  classStudent.hpp
//  学生、员工与助工
//
//  Created by 杨博文 on 2024/4/11.
//

#ifndef classStudent_hpp
#define classStudent_hpp

#include "classPerson.hpp"
class Student: virtual public Person
{
private:
    std::string _major;
    int _studentID;
public:
    void setMajor(std::string major);
    void setStudentID(int id);
    std::string getMajor();
    int getStudentID();
};

#endif /* classStudent_hpp */
