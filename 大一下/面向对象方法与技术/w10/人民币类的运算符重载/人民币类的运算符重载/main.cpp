//
//  main.cpp
//  人民币类的运算符重载
//
//  Created by 杨博文 on 2024/4/25.
//

/*设计人民币类，成员数据包含正负标志位、元、角、分 ，设计构造函数、重载＋、－、前置自增、后置自增、前置自减、后置自减、输出流插入运算符<<、输入流提取运算符>> . 其中前置自减、后置自减、<<和>>重载成友元函数。
 自增表示增加1分钱。自减表示减少1分钱。
 编写主函数测试人民币类。
*/

#include "classRMB.hpp"

int main(int argc, const char * argv[]) {
    char ifcontinue='y';
    while(ifcontinue=='y'||ifcontinue=='Y')
    {
        RMB rmb1,rmb2;
        std::cout << "请构造两个人民币：\n";
        std::cin >> rmb1 >> rmb2;
        for(int i=0;i<6;i++)
        {
            std::cout << "请选择运算(A:+/S:-/Q:++i/H:i++/J:--i/K:i--/):";
            char choice;
            std::cin >> choice;
            switch (choice) 
            {
                case 'a':
                case 'A':
                    std::cout << "(" << rmb1 << ")+(" << rmb2 << ")=(" << rmb1+rmb2 << ")\n";
                    break;
                case 's':
                case 'S':
                    std::cout << "(" << rmb1 << ")-(" << rmb2 << ")=(" << rmb1-rmb2 << ")\n";
                    break;
                case 'q':
                case 'Q':
                    std::cout << "++(" << rmb1 << ")=(" << ++rmb1 << ")\n";
                    break;
                case 'h':
                case 'H':
                    std::cout << "(" << rmb1 << ")++=(" << rmb1++ << ")\n人民币1:(" << rmb1 << ")\n";
                    break;
                case 'j':
                case 'J':
                    std::cout << "--(" << rmb1 << ")=(" << --rmb1 << ")\n";
                    break;
                case 'k':
                case 'K':
                    std::cout << "(" << rmb1 << ")--=(" << rmb1-- << ")\n人民币1:(" << rmb1 << ")\n";
                    break;
            }
        }
        std::cout << "您还要继续吗？(Y/N):";
        std::cin >> ifcontinue;
    }
    std::cout << "press any key to continue…";
    return 0;
}
