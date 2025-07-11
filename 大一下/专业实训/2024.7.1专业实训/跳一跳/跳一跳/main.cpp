//
//  main.cpp
//  跳一跳
//
//  Created by 杨博文 on 2024/7/1.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int score=0;
    int last=1,now=0;
    while(true)
    {
        cin>>now;
        if(now==0)
        {
            cout<<score;
            break;
        }
        if(now==1)
        {
            score+=1;
            last=1;
        }
        else if(last==1)
        {
            score+=2;
            last=2;
        }
        else
        {
            score=score+last+2;
            last+=2;
        }
    }
    return 0;
}
