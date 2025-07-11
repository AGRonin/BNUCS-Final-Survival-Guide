#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 510;
int s[N][N];
int n, m, k;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%d", &s[i][j]);
			s[i][j] += s[i - 1][j];
		}
	}

	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			int sum = 0;
			for(int l = 1, r = 1; r <= m; r++)
			{
				sum += s[j][r] - s[i - 1][r];

				//为什么不用写l <= r?因为当l = r + 1时sum = 0
				//可以想象一下当第一列的和就大于k时程序如何运行
				//为什么不用写l <= m?因为当l最大只能加到r + 1
				//且当l = m + 1时r只能是m,然后结束循环
				while(sum > k) 
				{
					sum -= s[j][l] - s[i - 1][l];
					l++;
				}

				//前面提到l <= r + 1,当l = r + 1时显然不是一个合法矩阵
				//但是r - l + 1等于0，所以不需要进行特判
				//为什么是r - l + 1?
				//因为我们的子矩阵定义的是以r为右端点的子矩阵
				//因此只需要考虑与r连续，以r为右端点并包含r矩阵即可
				ans += r - l + 1;
			}
		}
	}

	printf("%lld", ans);

	return 0;
}