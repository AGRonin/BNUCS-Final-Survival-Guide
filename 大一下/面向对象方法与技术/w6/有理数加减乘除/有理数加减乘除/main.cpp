//
//  main.cpp
//  有理数加减乘除
//
//  Created by 杨博文 on 2024/3/29.
//

/*1.1设计分数类Fraction
 成员数据(私有) 分子int _num
            分母int _den
 成员函数(公有)
         构造函数 Fraction(int n=0,int den=1); 如果是负数，符号写在分子上
         化简函数 void Standard();   化简函数使得分子分母互质
         Set函数 void Set(int, int);
         输出函数 void Show() const;
         其他函数自行增加
 1.2友元函数
     加法函数 Fraction Add(const Fraction& f1,const Fraction& f2);
     减法函数
     乘法函数
     除法函数
 1.3主程序（main函数）
     用户输入4个任意整数，创建2个分数；程序输出加、减、乘、除的结果。
 在输入时，如果用户输入的分母为0，则提示“不能构成分数，再次输入”；在除法的时候，如果除数为0，则提示“不能除以0”，程序退出（exit）.
     以上过程可以重复，一直到用户输入”n”，程序结束(return)。
*/
#include "classFraction.hpp"

int main(int argc, const char * argv[]) {
    while(true)
    {
        int a,b,c,d;
        while(true)
        {
            std::cout << "Input f1:";
            std::cin >> a >> b;
            if(b!=0)
            {
                break;
            }
            std::cout << "不能构成分数，再次输入" << std::endl;
        }
        while(true)
        {
            std::cout << "Input f2:";
            std::cin >> c >> d;
            if(d!=0)
            {
                break;
            }
            std::cout << "Den can’t be 0. " << std::endl;
        }
        Fraction f1=Fraction(a,b);
        Fraction f2=Fraction(c,d);
        //加法
        f1.Show();
        std::cout << " + ";
        f2.Show();
        std::cout << " = ";
        Add(f1,f2).Show();
        std::cout << std::endl;
        //减法
        f1.Show();
        std::cout << " - ";
        f2.Show();
        std::cout << " = ";
        Minus(f1,f2).Show();
        std::cout << std::endl;
        //乘法
        f1.Show();
        std::cout << " * ";
        f2.Show();
        std::cout << " = ";
        Multiply(f1,f2).Show();
        std::cout << std::endl;
        //除法
        if(f2.ifZero()==0)
        {
            std::cout << "Can’t divide by 0 ." << std::endl;
            exit(-1);
        }
        else
        {
            f1.Show();
            std::cout << " / ";
            f2.Show();
            std::cout << " = ";
            Divide(f1,f2).Show();
            std::cout << std::endl;
        }
        std::cout << "Continue?(y/n): ";
        char ifContinue;
        std::cin >> ifContinue;
        if(ifContinue=='n')
        {
            std::cout << "Byebye~" << std::endl;
            break;
        }
    }
    return 0;
}
