#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	getline(cin,str);
	int pos = str.rfind(' ');
	cout << str.size() - pos -1 << endl;
	return 0;
}