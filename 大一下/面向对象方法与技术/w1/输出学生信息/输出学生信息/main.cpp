//
//  main.cpp
//  输出学生信息
//
//  Created by 杨博文 on 2024/2/24.
//

#include <iostream>
using namespace std;
/*设计数据类型：学生Student，包含姓名(string name)、学号(string number)、分数(int score)
      编写程序，分别使用面向过程和面向对象的方法实现：定义学生数据类型，创建1个学生，写入该学生的姓名、学号、分数，输出学生的信息。*/

class Student 
{
private:
    string name;
    string number;
    int score;
public:
    void setName(string x)
    {
        name=x;
    }
    void setNumber(string x)
    {
        number=x;
    }
    void setScore(int x)
    {
        score=x;
    }
    string printName()
    {
        return name;
    }
    string printNumber()
    {
        return number;
    }
    int printScore()
    {
        return score;
    }
};
int main(int argc, const char * argv[]) 
{
    Student std1;
    string x,y;
    int z;
    cin >> x >> y >> z;
    std1.setName(x);
    std1.setNumber(y);
    std1.setScore(z);
    cout << std1.printName() << " " << std1.printNumber() << " " << std1.printScore() << endl;
    return 0;
}
