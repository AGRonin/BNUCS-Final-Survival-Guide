//
//  main.cpp
//  学生、员工与助工
//
//  Created by 杨博文 on 2024/4/11.
//

/*一个学校的人员管理系统中，有学生、员工、助工三种类型的人，助工由勤工俭学的学生来兼任，兼有学生和员工两类人的特征，设计合适的类模拟此人员管理系统。
 Student类、Employee类、stuEmployee类；
 把这几类人员的共同特征和行为抽象形成基类Person类。
 在设计各个类时，请结合主程序的输入输出，增加构造函数、Set函数、输出函数等。
 1.2主程序main() 中：
 根据用户的选择来测试Person、Student、Employee、StuEmployee对象。
*/
#include "classStuEmployee.hpp"

int main(int argc, const char * argv[]) {
    while(true)
    {
        char type;
        std::cout << "Test p--Person s--Student e--Employee v--StudentEmployee o--Test Over:";
        std::cin >> type;
        if(type=='p'||type=='P')
        {
            Person p;
            std::cout << "Input person name: ";
            std::string name;
            std::cin >> name;
            p.setName(name);
            std::cout << "Input person age:";
            int age;
            std::cin >> age;
            p.setAge(age);
            std::cout << p.getName() << " " << p.getAge() << std::endl;
        }
        else if(type=='s'||type=='S')
        {
            Student p;
            std::cout << "Input student name: ";
            std::string name;
            std::cin >> name;
            p.setName(name);
            std::cout << "Input student age:";
            int age;
            std::cin >> age;
            p.setAge(age);
            std::cout << "Input student major: ";
            std::string major;
            std::cin >> major;
            p.setMajor(major);
            std::cout << "Input student id:";
            int id;
            std::cin >> id;
            p.setStudentID(id);
            std::cout << p.getName() << " " << p.getAge() << " " << p.getMajor() << " " << p.getStudentID() << std::endl;
        }
        else if(type=='e'||type=='E')
        {
            Employee p;
            std::cout << "Input employee name: ";
            std::string name;
            std::cin >> name;
            p.setName(name);
            std::cout << "Input employee age:";
            int age;
            std::cin >> age;
            p.setAge(age);
            std::cout << "Input employee department: ";
            std::string depart;
            std::cin >> depart;
            p.setDepartment(depart);
            std::cout << "Input employee id:";
            int id;
            std::cin >> id;
            p.setEmployeeID(id);
            std::cout << p.getName() << " " << p.getAge() << " " << p.getDepartment() << " " << p.getEmployeeID() << std::endl;
        }
        else if(type=='v'||type=='V')
        {
            StuEmployee p;
            std::cout << "Input stuEmployee name: ";
            std::string name;
            std::cin >> name;
            p.setName(name);
            std::cout << "Input stuEmployee age:";
            int age;
            std::cin >> age;
            p.setAge(age);
            std::cout << "Input stuEmployee major: ";
            std::string major;
            std::cin >> major;
            p.setMajor(major);
            std::cout << "Input stuEmployee student id:";
            int stuid;
            std::cin >> stuid;
            p.setStudentID(stuid);
            std::cout << "Input stuEmployee department: ";
            std::string depart;
            std::cin >> depart;
            p.setDepartment(depart);
            std::cout << "Input stuEmployee employee id:";
            int empid;
            std::cin >> empid;
            p.setEmployeeID(empid);
            std::cout << p.getName() << " " << p.getAge() << " " << p.getMajor() << " " << p.getStudentID() << " " << p.getDepartment() << " " << p.getEmployeeID() << std::endl;
        }
        else if(type=='o'||type=='O')
        {
            break;
        }
    }
    std::cout << "Byebye~\n";
    return 0;
}
