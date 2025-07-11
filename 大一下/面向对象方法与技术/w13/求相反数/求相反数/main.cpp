//
//  main.cpp
//  求相反数
//
//  Created by 杨博文 on 2024/5/22.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{   const int N = 5;

    vector<int> s(N);

    for (int i=0; i<N; i++)
        cin >> s[i];

    transform(s.begin(),
              s.end(),
              ostream_iterator<int>(cout, " "),
              negate<int>() );
    cout << endl;
    return 0;
}
