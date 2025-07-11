//
//  main.cpp
//  约瑟夫环
//
//  Created by 杨博文 on 2024/7/1.
//

#include <iostream>
using namespace std;

void Josephus(int a)
{
    int AllPeople[a];
    for(int i=0;i<a;i++)
    {
        AllPeople[i]=i+1;
    }
    int Index=-1;
    int death=0;
    int len=a;
    while(true)
    {
        Index=(Index+1)%a;
        if(AllPeople[Index]==0)
        {
            continue;
        }
        death++;
        if(death==3)
        {
            cout<<AllPeople[Index]<<' ';
            len--;
            AllPeople[Index]=0;
            death=0;
        }
        if(len==0)
        {
            break;
        }
    }
    cout<<endl;
    return;
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
        Josephus(A[i]);
    }
}
