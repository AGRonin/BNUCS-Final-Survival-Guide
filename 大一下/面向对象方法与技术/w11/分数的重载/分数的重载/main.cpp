//
//  main.cpp
//  分数的重载
//
//  Created by 杨博文 on 2024/5/8.
//

#define TEST_FRACTION 1
#define TEST_MYSTRING 0
#define TEST_MYARRAY 0

#if TEST_FRACTION
#include "fraction.hpp"
int main()
{
    fraction  f1, f2(2, -3), f3(4, 5);
    cout << "f1=" << f1 << endl << "f2=" << f2 << endl << "f3=" << f3 << endl;
    cout << "***************************************\n";
    cout << "-f2 = " << -f2 << endl;
    cout << "***************************************\n";
    cout << "f1=f2+f3*fraction(1,2)\n";
    f1 = f2 + f3 * fraction(1, 2);
    cout << f1 << '=' << f2 << '+' << f3 << '*' << fraction(1, 2) << endl;
    cout << "***************************************\n";
    cout << "long(f4)\n";
    fraction f4(7, 2);
    cout << "long(" << f4 << ")=" << long(f4) << endl;
    cout << "***************************************\n";
    cout << "cin>>f1>>f2\n";
    cin >> f1 >> f2;
    cout << "f1=" << f1 << endl << "f2=" << f2 << endl;
    cout << "***************************************\n";
    cout << "f1>f2?\n";
    if (f1 > f2)
        cout << f1 << " > " << f2 << endl;
    else
        cout << f1 << " <= " << f2 << endl;
    cout << "***************************************\n";
    cout << "f2=++f1\n";
    f2 = ++f1;
    cout << "f2=" << f2 << endl << "f1=" << f1 << endl;
    cout << "***************************************\n";
    cout << "f2=f1++\n";
    f2 = f1++;
    cout << "f2=" << f2 << endl << "f1=" << f1 << endl;
    /*cout << "***************************************\n";
    cout<<"test f1+1 1+f1 need invalidate operator long()\n";
    cout << "f2=f1+1\n";
    f2 = f1 + 1;
    cout << "f2=" << f2 << endl << "f1=" << f1 << endl;
    cout << "***************************************\n";
    cout << "f2=1+f1\n";
    f2 = 1 + f1;
    cout << "f2=" << f2 << endl << "f1=" << f1 << endl;*/
    return 0;
}
#endif

#if TEST_MYSTRING
#include "mystring.hpp"
int main()
{
    STRING s1("abc"), s2("12345567"), s3(s1);
    s1 = s2;
    s1.operator=(s2);
    s3 = "ok";
    cout << "s1=" << s1 << endl << "s2=" << s2 << endl << "s3=" << s3 << endl;

    return 0;
}
#endif

#if TEST_MYARRAY
#include <iomanip>        //使用I/O操作符setw
#include "myarray.hpp"
int main()
{
    IntArray a(10);
    int i;
    for (i = 1; i <= a.size(); i++)
        a[i] = i * 10;        //a.operator[](i)=i*10    //a.data[i-1]=i*10;
    for (i = 1; i <= a.size(); i++)
        cout << setw(5) << a[i];        //a.operator[](i)
    cout << endl;
    return 0;
}
#endif


