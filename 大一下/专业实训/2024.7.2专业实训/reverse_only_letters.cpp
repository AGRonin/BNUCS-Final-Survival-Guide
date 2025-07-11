#include <iostream>
#include <string>

using namespace std;

void reverse_letters(string& s)
{
	int left = 0;
	int right = s.size()-1;

	while ( left<right )
	{
		while ( left<right && !isalpha(s[left]) )
		{
			++left;
		}
		while ( left<right && !isalpha(s[right]) )
		{
			--right;
		}
		swap(s[left], s[right]);
		++left;
		--right;
	}
}


void reverse_letters_iterator(string& s)
{
	string::iterator iterLeft=s.begin();
	string::iterator iterRight=s.end()-1;

	while ( iterLeft<iterRight )
	{
		while ( iterLeft<iterRight && !isalpha(*iterLeft) )
			++iterLeft;
		while ( iterLeft<iterRight && !isalpha(*iterRight) )
			--iterRight;
		swap(*iterLeft, *iterRight);
		++iterLeft;
		--iterRight;
	}
}

int main(void)
{
	string s;
	cin >> s;
	reverse_letters_iterator(s);
	cout << s;
	return 0;
}