//
//  classIntArray.cpp
//  从1开始的整数数组
//
//  Created by 杨博文 on 2024/5/10.
//

#include "classIntArray.hpp"
IntArray::IntArray(int n)
{
    if (n < 1)
    {
        std::cout << "Error dimension description";
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
        _data = NULL;//将指针清空
    }
}
int IntArray::size() const
{
    return _size;
}
int& IntArray::operator[](int i)
{
    if (i<1 || i>_size)
    {
        std::cout << std::endl << "Subscript out of range";
        delete[] _data;
        _data = NULL;
        exit(2);
    }
    return _data[i - 1];//a[1]是_data[0]
}
IntArray& IntArray::operator= (const IntArray& a)
{
    _size=a._size;
    if(this == &a)
    {
        return *this;
    }
    if(_data)
    {
        delete[] _data;
        _data=NULL;
    }
    if(a._data==NULL)
    {
        _data=NULL;
    }
    else
    {
        _data=new int[a._size+1];
        for(int i=0;i<_size;i++)
        {
            _data[i]=a._data[i];
        }
    }
    return *this;
}
IntArray::IntArray(const IntArray& a)
{
    _size=a._size;
    if(a._data==NULL)
    {
        _data=NULL;
    }
    else
    {
        _data=new int[_size+1];
        for(int i=0;i<_size;i++)
        {
            _data[i]=a._data[i];
        }
    }
}
std::ostream& operator<< (std::ostream& o,const IntArray& a)
{
    o<<"{ ";
    for(int i=0;i<a._size;i++)
    {
        o << a._data[i];
        if(i!=a._size-1)
        {
            o<< ", ";
        }
    }
    return o<<"}\n";
}
std::istream& operator>> (std::istream& i,IntArray& a)
{
    std::cout << "请依次输入所有数据，空格隔开\n";
    for(int j=1;j<=a._size;j++)
    {
        i >> a[j];
    }
    return i;
}
