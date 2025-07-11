#include <iostream>

using namespace std;

const int MAX_N = 1001;

int main(void)
{
	int t[MAX_N] = {0};

	int n;
	cin >> n;
	
	int tmp;
	for (int i=0; i<n; i++)
	{
		cin >> tmp;
		t[tmp]++;
		cout << t[tmp] << " ";
	}

	cout << endl;
	return 0;
}