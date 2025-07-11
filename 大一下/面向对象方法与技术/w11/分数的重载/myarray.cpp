//
//  myarray.cpp
//  分数的重载
//
//  Created by 杨博文 on 2024/5/8.
//

#include "myarray.hpp"
IntArray::IntArray(int n)
{
    if (n < 1)
    {
        cout << "Error dimension description";
        exit(1);
    }
    _size = n;
    _data = new int[_size];
}
IntArray::~IntArray()
{
    if (_data)
    {
        delete[] _data;
        _data = NULL;
    }
}
int IntArray::size() const
{
    return _size;
}
int& IntArray::operator[](int i)
{
    if (i<1 || i>_size)         //œ¬±Í‘ΩΩÁºÏ≤È
    {
        cout << endl << "Subscript out of range";
        delete[] _data;
        _data = NULL;
        exit(2);
    }
    return _data[i - 1];     //IntArryµƒœ¬±Í¥”1ø™ º
}
