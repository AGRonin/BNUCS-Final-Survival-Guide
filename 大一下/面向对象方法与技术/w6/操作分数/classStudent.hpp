//
//  classStudent.hpp
//  操作分数
//
//  Created by 杨博文 on 2024/3/29.
//

#ifndef classStudent_hpp
#define classStudent_hpp

#include <iostream>
#include <iomanip>
class Teacher;
class Student
{
    friend class Teacher;
private:
    std::string _name;
    int _credits=0;
    int _score=0;
public:
    void ShowAll();
    void setName(std::string name);
    int ifName(std::string name);
};
#endif /* classStudent_hpp */
