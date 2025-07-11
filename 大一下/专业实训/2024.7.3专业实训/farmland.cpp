#include <iostream>

using namespace std;

const int N = 100010;

int n,m,k;
int t[N], c[N];

bool check(int mid)
{
	long long res = 0;
	for (int i=0; i<n; i++)
		if (t[i] > mid)
			res += (long long)(t[i]-mid)*c[i];
	return res<=m;
}

int main()
{
	cin >> n  >> m >> k;

	for (int i=0; i<n; i++)
	{
		cin >> t[i] >> c[i];
	}

	int l=k, r=1e5;

	while (l<r)
	{
		int mid = (l+r)/2;
		if (check(mid)) r = mid;
		else
			l = mid+1;
	}

	cout << r << endl;
	return 0;
}
