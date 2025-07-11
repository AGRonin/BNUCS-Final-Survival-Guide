//
//  classStudent.cpp
//  栈类模版
//
//  Created by 杨博文 on 2024/5/16.
//

#include "classStudent.hpp"
student::student(std::string name, int id):_name(name),_id(id){}
std::ostream& operator<<(std::ostream& o,const student& s)
{
    o << s._name <<" "<< s._id;
    return o;
}
std::istream& operator>>(std::istream& i,student& s)
{
    i >> s._name >> s._id;
    return i;
}
