#include <iostream>
#include <string>

using namespace std;

void myreverse(string& s)
{
	if (s.size()==0) return;
	size_t i=0;
	size_t j=s.size()-1;
	while(i<j)
	{
		char c=s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

int main(void)
{
	string s;
	getline(cin, s);
	myreverse(s);
	cout << s << endl;
	return 0;
}
