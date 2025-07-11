#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str("hello world the c++ programming");
	string str2 = "this is";
	string s;
	
	// 输入字符串到s
	cin >> s;
	cout << "the input string is : " << s  << endl;

	cout << "first char of s is : " << s.front() << endl; // s的第一个字符
	cout << "last char of s is :  "  << s.back()  << endl;  // s的最后一个字符

	// string 迭代器 可以理解为一个指向元素的指针
	string::iterator iter = s.begin();
	cout << "iterator begin() : " << *iter << endl;
	iter = s.end();
	cout << "iterator end() : "   << *iter << endl;

	// 向string插入字符
	cout << str << endl;
	str.push_back('!'); // 在str尾部插入字符!
	cout << "after push back '!' : " << str  << endl;
	str.insert(str.begin(), '#');
	cout << "after insert '#' at begin() : " << str  << endl;
	str.insert(str.begin()+12, ',');
	cout << "after insert ',' at begin()+12 : " << str  << endl;

	// string 删除元素
	str.pop_back(); //删除最后一个元素
	str.erase(str.begin()); // 删除迭代器所指向的元素
	str.erase(str.begin()+5, str.end()); // 删除指定区间的元素
	cout << "after erase some sub string : " << str << endl;

	// string 替换
	str.replace(str.begin(), str.begin()+2, "programming"); //替换迭代器指定的区间，长度可以不相等
	cout << "after replace : " << str << endl;
	str.replace(5, 4, "c++");  // 从第五个元素开始的连续4个元素被替换成 c++
	cout << "after replace : " << str << endl;

	// string 拼接
	str.append(str2); // 把str2加入到str的后面
	cout << "after append str2 : "  << str << endl;
	str = str+str2; // 把str2加入到str后面，保存到str中
	cout << "after operator + : "   << str << endl;

	// string 的长度
	cout << "length of string: by size() : "   << str.size() << endl;
	cout << "length of string: by length() : "   << str.length() << endl;

	// string 遍历
	for (int i=0; i<str.size(); i++)
		cout << str[i];
	cout << endl;

	// string 排序
	sort(str.begin(), str.end());
	cout << "after sort : " << str << endl;

	// string 比较
	if (str < str2) // 可以用 <    >    <=    >=    == 
		cout << str << " < " << str2 << endl;
	else cout << str << " >= " << str2 << endl;

	cout << "str :" << str << endl << "str2 :"  << str2 << endl;
	cout << "str.compare(str2)  :  " << str.compare(str2) << endl; // 相等为0， str > str2  返回正数， 反之负数

	// string 查找
	cout << "str.find(\"ii\") : " << str.find("ii") << endl; // 从前向后着，找到返回首字母下标，反之-1
	cout << "str.rfind(\"ii\") : " << str.rfind("ii") << endl; // 从后向前找，相耽于找最后一次出现的hello
	cout << "first of \"ghns\" : " << str.find_first_of("ghns")  << endl; // 查找第一个属于该字符串的字符的下标
	cout << "first not of \"ghns\" : " << str.find_first_not_of("ghns")  << endl;
	cout << "last of \"ghns\" : " << str.find_last_of("ghns") << endl;
	cout << "last not of \"ghns\" : " << str.find_last_not_of("ghns")  << endl;

	// string 某元素的个数
	cout << "count(str.begin(), str.end(), 's') : " << count(str.begin(), str.end(), 's') << endl; // 返回str里字符a的个数

	// string 分割
	cout << "str.substr(2,5) : " << str.substr(2,5)  << endl; //返回从索引2开始的五个元素组成的字符串

	// string是否为空？
	if (str.empty()) // 返回bool值
		cout << "str is empty" << endl;

	// string 清空
	str.clear();

	return 0;
}