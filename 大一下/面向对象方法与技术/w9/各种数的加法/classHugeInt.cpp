//
//  classHugeInt.cpp
//  各种数的加法
//
//  Created by 杨博文 on 2024/4/21.
//

#include "classHugeInt.hpp"
Huge_Int::Huge_Int(const char* str)
{
    _sign=str[0];
    //先统计字符数组的长度
    int length=0;
    for(int i=1;i<111;i++)
    {
        if(str[i]=='\0')
        {
            break;
        }
        length++;
    }
    _length=length;
    for(int i=0;i<110;i++)
    {
        if(i+length<110)
        {
            _data[i]=0;
        }
        else
        {
            _data[i]=str[-109+i+length]-48;
        }
    }
}
void Huge_Int::Show()
{
    std::cout << _sign;
    int ifprint=0;
    for(int i=0;i<110;i++)
    {
        if(_data[i]!=0 && ifprint==0)
        {
            ifprint=1;
        }
        if(_data[i]!=0 || ifprint!=0)
        {
            std::cout << _data[i];
        }
    }
}
char Huge_Int::getsign()
{
    return _sign;
}
unsigned* Huge_Int::getdata()
{
    return _data;
}
int Huge_Int::getlength()
{
    return _length;
}
void Huge_Int::setsign(char sign)
{
    _sign=sign;
}
void Huge_Int::setdata(unsigned* data)
{
    for(int i=0;i<110;i++)
    {
        _data[i]=data[i];
    }
}
void Huge_Int::setlength(int length)
{
    _length=length;
}
void Huge_Int::Add(Sum *num)
{
    Huge_Int* x=dynamic_cast<Huge_Int*>(num);
    int length=x->getlength();
    unsigned* data=x->getdata();
    char sign=x->getsign();
    char signResult='+';
    unsigned dataResult[110];
    //先做同号加法，保留符号，绝对值相加
    if(sign==_sign)
    {
        signResult=_sign;
        int jinwei=0;
        for(int i=109;i>=0;i--)
        {
            dataResult[i]=(_data[i]+data[i]+jinwei)%10;
            if(_data[i]+data[i]+jinwei<10)
            {
                jinwei=0;
            }
            else
            {
                jinwei=1;
            }
        }
    }
    //做异号
    else
    {
        //建立两个新的数，第一个是符号为正的数，第二个是负的数，没啥别的就是方便我后面调用
        Huge_Int x1,x2;
        if(_sign=='+')
        {
            x1.setsign(_sign);
            x1.setdata(_data);
            x1.setlength(_length);
            x2.setsign(sign);
            x2.setdata(data);
            x2.setlength(length);
        }
        else
        {
            x2.setsign(_sign);
            x2.setdata(_data);
            x2.setlength(_length);
            x1.setsign(sign);
            x1.setdata(data);
            x1.setlength(length);
        }
        //比较两者大小
        int who=whoisbigger(x1, x2);
        if(who==0)
        {
            std::cout << "0";
            return;
        }
        if(who==1)
        {
            signResult='+';
            for(int j=0;j<110;j++)
            {
                dataResult[j]=answer(x1, x2)[j];//如果被减数大于减数，取正号，做绝对值的减法
            }
        }
        if(who==2)
        {
            signResult='-';
            for(int j=0;j<110;j++)
            {
                dataResult[j]=answer(x2, x1)[j];//如果减数大于被减数，取负号，做绝对值反过来的减法
            }
        }
    }
    //开始数位数，这一步并不必要，因为在后面并不会用到这个长度，但为了结构的完整性和逻辑的自洽性（我不希望最后结果的长度是0或者什么奇怪的东西），所以加入这一部分，也便于当我需要的是Huge_Int型的加法结果时可以自然而然的成立
    int lengthResult=0,ifcount=0;
    for(int i=0;i<110;i++)
    {
        if(dataResult[i]!=0 && ifcount==0)
        {
            ifcount=1;
        }
        if(dataResult[i]!=0 || ifcount!=0)
        {
            lengthResult++;
        }
    }
    //这是最终的答案
    Huge_Int FinalResult;
    FinalResult.setsign(signResult);
    FinalResult.setdata(dataResult);
    FinalResult.setlength(lengthResult);
    FinalResult.Show();
}
//判断减法符号的函数
int whoisbigger(const Huge_Int& x1,const Huge_Int& x2)
{
    for(int i=0;i<110;i++)
    {
        if(x1._data[i]>x2._data[i])
        {
            return 1;
        }
        if(x1._data[i]<x2._data[i])
        {
            return 2;
        }
    }
    return 0;
}
//只做数据的减法，1-2，这里的数据保证了x1>x2
unsigned* answer(const Huge_Int& x1,const Huge_Int& x2)
{
    int jiewei=0;
    unsigned result[110];
    for(int i=109;i>=0;i--)
    {
        result[i]=(x1._data[i]-x2._data[i]-jiewei)%10;
        if(x1._data[i]-x2._data[i]-jiewei<0)
        {
            jiewei=1;
        }
        else
        {
            jiewei=0;
        }
    }
    return result;
}
