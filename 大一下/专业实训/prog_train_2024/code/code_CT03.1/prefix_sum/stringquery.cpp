// 前缀和
#include <iostream>
#include <cstring>
using namespace std;

string str;
int a, b, c, d, q, idx, ps[26][50010]; // ps保存a~z的前缀和

bool check(){
    for(int i=0; i<26; i++)
        if( ps[i][b]-ps[i][a-1] != ps[i][d]-ps[i][c-1] )
            return false;
    return true;
}

int main(){
    cin >> str;
    cin >> q;

    // 构造前缀和数组
    for(int i=1; i<str.size()+1; i++){
        for(int j=0; j<26; j++)
            ps[j][i] = ps[j][i-1];
        idx = str[i-1] - 'a';
        ps[idx][i]++;
    }

    // 询问
    while( q -- ){
        cin >> a >> b >> c >> d;
        if( check() )   cout << "DA" << endl;
        else cout << "NE" << endl;
    }

    return 0;
}


/*
	for (int i=0; i<26; i++)
		for (int j=1; str[j]!='\0'; j++)
			if (str[j]-'a' == i)
				s[i][j] = s[i][j-1] +1;
			else
				s[i][j] = s[i][j-1];

*/