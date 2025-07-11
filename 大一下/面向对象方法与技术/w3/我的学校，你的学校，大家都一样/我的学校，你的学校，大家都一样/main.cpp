//
//  main.cpp
//  我的学校，你的学校，大家都一样
//
//  Created by 杨博文 on 2024/3/8.
//

/*2.1设计类学校School，包含：
 成员数据（私有）：
     名称： _name，数据类型：char*
     地址：_addr，数据类型：char*
 成员函数（公有）：
     （1）构造函数
 School(const char* name,const char* addr);
         在构造函数中给_name和_addr分配空间，写入_name和_addr的实际内容；并输出“school constructed.” .
     （2）拷贝构造函数
         School(const School& s);
         在拷贝构造函数中给_name和_addr分配空间，写入实际内容；并输出“school copy constructed.” .
     （3）析构函数
         ~School();
         在析构函数中，收回分配给_name和_addr的空间，并输出“school     deconstructed. delete space of name and address.”
     （4）显示学校信息函数void Show() const;
     如果需要其他成员函数，请自行增加。

 2.2 在主函数main()中：
 用户输入学校的名称和地址，创建学校myschool,输出myschool的信息；
 利用myschool拷贝构造新学校对象yourschool,输出yourschool的信息；
 当程序结束时，自动析构yourschool和myschool对象。

 2.3 提示：当需要输入包含空格的字符串时，可以使用下面的方法：
 char str[80];
 cin.getline(str,80);            //字符串被放在str中，字符串长度不要超过79

 2.4下面是程序的运行结果（供参考）：
 Input school name: Beijing Normal University
 Input school address: No.19, Xinjiekouwai St, Haidian District, Beijing
 school constructed.
 myschool:
 name:     Beijing Normal University
 address:     No.19, Xinjiekouwai St, Haidian District, Beijing
 school copy constructed.
 yourschool:
 name:     Beijing Normal University
 address:     No.19, Xinjiekouwai St, Haidian District, Beijing
 school deconstructed. delete space of name and address.
 school deconstructed. delete space of name and address.
*/
#include <iostream>

class School
{
private:
    char* _name;
    char* _addr;
public:
    School(const char* name,const char* addr)
    {
        _name=new char[strlen(name)+1];
        strcpy(_name, name);
        _addr=new char[strlen(addr)+1];
        strcpy(_addr, addr);
        std::cout << "school constructed." << std::endl;
    }
    School(const School& s)
    {
        _name=new char[strlen(s._name)+1];
        strcpy(_name, s._name);
        _addr=new char[strlen(s._addr)+1];
        strcpy(_addr, s._addr);
        std::cout << "school copy constructed." << std::endl;
    }
    ~School()
    {
        delete[] _name;
        delete[] _addr;
        std::cout << "school deconstructed. delete space of name and address." << std::endl;
    }
    void Show() const
    {
        std::cout <<"name:"<<_name<<std::endl<<"address"<< _addr<<std::endl;
    }
};

int main(int argc, const char * argv[]) {
    char name[80],addr[80];
    std::cout << "Input school name:";
    std::cin.getline(name,80);
    std::cout << "Input school address:";
    std::cin.getline(addr,80);
    School myschool(name, addr);
    std::cout << "myschool:" << std::endl;
    myschool.Show();
    
    School yourschool(myschool);
    std::cout << "yourschool:" << std::endl;
    yourschool.Show();
    
    return 0;
}
