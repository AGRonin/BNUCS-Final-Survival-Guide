//
//  main.cpp
//  string
//
//  Created by 杨博文 on 2024/5/29.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1 = "中华人民共和国成立了";
    string s2 = "中国人民从此站起来了！";
    string s3, s4, s5;
    s3 = s1 + "，" + s2;
    int n = s1.find_first_of("人民");
    if (n != string::npos)
    {
        cout << "人民在s1中的位置：" << n << endl;
    }
    else
    {
        cout << "在s1中没有该子串！";
    }
    s4 = s1.substr(4, 10);
    cout << "s1= " << s1 << endl;
    cout << "s2= " << s2 << endl;
    cout << "s3= " << s3 << endl;
    cout << "s4= " << s4 << endl;
    if (s1 > s2)
    {
        cout << "s1>s2= true " << endl;
    }
    else
    {
        cout << "s1>s2= false" << endl;
    }
    s3.replace(s3.find("从此"), 4, "从1949年");
    cout << "s3 after replace= " << s3 << endl;
    s3.insert(s3.find("站"), "10月");
    cout << "s3 after insert=  " << s3 << endl;
    return 0;
}

