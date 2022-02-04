/*1. Создайте класс «Массив целых чисел». Внутри него живёт динамически выделяемый массив целых чисел.
Массив выделяется в конструкторе; размер передают как аргумент конструктора. В деструкторе массив уничтожается.
Напишите методы:
• Сделать все числа массива случайными
• Перевыделить массив с размером на 1 больше; перенести в него все старые значения
• Распечатать массив (константный метод)
• Узнать размер массива (константный метод)
2. Добавьте в класс Массива целых чисел конструктор копирования. Каждый объект класса хранит персональную копию массива целых чисел. Если объект умирает, он уничтожает свою копию.
Проверьте, что конструктор копирования работает.
3. Напишите функцию конкатенации двух Массивов целых чисел:
Массив1 + Массив2 = Массив3
Она принимает два объекта Массивов целых чисел и создаёт новый в ответ. Вызовите эту функцию и распечатайте результат. Узнайте, сколько раз был вызван конструктор копирования.
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
	Array_int(int length) // конструктор
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
	~Array_int() // деструктор
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
