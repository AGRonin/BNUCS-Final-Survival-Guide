//
//  main.cpp
//  约瑟夫问题
//
//  Created by 杨博文 on 2024/5/22.
//

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <sys/time.h>

template <typename IT>
int Joesphus(IT people,int m,int n)
{
    typename IT::iterator sword=people.begin();
    while(people.size()>1)
    {
        for(int i=0;i<m-1;i++)
        {
            ++sword;
            if(sword==people.end())
            {
                sword=people.begin();
            }
        }
        sword=people.erase(sword);//因为在这里擦掉了一个数，所以应当是迭代器跳m-1下而不是m下。这里需要重新赋值sword因为删除后迭代器失效
        if(sword==people.end())
        {
            sword=people.begin();
        }
    }
    return *sword;
}

int main(int argc, const char * argv[])
{
    std::vector<int> peopleVector;
    std::list<int> peopleList;
    struct timeval start_time,end_time;
    int n,m;
    std::cout << "请输入总人数n和间隔人数m:";
    std::cin >>n >> m;
    gettimeofday(&start_time, NULL);//获取现在的时间，由于mac系统中clock函数好像有点什么奇怪的问题，故使用此函数（据CSDN）
    for(int i=1;i<=n;i++)
    {
        peopleVector.push_back(i);
    }
    std::cout << "现在，是vector的测试：\n测试结果是：" << Joesphus(peopleVector, m, n) << "号存活，用时：";
    gettimeofday(&end_time, NULL);
    std::cout << (end_time.tv_sec-start_time.tv_sec)*1000+(end_time.tv_usec-start_time.tv_usec)/1000<<"ms\n";
    
    gettimeofday(&start_time, NULL);//获取现在的时间
    for(int i=1;i<=n;i++)
    {
        peopleList.push_back(i);
    }
    std::cout << "现在，是list的测试：\n测试结果是：" << Joesphus(peopleList, m, n) << "号存活，用时：";
    gettimeofday(&end_time, NULL);
    std::cout << (end_time.tv_sec-start_time.tv_sec)*1000+(end_time.tv_usec-start_time.tv_usec)/1000 <<"ms\n";
    
}
