//
//  classMySet.hpp
//  新的集合
//
//  Created by 杨博文 on 2024/4/27.
//

#ifndef classMySet_hpp
#define classMySet_hpp

#include <iostream>
const unsigned MAX_COUNT = 100;
class MySet
{
private:
    int _array[MAX_COUNT];
    unsigned _count;
public:
    MySet();
    friend std::istream& operator>>(std::istream& i, MySet& set);
    friend std::ostream& operator<<(std::ostream& o, const MySet& set);
    int& operator[](unsigned i);//非const版本
    const int& operator[](unsigned i) const;//const版本
    bool IsInSet(int x) const;
    MySet operator+(const MySet& set) const;
    MySet operator-(const MySet& set) const;
    MySet& operator++();
    MySet operator++(int x);
    friend MySet& operator--(MySet& set);
    friend MySet operator--(MySet& set,int x);
};


#endif /* classMySet_hpp */
