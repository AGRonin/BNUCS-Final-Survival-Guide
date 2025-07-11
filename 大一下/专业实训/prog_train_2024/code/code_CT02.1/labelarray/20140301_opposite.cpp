#include<iostream>
#include<cmath>
using namespace std;

const int MAX_N = 1001;

int main(void)
{
    int n;
    int count=0;
    int number;
    int flag[MAX_N] = {0};
    
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        cin >> number;

        if( flag[abs(number)]==1 )
        {
        	count++;
        } 
        else
        {
        	flag[abs(number)] = 1;
        }
    }

    cout << count << endl;

    return 0;
}