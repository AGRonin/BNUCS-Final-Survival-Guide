//
//  main.c
//  平均成绩
//
//  Created by 杨博文 on 2023/12/1.
//

#include <stdio.h>
/*定义一个学生结构体Student，数据成员包括学号，姓名，性别，数学成绩，语文成绩，英语成绩，平均成绩。输入学生的学号，姓名，性别，数学成绩，语文成绩，英语成绩，编写函数计算该学生的平均成绩并放在结构体对象的平均成绩中。主函数输出该学生所有信息。
 函数定义为：void averageScore ( struct Student &stu);
 注：要求用结构体引用做函数参数。*/
struct Student
{
    int xuehao;
    char name[20];
    char gender[10];
    int math;
    int chinese;
    int english;
    int average;
};
void averageScore (struct Student *p)
{
    p->average=(p->chinese+p->english+p->math)/3;
}
int main(int argc, const char * argv[]) {
    struct Student stu;
    struct Student *p;
    p=&stu;
    scanf("%d%s%s%d%d%d",&stu.xuehao,stu.name,stu.gender,&stu.math,&stu.chinese,&stu.english);
    averageScore(p);
    printf("%d %s %s %d %d %d %d",stu.xuehao,stu.name,stu.gender,stu.math,stu.chinese,stu.english,stu.average);
    return 0;
}
