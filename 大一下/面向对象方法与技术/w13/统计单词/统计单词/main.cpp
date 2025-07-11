//
//  main.cpp
//  统计单词
//
//  Created by 杨博文 on 2024/5/22.
//

#include <iostream>
#include <set>
#include <map>
#include <iterator>

int main(int argc, const char * argv[]) 
{
    std::multiset<std::string> wordMultiSet;
    std::map<std::string,int> wordMap;
    std::string temp;
    while(true)
    {
        std::cin >> temp;
        wordMultiSet.insert(temp);
        int num=0;
        for(std::multiset<std::string>::iterator i=wordMultiSet.begin();i!=wordMultiSet.end();++i)
        {
            if(*i==temp)
            {
                num++;
            }
        }
        std::cout << "经wordMultiSet统计，单词：" << temp << "总共出现过" << num << "次\n";
        bool ifTempIN=false;
        for(std::map<std::string,int>::iterator i=wordMap.begin();i!=wordMap.end();++i)
        {
            if(i->first==temp)
            {
                ifTempIN=true;
                i->second++;
                std::cout << "经wordMap统计，单词：" << temp << "总共出现过" << i->second << "次\n";
            }
        }
        if(!ifTempIN)
        {
            wordMap[temp]=1;
            std::cout << "经wordMap统计，单词：" << temp << "总共出现过1次\n";
        }
        if(temp=="QUIT")
        {
            break;
        }
    }
    return 0;
}
