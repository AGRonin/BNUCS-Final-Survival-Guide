//
//  main.cpp
//  set
//
//  Created by 杨博文 on 2024/5/22.
//

#include<iostream>
#include<set>
using namespace std;

int  main()
{    /*初始化名单set */
     string a[]={"杜明","王为","张清山","李海","黄明浩",
               "刘一","张三","林浦海","王小二","张清山"};
multiset<string> nameset(a,a+10);
nameset.insert("杜明");
nameset.insert("李则");
multiset<string>::iterator it;
for(it=nameset.begin();it!=nameset.end();it++)
    cout<<*it<<"  ";
cout<<endl;

/*输入名字并在名单set中查找*/
string sname;
cout<<"输入要查找的姓名：";
cin>>sname;

it=nameset.begin();
bool s=false;
while(it!=nameset.end())
{    if(sname==*it)
     {    cout<<*it<<endl;
s=true;
}
it++;
}
if(!s)
    cout<<sname<<"不在集合中！"<<endl;
     return 0;
}

