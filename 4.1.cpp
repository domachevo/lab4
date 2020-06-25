using namespace std;

#include <iostream>

void FillArray(int* const Array, const int size)
{
	for (int i = 0; i < size; i++) {
		Array[i] = rand() % 20;
	}
}
void ShowArray(int* const Array, const int size)
{
	for (int i = 0; i < size; i++)
		cout << Array[i] << " ";
	cout << endl;
}
void SortArray(int* const Array, const int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (Array[j] > Array[j + 1]) {
				int t = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = t;
			}
		}
	}
	cout << "Данные после сортировки: ";
	for (int i = 0; i < size; i++)
		cout << Array[i] << " ";
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "ru");

	void (*P[3])(int* const, const int) = { FillArray , ShowArray ,SortArray };
	cout << "1.FillArray\n";
	cout << "2.ShowArray\n";
	cout << "3.SortArray\n";
	cout << "Your choose?\n ";
	int size = 10;
	int* Array = new int[size];


	while (true)
	{
		int punct;
		cin >> punct;

		if (punct <= 0 || punct > 3)
		{
			return 0;
		}

		punct--;
		(*P[punct])(Array, size);

		cout << "Enter 0 to exit\n";
	}
	return 0;
}

