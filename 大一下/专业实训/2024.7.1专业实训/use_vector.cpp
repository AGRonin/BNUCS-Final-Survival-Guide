#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	// vector 变量
	vector<int> v;
	
	for (int i=0; i<n; i++)
	{
		int number;
		cin >> number;
		v.push_back(number); //从后面加入数据
	}


	// vector 的头尾元素
	cout << v.front() << endl;
	cout << v.back()  << endl;

	// vector 迭代器
	vector<int>::iterator it;
	it = v.begin();
	cout << *it << endl;
	it = v.end();  // vector 的 end() 表示数据的结尾，在正常数据之外

	// vector 删除
	v.pop_back();
	v.erase(v.begin());
	v.erase(v.begin()+1, v.end()-2);

	// vector 里面的数据个数
	cout << v.size() << endl;

	// vector 遍历
	for (int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	
	for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
		cout << *it << " ";
	cout << endl;

	// vector 排序
	sort(v.begin(), v.end());

	// vector 从前向后寻找值的2的元素，若找到，返回迭代器，否则，返回end()
	vector<int>::iterator iter = find(v.begin(), v.end(), 2);

	// vector中值为2 的元素个数
	cout << count(v.begin(), v.end(), 2) << endl;

	// vector 是否为空？
	if (v.empty()) cout << "v is empty \n";
	else cout << "v is not empty\n";

	// 清空 vector
	v.clear();

	if (v.empty()) cout << "v now is empty after clear itself.\n";
	else cout << "something is wrong when clearing v.\n";

	return 0;
}