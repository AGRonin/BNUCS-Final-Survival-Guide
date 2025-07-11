//
//  main.cpp
//  混合运算计算器
//
//  Created by 杨博文 on 2024/5/17.
//

/*基于上题设计的栈模板，设计实现一个简单的四则运算计算器，可以实现如下的操作：
 例如：     1 + 2×3 – 4 / 2 = 5
         2.5×5 + 7/2 – 1 = 15  
 请不要使用上面的例子进行测试，上面的例子中使用的乘号是乘号，不是x或者*，无法得到正确的结果*/

#include "templateClassMyStack.h"

int main(int argc, const char * argv[]) 
{
    myStack<double> doubleStack;
    myStack<char> charStack;
    myStack<int> tempNumberStack;//只存储输入数字的整数部分，小数部分在发现"."后直接加
    char in='(';//输入，先默认为左括号
    bool ifPerviousSign=true;//上一个输入的是不是符号呢？用来判断接下来如果看到'-'这个是负号还是减号，默认是正确的因为如果开头就是'-'那么其一定是负号
    bool ifNegative=false;//接下来输入的数字要变成负数吗？
    while(true)
    {
        if(in=='+'||in=='-'||in=='*'||in=='/'||in=='(')//如果上一个输入的是符号
        {
            ifPerviousSign=true;
        }
        std::cin >> in;
        if(in=='x')//有的时候人们会使用x来代表乘法，我们考虑到人们的错误。
        {
            in='*';
        }
        if(ifPerviousSign&&in=='-')//如果这样的话，那这个负号的意义是负号，存一下，开始存数
        {
            ifNegative=true;
            ifPerviousSign=false;
            continue;
        }
        if(in>='0'&&in<='9'&&tempNumberStack.ifEmpty())//如果输入的是数字，那么接下来就继续是数字，那就开始算数字
        {
            tempNumberStack.inStack(in-48);
            double temp=-1;//-1代表还没有写值进去，这里由于输入的是数字不包括符号，所以数据应该>=0，故-1可以检验
            double positionDecimal=1;
            int position=1;
            while(true)
            {
                std::cin >> in;
                if(in=='x')//有的时候人们会使用x来代表乘法，我们考虑到人们的错误
                {
                    in='*';
                }
                if(in>='0'&&in<='9'&&temp==-1)
                {
                    tempNumberStack.inStack(in-48);
                }
                if(in=='.')//那么此时这个数是有小数部分的，先结算整数部分，再求小数部分
                {
                    temp=0;
                    position=1;
                    for(int i=0;!tempNumberStack.ifEmpty();i++)//请注意这里不能使用i<tempNumberStack.howMuch()作为结束条件，因为在弹出的过程中howmuch会减少
                    {
                        if(i!=0)
                        {
                            position=position*10;
                        }
                        temp=temp+tempNumberStack.outStack()*position;
                    }
                }
                if(in>='0'&&in<='9'&&temp!=-1)
                {
                    positionDecimal=positionDecimal*0.1;
                    temp=temp+(in-48.0)*positionDecimal;
                }
                if((in<'0'||in>'9')&&in!='.')
                {
                    if(temp==-1)//因为如果有小数部分前面就已经设置了temp的值，这里做之前全是整数的情况的值
                    {
                        temp=0;
                        position=1;
                        for(int i=0;!tempNumberStack.ifEmpty();i++)
                        {
                            if(i!=0)
                            {
                                position=position*10;
                            }
                            temp=temp+tempNumberStack.outStack()*position;
                        }
                    }
                    //接下来把已经算好了的temp放入到doubleStack中作为值
                    doubleStack.inStack(temp);
                    break;
                }
            }
            if(ifNegative)//这里判断这个数要不要变成负数
            {
                temp=doubleStack.outStack();
                temp=temp*(-1);
                doubleStack.inStack(temp);
            }
            ifNegative=false;
            ifPerviousSign=false;
            //接下来检查最近的一个符号是不是乘除法，如果是，计算掉
            if(!charStack.ifEmpty())
            {
                char perviousOperator;
                perviousOperator=charStack.outStack();
                if(perviousOperator=='+'||perviousOperator=='-'||perviousOperator=='(')
                {
                    charStack.inStack(perviousOperator);
                }
                if(perviousOperator=='*')
                {
                    double d1,d2;
                    d2=doubleStack.outStack();
                    d1=doubleStack.outStack();
                    d1=d1*d2;
                    doubleStack.inStack(d1);
                }
                if(perviousOperator=='/')
                {
                    double d1,d2;
                    d2=doubleStack.outStack();
                    d1=doubleStack.outStack();
                    d1=d1/d2;
                    doubleStack.inStack(d1);
                }
            }
        }
        //接下来，我们判断加减乘除，并将符号放进char栈
        if(in=='+'||in=='-'||in=='*'||in=='/'||in=='(')
        {
            charStack.inStack(in);
        }
        //如果是右括号，开始计算直到左括号
        if(in==')')
        {
            double partAnswer=0;
            char sign;
            double temp;
            while(true)//如果符号栈还没空，空了的时候数值栈应该还剩下最后一个数
            {
                sign=charStack.outStack();
                temp=doubleStack.outStack();
                if(sign=='+')
                {
                    partAnswer=partAnswer+temp;
                }
                if(sign=='-')
                {
                    partAnswer=partAnswer-temp;
                }
                if(sign=='(')
                {
                    partAnswer=partAnswer+temp;
                    break;
                }
            }
            doubleStack.inStack(partAnswer);
        }
        if(in=='=')//结束接收，准备写答案
        {
            double answer=0;
            char sign;
            double temp;
            while(!charStack.ifEmpty())//如果符号栈还没空，空了的时候数值栈应该还剩下最后一个数
            {
                sign=charStack.outStack();
                temp=doubleStack.outStack();
                if(sign=='+')
                {
                    answer=answer+temp;
                }
                if(sign=='-')
                {
                    answer=answer-temp;
                }
            }
            temp=doubleStack.outStack();
            answer=answer+temp;//把数值栈中最后一个数给加上，这是你输入的第一个数
            std::cout << answer << std::endl;
            break;
        }
    }
    return 0;
}
