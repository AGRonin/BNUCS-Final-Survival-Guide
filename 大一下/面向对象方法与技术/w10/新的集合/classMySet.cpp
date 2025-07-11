//
//  classMySet.cpp
//  新的集合
//
//  Created by 杨博文 on 2024/4/27.
//

#include "classMySet.hpp"
MySet::MySet()
{
    _count=0;
    for(int i=0;i<MAX_COUNT;i++)
    {
        _array[i]=0;
    }
}
std::istream& operator>>(std::istream& i, MySet& set)
{
    std::cout << "请输入集合中元素的个数n(n>0)：";
    i >> set._count;
    std::cout << "请输入这4个元素（不要重复）：";
    for(int j=0;j<set._count;j++)
    {
        i >> set._array[j];
    }
    return i;
}
std::ostream& operator<<(std::ostream& o, const MySet& set)
{
    for(int j=0;j<set._count;j++)
    {
        if(j==0)
        {
            o << "(";
        }
        o << set._array[j];
        if(j==set._count-1)
        {
            o << ")";
            continue;
        }
        o << ",";
    }
    return o;
}
int& MySet::operator[](unsigned i)
{
    return _array[i];
}
//这里需要一个const版本，否则在后面对于const Myset& set没法用
const int& MySet::operator[](unsigned i) const
{
    return _array[i];
}
bool MySet::IsInSet(int x) const
{
    for(int j=0;j<_count;j++)
    {
        if(x==_array[j])
        {
            return true;
        }
    }
    return false;
}
MySet MySet::operator+(const MySet& set) const
{
    MySet result;
    int i=0;
    for(i=0;i<_count;i++)
    {
        result[i]=_array[i];
    }
    for(int j=0;j<set._count;j++)
    {
        if(IsInSet(set[j]))
        {
            continue;
        }
        result[i]=set[j];
        i++;
    }
    result._count=i;
    return result;
}
MySet MySet::operator-(const MySet& set) const
{
    MySet result;
    int i=0;
    for(int j=0;j<_count;j++)
    {
        if(set.IsInSet(_array[j]))
        {
            continue;
        }
        result[i]=_array[j];
        i++;
    }
    result._count=i;
    return result;
}
MySet& MySet::operator++()
{
    for(int i=0;i<_count;i++)
    {
        _array[i]++;
    }
    return *this;
}
MySet MySet::operator++(int x)
{
    MySet old(*this);
    for(int i=0;i<_count;i++)
    {
        _array[i]++;
    }
    return old;
}
MySet& operator--(MySet& set)
{
    for(int i=0;i<set._count;i++)
    {
        set._array[i]--;
    }
    return set;
}
MySet operator--(MySet& set,int x)
{
    MySet old(set);
    for(int i=0;i<set._count;i++)
    {
        set._array[i]--;
    }
    return old;
}
