//
//  main.cpp
//  买酱油
//
//  Created by 杨博文 on 2024/7/1.
//
/*小明带着 N 元钱去买酱油。
 酱油 10 块钱一瓶，商家进行促销，每买 3 瓶送 1 瓶，或者每买 5 瓶送 2 瓶。
 请问小明最多可以得到多少瓶酱油。*/

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    n=n/10;
    cout<<int(n/5)*7+int((n-int(n/5)*5)/3)*4+(n-int(n/5)*5)%3;
    return 0;
}
