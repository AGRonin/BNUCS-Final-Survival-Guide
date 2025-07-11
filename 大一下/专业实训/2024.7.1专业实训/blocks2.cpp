#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Position
{
public:
	int p;
	int h;
	Position():p(-1),h(-1){};
};

class BlockPiles
{
public:
	BlockPiles(int n):numPiles(n) {}
	
	void init();
	Position find_block(int a);
	void clear_above(const Position& pos);
	void pile_onto(const Position& pos, int p);
	void print();
private:
	int numPiles;
	vector<vector<int> > piles;
};

void BlockPiles::init()
{
	piles.resize(numPiles);

	for (int i=0; i<numPiles; i++)
	{
		piles[i].push_back(i);
	}
}

Position BlockPiles::find_block(int a)
{
	Position pos;
	for ( pos.p=0; pos.p<numPiles; pos.p++ )
	{
		for ( pos.h=0; pos.h<piles[pos.p].size(); pos.h++)
		{
			if ( piles[pos.p][pos.h]==a )
				return pos;
		}
	}
	return pos;
}

void BlockPiles::clear_above(const Position& pos)
{
	for (int i=pos.h+1; i< piles[pos.p].size(); i++)
	{
		int b =  piles[pos.p][i];
		 piles[b].push_back(b);
	}
	 piles[pos.p].resize(pos.h+1);
}

void BlockPiles::pile_onto(const Position& pos, int p)
{
	for ( int i=pos.h; i< piles[pos.p].size(); i++ )
	{
		 piles[p].push_back( piles[pos.p][i]);
	}
	 piles[pos.p].resize(pos.h);

}

void BlockPiles::print()
{
	for ( int i=0; i<numPiles; i++ )
	{
		cout << i << ": ";
		for ( int j=0; j< piles[i].size(); j++ )
		{
			cout << " " <<  piles[i][j];
		}
		cout << endl;
	}
}

int main(void)
{
	//int n;
	//vector<int>  piles[MAX_N];  // 数组的元素是vector<int>
	int n;
	int a, b;
	string s1, s2;

	cin >> n;
	BlockPiles bp(n);
	bp.init();

	while((cin >> s1) && s1!="quit")
	{
		cin >> a >> s2 >> b;

		Position pos_a = bp.find_block(a);
		Position pos_b = bp.find_block(b);

		if (pos_a.p==pos_b.p) continue;
		if (s2=="onto") bp.clear_above(pos_b);
		if (s1=="move") bp.clear_above(pos_a);
		bp.pile_onto(pos_a, pos_b.p);
	}

	bp.print();
	return 0;
}