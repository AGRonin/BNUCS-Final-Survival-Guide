//
//  classPerson.hpp
//  学生、员工与助工
//
//  Created by 杨博文 on 2024/4/11.
//

#ifndef classPerson_hpp
#define classPerson_hpp

#include <iostream>
class Person
{
private:
    std::string _name;
    int _age;
public:
    void setName(std::string name);
    void setAge(int age);
    std::string getName();
    int getAge();
};

#endif /* classPerson_hpp */
