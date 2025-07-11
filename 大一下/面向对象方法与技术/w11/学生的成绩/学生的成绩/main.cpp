//
//  main.cpp
//  学生的成绩
//
//  Created by 杨博文 on 2024/5/10.
//

/*包含私有成员数据：姓名、学号、语文成绩、数学成绩、英语成绩。
 成员函数：
 重载比较运算符函数（根据需要，重载 > 或者 >= 或者 < 或者 <= 等）
 重载输入>>函数、重载输出<<函数，
 其他函数自行增加。
 主程序功能：
 建立学生数组，输入10个学生信息。学生信息存放在文本文件in.txt中。
 对学生排序：按照总分降序排序，当总分相同时，按照语文、数学、英语的成绩排序。
 输出排序后的学生信息。*/
#include "classStudent.hpp"

int main(int argc, const char * argv[]) {
    std::ifstream in("/Users/yangbowen/Desktop/本科/大一/大一下课程/面向对象方法与技术/2024.5.8面向对象方法与技术/学生的成绩/in.txt");
    student stu[10];
    for(int i=0;i<10;i++)
    {
        in >> stu[i];
    }
    //下面开始排序，冒泡，由于使用std::string，不涉及浅拷贝问题，不重载=号
    student temp;
    for(int i=9;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(stu[j]<stu[j+1])
            {
                temp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp;
            }
        }
    }
    
    for(int i=0;i<10;i++)
    {
        std::cout << stu[i];
    }
    
    return 0;
}
