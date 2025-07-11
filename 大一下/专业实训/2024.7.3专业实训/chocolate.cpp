#include <iostream>

using namespace std;

const int MAX_N = 100000;
int n, k;
int h[MAX_N], w[MAX_N];

int cut(int x) //在x的边长下，求能分几块巧克力的函数
{
	int res = 0;
	for(int i=1; i<=n ; i++)
	{
		res += ( h[i]/x ) * ( w[i]/x );
	}
	return res;
}

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i ++ )
		cin >> h[i] >> w[i];

	 //这里是巧克力边长的范围
	int l = 0;
	int r = 1e5;
	while(l < r)//找符合条件的巧克力边长的最大值，也就是右区间
	{
		int mid = (l + r + 1)/2;
		if( cut(mid) >= k )  l = mid;
		else r = mid - 1;
	}
	cout << r << endl;
	return 0;
}
