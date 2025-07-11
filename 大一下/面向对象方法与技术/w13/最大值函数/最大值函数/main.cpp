//
//  main.cpp
//  最大值函数
//
//  Created by 杨博文 on 2024/5/29.
//

#include <iostream>
using namespace std;
template <class T>
T Max(T* pt, int size)
{
    T max=pt[0];
    for(int i=0;i<size;i++)
    {
        if(pt[i]>max)
        {
            max=pt[i];
        }
    }
    return max;
}
int main(int argc, const char * argv[]) {
    int A[10]={1,2,3,98,4,5,6,7,8,9};
    double B[5]={1.2,-3.2,8.9,0,2};
    string C[6]={"abc","ok","cplus","java","school","123"};
    cout << Max(A,10)<<" "<<Max(B,5)<<" "<<Max(C,6)<<endl;
    return 0;
}
