#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1001;

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

    sort(a,a+n);

    for (int i=0; i<n-1; i++)
    {
        if ( a[i+1]==a[i]+1 )
        {
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}