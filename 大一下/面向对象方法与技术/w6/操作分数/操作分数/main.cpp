//
//  main.cpp
//  操作分数
//
//  Created by 杨博文 on 2024/3/29.
//

/*2.1 基本要求：
 教师作为学生的友元类，操作学生的学分和总成绩。
2.2 功能设计：
 （1）设计学生类，包含学生姓名、学分和总成绩；
 （2）设计教师类，包含教师姓名，教师有权限修改每个学生的学分和总成绩；
 （3）在以上类中增加合适的成员函数以完成程序的功能；
 （4）教师类设计成学生类的友元；
2.4.1 主程序要求：
（1）至少有5名学生，3名教师；
（2）用户随意选择一位教师、一名学生，让该教师给该学生增加学分、增加总成绩；
（3）程序结束前输出每位学生的姓名、学分、总成绩
*/
#include "classTeacher.hpp"

int main(int argc, const char * argv[])
{
    std::cout << "您需要建立几位学生(M)和几位教师(N)：";
    int m,n;
    std::cin >> m >> n;
    Student stu[m];
    Teacher tea[n];
    std::cout << "请输入" << m << "位学生的姓名：";
    for(int i=0;i<m;i++)
    {
        std::string name;
        std::cin >> name;
        stu[i].setName(name);
    }
    std::cout << "请输入" << n << "位教师的姓名：";
    for(int i=0;i<n;i++)
    {
        std::string name;
        std::cin >> name;
        tea[i].setName(name);
    }
    char ifContinue='y';
    while(ifContinue=='y')
    {
        std::string teaname,stuname;
        int judge,i,j;
        while(1)
        {
            judge=0;
            std::cout << "请选择一位教师: ";
            std::cin >> teaname;
            for(i=0;i<n;i++)
            {
                judge=tea[i].ifName(teaname);
                if(judge==1)
                    break;
            }
            if(judge==1)
                break;
            std::cout << "没有找到教师！";
        }
        while(1)
        {
            judge=0;
            std::cout << "请选择一位学生: ";
            std::cin >> stuname;
            for(j=0;j<m;j++)
            {
                judge=stu[j].ifName(stuname);
                if(judge==1)
                    break;
            }
            if(judge==1)
                break;
            std::cout << "没有找到学生！";
        }
        tea[i].addAll(stu[j]);
        std::cout << "还要继续吗？(Y/N): ";
        std::cin >> ifContinue;
    }
    std::cout << "学生信息：\n" <<
    std::setw(13) << std::setiosflags(std::ios::left) << "姓名" <<
    std::setw(14) << std::setiosflags(std::ios::left) << "总学分" <<
    std::setw(10) << std::setiosflags(std::ios::left) << "总成绩" << std::endl;
    for(int i=0;i<m;i++)
    {
        stu[i].ShowAll();
    }
    return 0;
}
