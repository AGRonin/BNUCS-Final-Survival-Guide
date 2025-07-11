#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 1010;

int main(void)
{
    int n;
    int a[MAX_N];

    cin >> n;

    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    
    int ans = 0;

    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
        {
            if (abs(a[i] - a[j]) == 1)
            {
                ans ++;
            }
        }

    cout << ans << endl;
    return 0;
}