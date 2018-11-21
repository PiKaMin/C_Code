#include <iostream>
#include <cstdlib>

using namespace std;
int main()
{
	cout << "计算器" << endl;
	int num1;
	int num2;

	cout << "输入第一个数:" << endl;
	cin >> num1;

	cout << "输入第二个数:" << endl;
	cin >> num2;

	int res = num1 + num2;
	cout << "两个数的和为:" << res << endl;

	system("pause");
}