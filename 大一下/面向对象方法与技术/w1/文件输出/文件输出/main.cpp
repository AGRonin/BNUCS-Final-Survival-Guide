//
//  main.cpp
//  文件输出
//
//  Created by 杨博文 on 2024/2/21.
//

#include <fstream>
using namespace std;
int main(void)
{
    ofstream SaveFile("/Users/yangbowen/Desktop/本科/大一/大一下课程/面向对象方法与技术/2024.2.21面向对象方法与技术/文件输出/文件输出/cppsavefile.txt");
    SaveFile << "Hello World, from bnu!";
    SaveFile.close();
    return 0;
}
