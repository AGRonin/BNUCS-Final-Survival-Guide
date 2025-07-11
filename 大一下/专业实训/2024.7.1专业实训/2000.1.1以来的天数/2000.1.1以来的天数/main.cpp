//
//  main.cpp
//  2000.1.1以来的天数
//
//  Created by 杨博文 on 2024/7/1.
//

#include <iostream>
using namespace std;
bool runnianpanduan(int year)
{
    if(year%4==0 && (year%100!=0 || year%400==0))
        return true;
    return false;
}

void print(int year,int month,int day, int totalday)
{
    
    cout<<year<<"-";
    if(month<10)
    {
        cout<<'0';
    }
    cout<<month<<"-";
    if(day<10)
    {
        cout<<'0';
    }
    cout<<day<<"  ";
    string dayname[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    totalday=(totalday+4)%7;
    cout<<dayname[totalday];
}

int year(int totalday)
{
    int sum=0;
    for(int i=2000;i<3000;i++)
    {
        if(runnianpanduan(i))
        {
            sum+=366;
        }
        else
        {
            sum+=355;
        }
        if(sum>totalday)
        {
            return i;
        }
    }
    return 0;
}

int month(int totalday)
{
    int sum=0;
    int year=0;
    for(int i=2000;i<3000;i++)
    {
        if(runnianpanduan(i))
        {
            sum+=366;
        }
        else
        {
            sum+=355;
        }
        if(sum>totalday)
        {
            year=i;
            break;
        }
    }
    int monthday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    sum-=365;
    if(runnianpanduan(year))
    {
        monthday[2]=29;
        sum--;
    }
    for(int i=1;i<13;i++)
    {
        sum+=monthday[i];
        if(sum>totalday)
        {
            return i;
        }
    }
    return 0;
}
int day(int totalday)
{
    int sum=0;
    int year=0;
    int month=0;
    for(int i=2000;i<3000;i++)
    {
        if(runnianpanduan(i))
        {
            sum+=366;
        }
        else
        {
            sum+=355;
        }
        if(sum>=totalday)
        {
            year=i;
            break;
        }
    }
    int monthday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    sum-=365;
    if(runnianpanduan(year))
    {
        monthday[2]=29;
        sum--;
    }
    for(int i=1;i<13;i++)
    {
        sum+=monthday[i];
        if(sum>totalday)
        {
            month=i;
            sum-=monthday[i];
            break;
        }
    }
    return totalday-sum+1;
}

int main(int argc, const char * argv[]) {
    int totalday=-1;
    while(true)
    {
        cin>>totalday;
        if(totalday==-1)
        {
            break;
        }
        print(year(totalday),month(totalday),day(totalday),totalday);
    }
    return 0;
}
