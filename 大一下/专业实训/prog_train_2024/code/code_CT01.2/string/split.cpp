#include <iostream>
#include <string>
#include <vector>

using namespace std;

void split(const string& s, const char delimiter, vector<string>& tokens)
{
	if ( s=="" ) return;
	string str = s+delimiter;
	size_t pos = str.find(delimiter);

	while ( pos!=string::npos )
	{
		string temp = str.substr(0,pos);
		if ( temp!="" )
		{
			tokens.push_back(temp);
		}
		str = str.substr(pos+1, str.size() );
		pos = str.find(delimiter);
	}
}

int main(void)
{
	string s;
	const char delimiter = ' ';
	vector<string> tokens;

	getline(cin,s);
	split(s,delimiter,tokens);
	
	for (int i=0; i<tokens.size(); i++)
		cout << tokens[i] << " ";

	return 0;
}