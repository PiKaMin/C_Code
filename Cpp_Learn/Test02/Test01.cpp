#include <iostream>
#include <string>

using namespace std;
int main()
{
	//cin 获取的输入如果中间有空格,只获取到空格之前的输入 
	string name;
	//cin >> name;
	//cout << name << endl;
	//如果想获取一行输入中间可以有空格的输入,可以使用getline()
	getline(cin, name);
	cout << name << endl;
	system("pause");
	return 0;
}