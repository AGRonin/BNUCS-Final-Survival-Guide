//
//  main.cpp
//  找出分数最高的小朋友
//
//  Created by 杨博文 on 2024/3/7.
//

/*1.1设计学生类Student，包含：
 成员数据（私有）：
     姓名_name ，数据类型 string ，默认值“XXX”
     学号_number，数据类型 string，默认值“200010000001”
     性别_gender，数据类型 char，默认值‘m’('m'代表男，‘f’表示女)
     分数_score，数据类型 double，默认值 0
 成员函数（公有）：
 （1）构造函数
     Student(string name="xxx",string num="200010000001",char gen='m',double score=0);在实现这个构造函数的时候，请使用初始化列表；
 （2）读取分数的接口(公有)
     double GetScore() const;        (建议使用const)
 （3）输出学生信息接口（公有）：
     void Show() const;                 (建议使用const)
     如果需要其他成员函数，请自行增加。

 1.2类外函数：
 找出分数最高的学生的函数：
 Student MaxScore(Student* s);

 1.3在主函数main()中:
 （1） 定义包含10个学生的学生数组stu1[10]：
 Student stu1[10];
 输出stu1中每一个学生的信息；
 （2） 定义包含10个学生的学生数组stu2[10]：
 Student stu2[10]={Student("张三","202010000005",'m',90),
 Student("李四","201810200012",'m',85),
 Student("王五","202010020108",'m',76),
 Student("刘丽丽","201910060022",'f',92),
 Student("赵勇平","202010000115",'m',88),
 Student("张春生","200610000059",'m',82),
 Student("周勇刚","201110040001",'m',77),
 Student("王阳","201810080072",'f',89),
 Student("刘燕","202010000023",'f',90),
 Student("何平平","202010000007",'f',93)
 };
 输出stu2中每一个学生的信息；
 （3） 调用MaxScore函数，找到分数最高的学生，输出这名学生的信息。

 1.4程序的输出（供参考）：
 stu1的10名同学的信息：
 （步骤1的输出省略）
 stu2的10名同学的信息：
 name: 张三
 number: 202010000005
 gender: 男
 score:  90
 name: 李四
 number: 201810200012
 gender: 男
 score:  85
 ......
 name: 何平平
 number: 202010000007
 gender: 女
 score:  93
 分数最高的同学信息：
 name: 何平平
 number: 202010000007
 gender: 女
 score:  93
*/

#include <iostream>
using namespace std;
class Student
{
private:
    string _name;
    string _number;
    char _gender;
    double _score;
public:
    Student(string name="xxx",string num="200010000001",char gen='m',double score=0):_name(name),_number(num),_gender(gen),_score(score){}
    double GetScore() const
    {
        return _score;
    }
    void Show() const
    {
        string gender = _gender=='m'?"男":"女";
        cout << "name:" << _name << endl << "number:" << _number << endl << "gender:" << gender << endl << "score:" << _score << endl ;
    }
};

Student MaxScore(Student* s)
{
    double maxscore=0;
    Student* maxStudent(s);
    for(int i=0;i<10;i++,s++)
    {
        if(maxscore < s->GetScore())
        {
            maxscore = s->GetScore();
            maxStudent=s;
        }
    }
    return *maxStudent;
}


int main(int argc, const char * argv[]) {
    Student stu1[10];
    Student stu2[10]={Student("张三","202010000005",'m',90),
        Student("李四","201810200012",'m',85),
        Student("王五","202010020108",'m',76),
        Student("刘丽丽","201910060022",'f',92),
        Student("赵勇平","202010000115",'m',88),
        Student("张春生","200610000059",'m',82),
        Student("周勇刚","201110040001",'m',77),
        Student("王阳","201810080072",'f',89),
        Student("刘燕","202010000023",'f',90),
        Student("何平平","202010000007",'f',93)};
    Student stu3=MaxScore(stu2);
    cout << "stu1的10名同学的信息：" << endl ;
    for(int i=0;i<10;i++)
    {
        stu1[i].Show();
    }
    cout << "stu2的10名同学的信息：" << endl ;
    for(int i=0;i<10;i++)
    {
        stu2[i].Show();
    }
    cout << "分数最高的同学信息：" << endl ;
    stu3.Show();
    
    return 0;
}
