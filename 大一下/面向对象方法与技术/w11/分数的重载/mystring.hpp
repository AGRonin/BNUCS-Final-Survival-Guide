//
//  mystring.hpp
//  分数的重载
//
//  Created by 杨博文 on 2024/5/8.
//

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;
class STRING
{
    char* _p;
public:
    STRING(const char* c = NULL);    //ππ‘Ï∫Ø ˝, str("abc")
    STRING(const STRING& s);        //øΩ±¥ππ‘Ï, str(str1)
    ~STRING();
    STRING& operator=(const STRING&);    //∏≥÷µ‘ÀÀ„= £¨str=str2
    STRING& operator=(const char*);    //∏≥÷µ‘ÀÀ„= , str="abc"
    friend ostream& operator<<(ostream&, const STRING&);    // ‰≥ˆ∫Ø ˝
};
#endif

