//
//  main.cpp
//  self number
//
//  Created by 杨博文 on 2024/7/1.
//

#include <iostream>
int sumNum(int a)
{
    if(a<10)
    {
        return a;
    }
    return a%10+sumNum(a/10);
}

int main(int argc, const char * argv[]) {
    int A[10000];
    for(int i=0;i<10000;i++)
    {
        A[i]=1;
    }
    for(int i=0;i<10000;i++)
    {
        if(i+sumNum(i)<=10000)
        {
            A[i+sumNum(i)-1]=0;
        }
    }
    for(int i=0;i<10000;i++)
    {
        if(A[i]!=0)
        {
            std::cout<<i+1<<' ';
        }
    }
}
