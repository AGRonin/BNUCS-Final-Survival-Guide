#include<iostream>
#include<string>

using namespace std;

const int N = 128;

int h[N]; //第i个字符的数量

int main() {
    string str;
    cin>>str;
    int q;
    cin>>q;
    while(q--) {
        memset(h, 0, sizeof h);
        int l1, r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;
        for(int i = l1 - 1; i <= r1 - 1; i++) {//第i个数下标为i-1
            h[str[i]]++; //记录区间不同字符的数量
        }
        for(int i = l2 - 1; i <= r2 - 1; i++) {
            h[str[i]]--; //若二者相消，则说明相等
        }
        bool flag = true;
        for(int i = 0; i < N; i++) {
            if(h[i] != 0) {
                flag = false;
                break;
            }
        }
        if(flag) cout<<"DA"<<endl;
        else cout<<"NE"<<endl;
    }
    return 0;
}