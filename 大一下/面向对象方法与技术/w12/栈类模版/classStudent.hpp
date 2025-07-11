//
//  classStudent.hpp
//  栈类模版
//
//  Created by 杨博文 on 2024/5/16.
//

#ifndef classStudent_hpp
#define classStudent_hpp

#include <iostream>
#include <fstream>

class student
{
private:
    std::string _name;
    int _id;
public:
    student(std::string name="", int id=0);
    friend std::ostream& operator<<(std::ostream& o,const student& s);
    friend std::istream& operator>>(std::istream& i,student& s);
};

#endif /* classStudent_hpp */
