#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 10000;
vector<int> a[N];

int f[N], r[N];	//多重链表，其中节点i的孩子链表a[i]为vector，f[i]是父节点，其层次为r[i]

void dfs(int u, int dep)		//从dep层的u节点出发，通过先序遍历计算每个节点的层次
{
	r[u] = dep;			//节点u为dep层
	for ( vector<int>::iterator it = a[u].begin();
		  it!=a[u].end(); it++ )	//递归遍历u的每个孩子节点
	{
		dfs(*it, dep+1);
	}
}

int main(void)
{
	int casenum, num, n, i, x, y;
	
	cin >> casenum;	//测试用例数目

	for (num=0; num<casenum; num++)
	{
		cin >> n;	//当前测试用例的节点数目
		for (i=0; i<n; i++)	//每个节点的孩子序列初始化
		{
			a[i].clear();
		}
		memset(f, 255, sizeof(f));
		for (i=0; i<n-1; i++)
		{
			cin >> x >> y;	//输入边（x，y）
			a[x-1].push_back(y-1);		// 将节点y-1 压入x-1节点的孩子列表
			f[y-1] = x-1;				// 节点y-1的父指针设为 x-1
		}
		for (i=0; f[i]>=0; i++);	//搜索根节点
			dfs(i,0);				//从根节点出发，计算每个节点的层次

		cin >> x >> y;				//输入节点对，计算这两个节点的序号
		x--;
		y--;

		while(x!=y)				//如果没有找到公共祖先，则反复计算深层次节点的父节点
		{
			if (r[x]>r[y])
				x=f[x];
			else
				y=f[y];
		}
		cout << x+1 << endl;
	}
	return 0;
}