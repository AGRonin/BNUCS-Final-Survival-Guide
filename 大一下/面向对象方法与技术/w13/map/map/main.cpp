//
//  main.cpp
//  map
//
//  Created by 杨博文 on 2024/5/22.
//

#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    /* 初始化名单 name */
    string name[]={"张大年","刘明海","李煜"};
    double salary[]={1200,2000,1450};
    map<string, double>  sa;
    for(int i=0;i<3;i++)
        sa.insert(make_pair(name[i],salary[i]));
    sa["tom"]=3400;
    sa["bob"]=2000;

    /* 输入名字并在 name 检索 */
    map<string,double>::iterator p;   // 通过迭代器访问map元素
    for(p=sa.begin();p!=sa.end();p++)
        cout<<p->first<<"\t"<<p->second<<endl;
    string person;
    cout<<"输入查找人员的姓名：";
    cin>>person;
    for(p=sa.begin();p!=sa.end();p++)
        if(p->first==person)
            cout<<p->second<<endl;
    return 0;
}
