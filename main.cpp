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
	Array_int(const Array_int& original, int length)
	{
		m_arr = new int[length];
		Array_int m_arr = original;
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
	int getLength() const
	{return m_length;}

	int getValue(int index) 
	{ return m_arr[index]; }

	void print() const
	{
		for (int count = 0; count < m_length; ++count)
			cout << m_arr[count] << " ";
		cout << endl;
	}

	void plusOne()
	{
		int* m_arr_plusOne;
		m_arr_plusOne = new int[m_length + 1];
		for (int count = 0; count < m_length; count++)
			m_arr_plusOne[count] = m_arr[count];

		for (int count = 0; count < m_length+1; ++count)
			cout << m_arr[count] << " ";
		cout << endl;
	}
};
void konkat(Array_int& arr1, Array_int& arr2)
{
	int* konkat_arr;
	konkat_arr = new int[arr1.getLength() + arr2.getLength()];
	for (int count = 0; count < arr1.getLength() + arr2.getLength(); count++)
		if (count < arr1.getLength())
			konkat_arr[count] = arr1.getValue(count);
		else
			konkat_arr[count] = arr2.getValue(count - arr1.getLength());
	for (int count = 0; count < arr1.getLength() + arr2.getLength(); count++)
		cout << konkat_arr[count] << " ";
		cout << endl;

}

int main()
{
	Array_int arr1(10);
	arr1.print();
	arr1.fillRandom();
	arr1.print();

	//arr1.plusOne();
	
	Array_int arr2(5);
	//arr2 = { arr1 };
	cout << endl;
	arr2.fillRandom();
	arr2.print();

	konkat(arr1, arr2);


	return 0;
}
