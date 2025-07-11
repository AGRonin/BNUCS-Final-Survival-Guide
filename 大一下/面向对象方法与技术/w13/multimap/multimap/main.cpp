//
//  main.cpp
//  multimap
//
//  Created by 杨博文 on 2024/5/29.
//

#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    multimap<string, string> dict;    //dict是用于存放字典的multimap
    multimap<string, string>::iterator p;
    string eng[] = { "polt","gorge","cliff","berg","precipice","tract" };
    string che[] = { "小块地，地点","峡谷","悬崖","冰山","悬崖","一片，区域" };
    for (int i = 0; i < 6; i++)
    {
        dict.insert(make_pair(eng[i], che[i]));
    }
    dict.insert(make_pair(string("tract"), string("地带")));
    dict.insert(make_pair(string("precipice"), string("危险的处境")));
    dict.insert(make_pair("day","一天"));
    //dict["precipice"]="悬崖，峭壁";                //错误
    for (p = dict.begin(); p != dict.end(); p++)
    {
        cout << p->first << "\t" << p->second << endl;
    }
    string word;
    cout << "请输入要查找的英文单词：";
    cin >> word;
    for (p = dict.begin(); p != dict.end(); p++)
    {
        if (p->first == word)
        {
            cout << p->second << endl;
        }
    }
    cout << "请输入要查找的中文单词：";
    cin >> word;
    for (p = dict.begin();p != dict.end(); p++)
    {
        if (p->second == word)
        {
            cout << p->first << endl;
        }
    }
    return 0;
}
