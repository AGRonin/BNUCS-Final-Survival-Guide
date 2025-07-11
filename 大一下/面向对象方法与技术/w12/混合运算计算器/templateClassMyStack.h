//
//  templateClassMyStack.h
//  混合运算计算器
//
//  Created by 杨博文 on 2024/5/17.
//

#ifndef templateClassMyStack_h
#define templateClassMyStack_h

#include <iostream>

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
    if(_nowSize+10<_size && _size>=20)//如果空的太多，那就减10个
    {
        resize(_size-10);
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

#endif /* templateClassMyStack_h */
