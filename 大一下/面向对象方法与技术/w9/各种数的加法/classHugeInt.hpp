//
//  classHugeInt.hpp
//  各种数的加法
//
//  Created by 杨博文 on 2024/4/21.
//

#ifndef classHugeInt_hpp
#define classHugeInt_hpp

#include "classSum.hpp"
class Huge_Int:public Sum
{
private:
    char _sign;//符号+-
    unsigned _data[110];//以[109]为个位，从后往前记，位数不够的前面补0
    int _length;//长度
public:
    Huge_Int(const char* str="0");
    virtual ~Huge_Int(){};
    virtual void Show();
    char getsign();
    unsigned* getdata();
    int getlength();
    void setsign(char sign);
    void setdata(unsigned* data);
    void setlength(int length);
    virtual void Add(Sum *num);
    friend int whoisbigger(const Huge_Int& x1,const Huge_Int& x2);//判断减法符号的函数
    friend unsigned* answer(const Huge_Int& x1,const Huge_Int& x2);//只做数据的减法，1-2
};

#endif /* classHugeInt_hpp */
