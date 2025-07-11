//
//  classTeacher.hpp
//  操作分数
//
//  Created by 杨博文 on 2024/3/29.
//

#ifndef classTeacher_hpp
#define classTeacher_hpp

#include "classStudent.hpp"

class Teacher
{
private:
    std::string _name;
public:
    int ifName(std::string name);
    void setName(std::string name);
    void addAll(Student& stu);
};

#endif /* classTeacher_hpp */
