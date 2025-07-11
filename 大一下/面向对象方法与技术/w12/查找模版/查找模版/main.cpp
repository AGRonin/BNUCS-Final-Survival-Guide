//
//  main.cpp
//  查找模版
//
//  Created by 杨博文 on 2024/5/16.
//

/*设计函数模板
 template <class T>
 int search( T* array, const int size, T item);
 在整形数组、字符数组、字符串数组、person数组中查找指定的数据，返回找到的第一个该数据下标；如果找不到则返回-1.

 int a[10] = {1,3,5,7,9,2,4,6,8,10};    分别查找0 , 4
 char b[] = “Beijing Normal University”；  分别查找 字符‘m’ ‘i’  ‘z’
 string c[] = {“BNU”,”welcome”,”Beijing”,”abc”,”1234”};  分别查找”ok”  “abc”
 Person d[] ={Person( “wangwei”,20),Person(“liuli”,30),Person(“zhangsan”,40),Person(“zhaoming”,20};  分别查找Person（”liuli”,30）,  Person（”liuli”,20）

     程序输出找到的第一个数据的下标，或者输出没有找到。*/

#include "classPerson.hpp"

template <class T>
int search(T* array, const int size, T item)
{
    for(int i=0;i<size;i++)
    {
        if(array[i]==item)
        {
            return i;
        }
    }
    return -1;
}

template <class T>
void print(T* array,const int size,T item)
{
    int x=search(array,size,item);
    if(x!=-1)
    {
        std::cout << item << " at position " << x << std::endl;
        return;
    }
    std::cout << item <<" is not found\n";
}

int main(int argc, const char * argv[]) {
    int a[10] = {1,3,5,7,9,2,4,6,8,10};
    char b[] = "Beijing Normal University";
    std::string c[] = {"BNU","welcome","Beijing","abc","1234"};
    Person d[] ={Person("wangwei",20),Person("liuli",30),Person("zhangsan",40),Person("zhaoming",20)};
    print(a,10,0);
    print(a,10,4);
    print(b,26,'m');
    print(b,26,'i');
    print(b,26,'z');
    print<std::string>(c,5,"ok");
    print<std::string>(c,5,"abc");
    print(d,4,Person("liuli",30));
    print(d,4,Person("liuli",20));
    return 0;
}
