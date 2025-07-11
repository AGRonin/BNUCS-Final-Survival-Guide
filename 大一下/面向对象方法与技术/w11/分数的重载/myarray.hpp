//
//  myarray.hpp
//  分数的重载
//
//  Created by 杨博文 on 2024/5/8.
//

#ifndef MYARRAYH
#define MYARRAYH
#include <iostream>
using namespace std;
class IntArray
{
    int _size;
    int* _data;
public:
    IntArray(int n);
    ~IntArray();
    int& operator[](int i);
    int size() const;
};
#endif
