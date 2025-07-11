//
//  classIntArray.hpp
//  从1开始的整数数组
//
//  Created by 杨博文 on 2024/5/10.
//

#ifndef classIntArray_hpp
#define classIntArray_hpp

#include <iostream>

class IntArray
{
private:
    int _size;
    int* _data;
public:
    IntArray(int n);//构造函数
    ~IntArray();//析构函数
    int& operator[] (int i);//重载下标
    int size() const;//输出长度
    IntArray& operator= (const IntArray& a);//重载赋值号
    IntArray(const IntArray& a);//拷贝构造函数
    friend std::ostream& operator<< (std::ostream& o,const IntArray& a);//重载输出流
    friend std::istream& operator>> (std::istream& i,IntArray& a);//重载输入流
};

#endif /* classIntArray_hpp */
