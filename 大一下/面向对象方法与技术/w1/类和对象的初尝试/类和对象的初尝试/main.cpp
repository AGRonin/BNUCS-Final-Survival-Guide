//
//  main.cpp
//  类和对象的初尝试
//
//  Created by 杨博文 on 2024/2/21.
//

#include <iostream>
using namespace std;
class person
{
private:
    string name;
    int number;
public:
    string getName()
    {
        return name;
    }
    void setName(string sn)
    {
        name=sn;
    }
    int getNumber()
    {
        return number;
    }
    void setNumber(int num)
    {
        number=num;
    }
};
int main(int argc, const char * argv[]) 
{
    int numb;
    person obj;
    obj.setName("Zhang");
    cout << "Please enter the number";
    cin >> numb;
    obj.setNumber(numb);
    cout << obj.getName() << "'s number is " << obj.getNumber() << endl;
    return 0;
}
