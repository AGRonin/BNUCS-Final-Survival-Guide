//
//  classPerson.hpp
//  查找模版
//
//  Created by 杨博文 on 2024/5/16.
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
    Person(std::string name, int age):_name(name),_age(age){};
    bool operator== (const Person& p);
    friend std::ostream& operator<<(std::ostream& o,const Person& p);
};

#endif /* classPerson_hpp */
