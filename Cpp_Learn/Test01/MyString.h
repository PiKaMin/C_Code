#pragma once
//�ڶ��ֵ��͵��� class with point
//���� �������ʱ,Ҫ���Ǽ���������: �������� , ������ֵ , ��������

class MyString
{
public:
	MyString(const char* str = 0); //���캯�� ����һ���ַ�ָ��

	MyString(const MyString& str); //�������� ����: MyString str1(str2),
	                               //����һ��MyString���͵Ķ���
	MyString& operator=(const MyString& str); //������ֵ

	~MyString(); //��������
private:
	char* m_data; //���ﲻ�������ԭ�����������ָ����С,��ָ��������
};


