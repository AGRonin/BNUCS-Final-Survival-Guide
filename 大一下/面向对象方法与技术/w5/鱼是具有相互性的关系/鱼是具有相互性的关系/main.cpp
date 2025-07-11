//
//  main.cpp
//  鱼是具有相互性的关系
//  到底是你在喂鱼，还是鱼在喂你？这是一个问题。
//
//  Created by 杨博文 on 2024/3/22.
//

/*编写程序，实现模拟的养鱼过程。从宠物市场买回N条鱼，开始养鱼：它们在一个鱼缸中。每天只投放一颗鱼食。因此每天只有一条鱼能够吃到食物。吃食后，鱼增长10克。如果一条鱼连续5天吃不到食物，体重就要减少10克。当鱼的体重减少到0克时，鱼就饿死了。当鱼的体重长到300克时，鱼就撑死了。
 基本功能描述：
 （1）    每一条鱼都有以下基本信息：名字、颜色、体重。鱼有以下基本行为：吃食物。除了这些基本信息之外，还要设计补充其它的数据成员和成员函数，以实现要求的功能。
 （2）养5条以上的鱼。
 （3）每条鱼刚买回来时，体重都是标准值100克。
 （4）喂食物时，用随机数方法决定哪条鱼能够吃到食物。（注意使用真正的随机数）
 （5）在程序中，用1秒钟来代替实际的1天。
 （6）每10天，统计一下鱼缸中还活着的鱼的情况。即输出每一条鱼的名字、颜色、体重、上次吃食物的时间。
 （7）当所有的鱼都死了，程序就结束了。结束前给出信息。
 （8）当用户要求程序终止时，也结束程序。
 程序设计要求：
 （1）设计鱼类；
 （2）鱼的总数使用静态数据成员，与总数相关的函数使用静态成员函数；
 （3）用户输入要喂养的鱼的数目；
 界面要求（输入输出样例）：
 您要养几条鱼（N>=5）: 5
 请输入第1条鱼的名字、颜色：Nimo orange
 ……
 请输入第5条鱼的名字、颜色：Melin red
 开始养鱼了！
 第1天：Nimo 吃到了食物
 您要结束养鱼吗？(Y/N) : N
 第2天：Melin 吃到了食物
 您要结束养鱼吗？(Y/N) : N
 ……
 第10天：
 还有5条活着的鱼，它们的情况是：
 名字        颜色        体重        上次吃食时间
 Nimo        Orange        130g            第8天
 Melin         Red            140g            第7天
 ……
 第11天：Tom 吃到了食物
 您要结束养鱼吗？(Y/N) : N
 ……
 第20天：
 还有4条活着的鱼，它们的情况是：
 名字        颜色        体重        上次吃食时间
 Nimo        Orange        170g            第16天
 Melin         Red            150g            第17天
 ……
 …….
 (就这样每天喂鱼，每10天统计一次，一直到结果1或者结果2)
 结果1：
 抱歉，所有的鱼都死了，养鱼失败了，程序结束。
 结果2：
 您要结束养鱼吗？(Y/N) : Y
 程序结束。*/

#include "classFish.hpp"

int main(int argc, const char * argv[]) 
{
    int n;
    std::cout << "您要养几条鱼（N>=5）: ";
    std::cin >> n;
    Fish::setNum(n);
    Fish fish[n];
    for(int i=0;i<n;i++)
    {
        std::string name,color;
        std::cout << "请输入第" << i+1 <<"条鱼的名字、颜色：";
        std::cin >> name >> color;
        fish[i].setFish(name, color);
    }
    std::cout << "开始养鱼了！" << std::endl;
    int date=1;
    time_t now;
    time(&now);
    int eat;
    srand(now);
    while (date)
    {
        eat=rand();
        eat=eat%Fish::getNum();
        int eatorder=-1;
        for(int i=0;i<n;i++)
        {
            if(fish[i].liveOrDead()==1)
            {
                eatorder++;
            }
            if(eatorder==eat)
            {
                eatorder=i;
                break;
            }
        }
        fish[eatorder].eating(date);
        for(int i=0;i<n;i++)
        {
            fish[i].hungry(date);
        }
        std::cout << "第" << date << "天:" << fish[eatorder].getName() << " 吃到了食物\n" ;
        if(Fish::getNum())
        {
            if(date%10==0)
            {
                std::cout <<
                std::setw(13) << std::setiosflags(std::ios::left) << "名字" <<
                std::setw(13) << std::setiosflags(std::ios::left) << "颜色" <<
                std::setw(12) << std::setiosflags(std::ios::left) << "体重" <<
                std::setw(20) << std::setiosflags(std::ios::left) << "上次吃食时间" << std::endl;
                for(int i=0;i<n;i++)
                {
                    fish[i].showAll();
                }
            }
            std::cout << "您要结束养鱼吗？(Y/N) : ";
            char YesOrNo='n';
            //std::cin >> YesOrNo;
            if(YesOrNo=='Y')
            {
                std::cout << "程序结束";
                break;
            }
        }
        else
        {
            break;
        }
        date++;
    }
    return 0;
}

