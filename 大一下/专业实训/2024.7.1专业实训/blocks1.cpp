#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int maxn = 30;
int n;
vector<int> pile[maxn];  // 数组的元素是vector<int>


void find_block(int a, int& p, int& h)
{
	for ( p=0; p<n; p++ )
	{
		for ( h=0; h<pile[p].size(); h++)
		{
			if ( pile[p][h]==a )
				return;
		}
	}
}

void clear_above(int p, int h)
{
	for (int i=h+1; i<pile[p].size(); i++)
	{
		int b = pile[p][i];
		pile[b].push_back(b);
	}
	pile[p].resize(h+1);
}

void pile_onto(int p, int h, int p2)
{
	for ( int i=h; i<pile[p].size(); i++ )
	{
		pile[p2].push_back(pile[p][i]);
	}
	pile[p].resize(h);

}

void print()
{
	for ( int i=0; i<n; i++ )
	{
		cout << i << ": ";
		for ( int j=0; j<pile[i].size(); j++ )
		{
			cout << " " << pile[i][j];
		}
		cout << endl;
	}
}

int main(void)
{
	int a,b;
	cin >> n;
	string s1, s2;

	for (int i=0; i<n; i++)
		pile[i].push_back(i);

	while(cin >> s1 >> a >> s2 >> b)
	{
		int pa, pb, ha, hb;

		if (s1=="quit") return 0;

		find_block(a, pa, ha);
		find_block(b, pb, hb);

		if (pa==pb) continue;
		if (s2=="onto") clear_above(pb,hb);
		if (s1=="move") clear_above(pa,ha);
		pile_onto(pa, ha, pb);
	}

	print();
	return 0;
}