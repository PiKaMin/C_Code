#include <iostream>
#include <string>

using namespace std;
int main()
{
	//cin ��ȡ����������м��пո�,ֻ��ȡ���ո�֮ǰ������ 
	string name;
	//cin >> name;
	//cout << name << endl;
	//������ȡһ�������м�����пո������,����ʹ��getline()
	getline(cin, name);
	cout << name << endl;
	system("pause");
	return 0;
}