#include <iostream>

using namespace std;

#define N 10000

unsigned sum_of_digits(unsigned n)
{	
	int sum = 0;

	while (n>0)
	{
		sum += n%10;
		n = n/10;
	}

	return sum;
}

void generate_sequence(unsigned n, unsigned num[])
{
	while (n<N)
	{
		unsigned next = n + sum_of_digits(n);
		
		if ( next >=N || num[next]!=0 )
		{
			return;
		}

		num[next] = n;
		n = next;
	}
}

void output(unsigned num[])
{
	for (int i=1; i<N; i++)
	{
		if (num[i]==0)
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

int main(void)
{
	unsigned num[N] = {};

	for (int i=1; i<N; i++)
	{
		generate_sequence(i, num);
	}

	output(num);

	return 0;
}