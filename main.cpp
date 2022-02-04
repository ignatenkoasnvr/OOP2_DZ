/*1. �������� ����� ������� ����� �����. ������ ���� ���� ����������� ���������� ������ ����� �����.
������ ���������� � ������������; ������ �������� ��� �������� ������������. � ����������� ������ ������������.
�������� ������:
� ������� ��� ����� ������� ����������
� ������������ ������ � �������� �� 1 ������; ��������� � ���� ��� ������ ��������
� ����������� ������ (����������� �����)
� ������ ������ ������� (����������� �����)
2. �������� � ����� ������� ����� ����� ����������� �����������. ������ ������ ������ ������ ������������ ����� ������� ����� �����. ���� ������ �������, �� ���������� ���� �����.
���������, ��� ����������� ����������� ��������.
3. �������� ������� ������������ ���� �������� ����� �����:
������1 + ������2 = ������3
��� ��������� ��� ������� �������� ����� ����� � ������ ����� � �����. �������� ��� ������� � ������������ ���������. �������, ������� ��� ��� ������ ����������� �����������.
*/
#include <string>
#include <iostream>
#include <cassert>
#include <time.h>

using namespace std;

class Array_int
{
private:
	int* m_arr;
	int m_length;

public:
	Array_int(int length) // �����������
	{
		assert(length > 0);
		m_arr = new int[length];
		m_length = length;
	}

	~Array_int() // ����������
	{
		delete[] m_arr;
	}

	void fillRandom()
	{
		srand(time(NULL));
		for (int count = 0; count < m_length; ++count)
			m_arr[count] = rand() % 10 + 1;
	}

	void print()
	{
		for (int count = 0; count < m_length; ++count)
			cout << m_arr[count] << " ";
		cout << endl;
	}

};

int main()
{

	Array_int arr1(10);
	arr1.print();
	arr1.fillRandom();
	arr1.print();


	return 0;
}
