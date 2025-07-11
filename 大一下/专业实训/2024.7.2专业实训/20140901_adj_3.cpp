#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 10010;

int main(void)
{
    int n;
    int cnt[MAX_N] = {0};

    cin >> n;

    int tmp;
    for (int i=0; i<n; i++)
    {
        cin >> tmp;
        cnt[tmp]++;
    }
    
    int ans = 0;

    for (int i=0; i<MAX_N-1; i++)
    {
        if ( cnt[i]>0 && cnt[i+1]>0 )
        {
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}