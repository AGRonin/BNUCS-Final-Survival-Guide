//
//  main.cpp
//  形状
//
//  Created by 杨博文 on 2024/4/20.
//

/*
 设计几何形状类族：形状、点、圆、矩形、三角形。
 关于构造矩形的说明：矩形由对角顶点构造，矩形的两条邻边和坐标轴分别平行。
 从文件shape.xlsx输入数据，建立形状指针数组。每一个形状指针指向具体的子类对象。
 正确地建立这个数组和每个对象。输出所有形状的信息。最后输出所有图形的总面积和总周长。
 */
#include <fstream>
#include "classCircle.hpp"
#include "classRectangle.hpp"
#include "classTriangle.hpp"

int main(int argc, const char * argv[]) 
{
    //将文件从csv转化成txt，输出
    std::ifstream infile("/Users/yangbowen/Desktop/本科/大一/大一下课程/面向对象方法与技术/2024.4.17面向对象方法与技术/形状/shape.csv");
    std::ofstream outfile("/Users/yangbowen/Desktop/本科/大一/大一下课程/面向对象方法与技术/2024.4.17面向对象方法与技术/形状/shape.txt");
    char temp[50] = { 0 };
    char outtemp[50] = { 0 };
    do
    {   for (int i = 0; i < 50; i++)
        {   temp[i] = 0;
            outtemp[i] = 0;
        }
        infile.getline(temp, 49);
        for (int i = 0; i < strlen(temp); i++)
            if (temp[i] != ',')
                outtemp[i] = temp[i];
            else
                outtemp[i] = ' ';
        outfile << outtemp<<std::endl;
    } while (!infile.eof());
    infile.close();
    outfile.close();
    //进行文件读取
    std::ifstream againInfile("/Users/yangbowen/Desktop/本科/大一/大一下课程/面向对象方法与技术/2024.4.17面向对象方法与技术/形状/shape.txt");
    //创建形状数组指针并输入内容
    int x;//总组数
    againInfile >> x;
    Shape** arrayShape;
    arrayShape=new Shape*[x];
    for(int i=0;i<x;i++)
    {
        int j;
        againInfile >> j;
        std::string type;
        againInfile >> type;
        j=j-1;
        if(type=="circle")
        {
            double a1,a2,a3;
            againInfile >> a1 >> a2 >> a3;
            arrayShape[j]=new Circle(a1,a2,a3);
        }
        else if(type=="rectangle")
        {
            double a1,a2,a3,a4;
            againInfile >> a1 >> a2 >> a3 >> a4;
            arrayShape[j]=new Rectangle(a1,a2,a3,a4);
        }
        else if(type=="triangle")
        {
            double a1,a2,a3,a4,a5,a6;
            againInfile >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
            arrayShape[j]=new Triangle(a1,a2,a3,a4,a5,a6);
        }
        else if(type=="point")
        {
            double a1,a2;
            againInfile >> a1 >> a2;
            arrayShape[j]=new Point(a1,a2);
        }
    }
    //进行输出
    double sumArea=0,sumPerimeter=0;
    for(int i=0;i<x;i++)
    {
        arrayShape[i]->GetInfo();
        sumArea+=arrayShape[i]->Area();
        sumPerimeter+=arrayShape[i]->Perimeter();
        std::cout << std::endl;
    }
    std::cout << "总面积是 " << sumArea << "\n总周长是 " << sumPerimeter << std::endl;
    //删除数组
    if(arrayShape)
    {
        delete[] arrayShape;
    }
    return 0;
}
