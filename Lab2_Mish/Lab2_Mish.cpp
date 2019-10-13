#include <iostream>
#include <locale.h>

using namespace std;

int LeftNumber(int number);

int RightNumber(int number);

int CorrectInput(int& value);

void PrintArr(int arr[], int lngth);

void Remove(int*& arr, int &length, int index);

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Вариант 9. ИКБО-02-18. Шошников Иван\n";
	int length;
	cout << "Введите количество чисел\n";
	CorrectInput(length);
	int* Array = new int[length];
	cout << "Введите числа\n";
	for (int i = 0; i < length; i++)
		CorrectInput(Array[i]);
	cout << "\nИсходный массив \n";
	PrintArr(Array, length);
	for (int i = 0; i < length; i++) 
	{
		if (LeftNumber(Array[i]) == RightNumber(Array[i]))
			Remove(Array, length, i);
	}
	cout << "Массив после удаления\n";
	PrintArr(Array, length);
	delete[] Array;
}

int LeftNumber(int number)
{
	while (number) 
	{
		if (number / 10 > 9)
			number /= 10;
		else
			return number/10;
	}
}

int RightNumber(int number)
{
	return number % 10;
}

int CorrectInput(int& value)
{
	char fail;
	cin >> value;
	while (cin.fail())
	{
		cout << "Данные некорректны\n";
		cin.clear();
		cin >> fail;
		cin >> value;
	}
	return value;
}

void PrintArr(int arr[], int lngth)
{
	for (int i = 0; i < lngth; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

void Remove(int*& arr, int &length, int index)
{
	int* NewArray = new int[length - 1];
	if (index == length - 1) 
	{
		for (int i = 0; i < index; i++)
			NewArray[i] = arr[i];
		length--;
	}
	else 
	{
		for (int i = 0; i < index; i++)
			NewArray[i] = arr[i];

		length--;

		for (int i = index; i < length; i++)
			NewArray[i] = arr[i + 1];
	}

	delete[] arr;
	arr = NewArray;
}
