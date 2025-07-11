//
//  main.cpp
//  新的集合
//
//  Created by 杨博文 on 2024/4/27.
//

#include "classMySet.hpp"

int main(int argc, const char * argv[]) 
{
    MySet m1,m2,m3;
    std::cin>>m1>>m2;
    m3=m1+m2;
    std::cout<<m1<<'+'<<m2<<'='<<m3<<std::endl;
    m3=m1-m2;
    std::cout<<m1<<'-'<<m2<<'='<<m3<<std::endl;
    std::cout<<"m1="<<m1<<std::endl;
    m2=++m1;
    std::cout<<"m2=++m1;   m2="<<m2<<",  m1="<<m1<<std::endl;
    m2=m1++;
    std::cout<<"m2=m1++;   m2="<<m2<<",  m1="<<m1<<std::endl;
    m2=--m1;
    std::cout<<"m2=--m1;   m2="<<m2<<",  m1="<<m1<<std::endl;
    m2=m1--;
    std::cout<<"m2=m1--;   m2="<<m2<<",  m1="<<m1<<std::endl;
    std::cout << "press any key to continue";
    return 0;
}
