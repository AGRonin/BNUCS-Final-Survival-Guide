//
//  main.cpp
//  栈类模版
//
//  Created by 杨博文 on 2024/5/16.
//

/*
 栈是一种这样的数据结构：它像一个圆柱形的罐子，有底并且有一个开口。所以存放数据时，先放入的数据在下层，后放进的数据在上层；取出数据时，要按照顺序从上层开始取出。所以栈的操作特点是先进后出，后进先出。比如：把1、2、3放入栈，那么它们要按照3、2、1的顺序出栈；又比如：1、2、3保存在栈中，那么想取出2，操作步骤是：取出3、取出2、再放回3。在栈的操作中，“压栈”就是放入数据，“出栈”或“弹出”就是取出数据。
 Step1:设计一个通用的栈类，包含以下操作：
 构造函数、析构函数、拷贝构造函数、判断是否为空、压栈操作、弹出操作、返回当前有几个元素、任意扩充栈大小的操作(resize)、重载赋值运算符
 根据需要，设计其他操作
 Step2:测试这个栈类模板
 int 型栈  Double 栈  Char 栈  String 栈  Student 栈
*/

#include "classStudent.hpp"

template <class T>
class myStack
{
private:
    T* _array;
    int _size;
    int _nowSize;
public:
    myStack();
    ~myStack();
    bool ifEmpty();
    void inStack(T item);
    T outStack();
    int howMuch();
    void resize(int size);
    myStack& operator=(const myStack<T>& s);
    myStack(const myStack<T>& s);
};

template <class T>
myStack<T>::myStack()
{
    _array=new T[10];
    if(_array==NULL)
    {
        exit(-1);
    }
    _size=10;//初始开辟10个空间
    _nowSize=0;//现有数量
}

template <class T>
myStack<T>::~myStack()
{
    delete[] _array;
    _array=NULL;
}

template <class T>
bool myStack<T>::ifEmpty()
{
    return _nowSize==0;
}

template <class T>
void myStack<T>::inStack(T item)
{
    if(_nowSize==_size)
    {
        resize(_size+10);//如果满了的话，加十个
    }
    _array[_nowSize]=item;
    _nowSize++;
}

template <class T>
T myStack<T>::outStack()
{
    if(ifEmpty())
    {
        exit(-2);
    }
    _nowSize--;
    return _array[_nowSize];
}

template <class T>
int myStack<T>::howMuch()
{
    return _nowSize;
}

template <class T>
void myStack<T>::resize(int size)
{
    if(size<0)
    {
        exit(-3);
    }
    int newsize=(size<_size)?size:_size;
    _nowSize=(size<_nowSize)?size:_nowSize;
    T* newarray=new T[newsize];
    if(newarray==NULL)
    {
        exit(-4);
    }
    T* pa=_array;
    T* pb=newarray;
    for(int i=0;i<_nowSize;i++,pa++,pb++)
    {
        *pb=*pa;
    }
    delete[] _array;
    _array=newarray;
}

template <class T>
myStack<T>& myStack<T>::operator=(const myStack<T>& s)
{
    if(this==&s)
    {
        return *this;
    }
    _nowSize=s._nowSize;
    _size=s._size;
    delete[] _array;
    _array =new T[_size];
    T* pa=s._array;
    T* pb=_array;
    for(int i=0;i<_size;i++,pa++,pb++)
    {
        *pb=*pa;
    }
    return *this;
}

template <class T>
myStack<T>::myStack(const myStack<T>& s)
{
    _nowSize=s._nowSize;
    _size=s._size;
    _array =new T[_size];
    T* pa=s._array;
    T* pb=_array;
    for(int i=0;i<_size;i++,pa++,pb++)
    {
        *pb=*pa;
    }
}

int main(int argc, const char * argv[]) {
    // 测试int栈
    myStack<int> intStack;
    intStack.inStack(1);
    intStack.inStack(2);
    intStack.inStack(3);
    intStack.inStack(4);
    intStack.inStack(5);
    intStack.inStack(6);
    intStack.inStack(7);
    intStack.inStack(8);
    intStack.inStack(9);
    intStack.inStack(10);
    intStack.inStack(11);//测试增加部分超过原有大小
    intStack.inStack(12);
    intStack.inStack(13);
    intStack.inStack(14);
    intStack.inStack(15);
    intStack.inStack(16);
    intStack.inStack(17);
    intStack.inStack(18);
    intStack.inStack(19);
    intStack.inStack(20);
    std::cout << "Int Stack Size: " << intStack.howMuch() << std::endl;
    std::cout << "Int Stack Top: " << intStack.outStack() << std::endl;
    std::cout << "Int Stack Top: " << intStack.outStack() << std::endl;
    std::cout << "Int Stack Top: " << intStack.outStack() << std::endl;
    std::cout << "Int Stack Top: " << intStack.outStack() << std::endl;
    std::cout << "Int Stack Top: " << intStack.outStack() << std::endl;
    std::cout << "Int Stack Top: " << intStack.outStack() << std::endl;
    std::cout << "Int Stack Size after pop: " << intStack.howMuch() << std::endl;
    intStack.resize(10);//测试强行减少大小
    std::cout << "Resized Int Stack Top: " << intStack.outStack() << std::endl;
    std::cout << "Resized Int Stack Top: " << intStack.outStack() << std::endl;
    std::cout << "Resized Int Stack Top: " << intStack.outStack() << std::endl;
    std::cout << "Resized Int Stack Top: " << intStack.outStack() << std::endl;
  
    // 测试double栈
    myStack<double> doubleStack;
    doubleStack.inStack(1.1);
    doubleStack.inStack(2.2);
    std::cout << "Double Stack Size: " << doubleStack.howMuch() << std::endl;
    std::cout << "Double Stack Top: " << doubleStack.outStack() << std::endl;
    std::cout << "Double Stack Size after pop: " << doubleStack.howMuch() << std::endl;
  
    // 测试char栈
    myStack<char> charStack;
    charStack.inStack('a');
    charStack.inStack('b');
    charStack.inStack('c');
    std::cout << "Char Stack Size: " << charStack.howMuch() << std::endl;
    std::cout << "Char Stack Top: " << charStack.outStack() << std::endl;
    std::cout << "Char Stack Size after pop: " << charStack.howMuch() << std::endl;
  
    // 测试std::string栈
    myStack<std::string> stringStack;
    stringStack.inStack("Hello");
    stringStack.inStack("World");
    std::cout << "String Stack Size: " << stringStack.howMuch() << std::endl;
    std::cout << "String Stack Top: " << stringStack.outStack() << std::endl;
    std::cout << "String Stack Top: " << stringStack.outStack() << std::endl;
    std::cout << "String Stack Size after pop: " << stringStack.howMuch() << std::endl;
  
    // 测试Student栈
    myStack<student> studentStack;
    studentStack.inStack(student("Alice", 101));
    studentStack.inStack(student("Bob", 102));
    std::cout << "Student Stack Size: " << studentStack.howMuch() << std::endl;
    std::cout << "Student Stack Top: " << studentStack.outStack() << std::endl;
    std::cout << "Student Stack Size after pop: " << studentStack.howMuch() << std::endl;
  
    return 0;
}
