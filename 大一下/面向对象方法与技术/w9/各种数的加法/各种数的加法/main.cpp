//
//  main.cpp
//  各种数的加法
//
//  Created by 杨博文 on 2024/4/21.
//

#include "classNumber.hpp"
#include "classComplex.hpp"
#include "classFraction.hpp"
#include "classHugeInt.hpp"
int main(int argc, const char * argv[])
{
    Sum* ps1, * ps2;
    Number a(25.0), b(30.5);
    ps1 = &a; ps2 = &b;
    ps1->Show();
    std::cout << " + ";
    ps2->Show();
    std::cout << " = ";
    ps1->Add(ps2);
    std::cout << std::endl;

    Complex ca(1, 2), cb(3, 4);
    ps1 = &ca; ps2 = &cb;
    ps1->Show();
    std::cout << " + ";
    ps2->Show();
    std::cout << " = ";
    ps1->Add(ps2);
    std::cout << std::endl;
    
    Fraction fa(2,3), fb(3,4);
    ps1 = &fa; ps2 = &fb;
    ps1->Show();
    std::cout << " + ";
    ps2->Show();
    std::cout << " = ";
    ps1->Add(ps2);
    std::cout << std::endl;
    
    Huge_Int ha("+12345678901234567890"),hb("+99999999999999999999");
    //Huge_Int ha("-12345678901234567890"),hb("+99999999999999999999");//这是一组减法的测试数据
    ps1 = &ha; ps2 = &hb;
    ps1->Show();
    std::cout << " + ";
    ps2->Show();
    std::cout << " = ";
    ps1->Add(ps2);
    std::cout << std::endl;
    
    return 0;
}
//总算调试结束了。一开始以为这个加法没有那么难，直到每一步都是问题，从读数到符号判断，再到加法和减法要分别写。最后看了看一共创造了8个函数……
