#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Student
{
public:
	string surname;
	string name;
	string patronymic;
	string floor;
	string nationality;
	string date_of_birth;
	string home_address;
	string phone_number;
	string course;
};

ostream& operator << (ostream& os, const Student& student);
istream& operator >> (istream& is, Student& student);

void output_owner(Student st);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "ru");
	Student* st = new Student[9];
	int number;

	while (true)
	{
		system("cls");

		Student student;
		int choose;
		cout << "1.Создание файла.\n";
		cout << "2.Добавление элемента в конец файла.\n";
		cout << "3.Вывод содержимого файла на экран.\n";
		cout << "4.Удаление элемента из файла(с заданным номером).\n";
		cout << "5.Удаление элемента из файла(с заданным ключом).\n";
		cout << "6.Упорядочивание элементов в файле по выбранному признаку, сортировкой перемешиванием.\n";
		cout << "Выберите действие\n ";

		cin >> choose;
		system("cls");
		switch (choose)
		{
		case 1:
		{
			ofstream file;
			file.open("Laba4.txt");
			if (!file.is_open())
			{
				cout << "Ошибка";
			}
			else
				cout << "Файл создан\n";
			file.close();
			Sleep(1000);
			break;
		}
		case 2:
		{
			ofstream file;
			file.open("Laba4.txt", ofstream::app);
			if (!file.is_open())
			{
				cout << "Ошибка";
			}
			else
			{
				cout << "Введите количество обитуриентов: ";
				cin >> number;
				if (number <= 0)
					break;
				else
				{
					st = new Student[number];
					for (int i = 0; i < number; i++)
					{
						system("cls");


						cout << "Введите фамилию: "; cin >> st[i].surname;
						cout << "Введите имя: "; cin >> st[i].name;
						cout << "Введите отчество: "; cin >> st[i].patronymic;
						cout << "Введите пол: "; cin >> st[i].floor;
						cout << "Введите национальность: "; cin >> st[i].nationality;
						cout << "Введите день рождения: "; cin >> st[i].date_of_birth;
						cout << "Введите адрес: "; cin >> st[i].home_address;
						cout << "Введите номер телефона "; cin >> st[i].phone_number;
						cout << "Введите курс "; cin >> st[i].course;
						file << st[i];
					}
					cout << "Все данные введены!";
					Sleep(1000);
					system("cls");
				}
			}
			file.close();
			break;
		}
		case 3:
		{
			ifstream file;
			file.open("Laba4.txt");
			if (!file.is_open())
			{
				cout << "Ошибка";
			}
			else
			{
				int i = 0;
				while (!file.eof())
				{
					file >> st[i];
					if (file.eof())
					{
						break;
					}
					cout << st[i] << endl;
					i++;
				}
				system("pause");
			}
			file.close();
			break;
		}
		case 4:
		{
			vector< Student>Myvector;
			ifstream file;
			file.open("Laba4.txt");
			if (!file.is_open())
			{
				cout << "Ошибка";
			}
			else
			{
				while (!file.eof())
				{
					file >> student;
					if (file.eof())
					{
						break;
					}
					Myvector.push_back(student);
				}
				int number;
				cout << "Под каким номером удалить студента ";
				cin >> number;
				if (number == 0 || number > Myvector.size())
				{
					cout << "Нет студента с таким номером";
					Sleep(1000);
					break;
				}
				else
				{
					number--;
					Myvector.erase(Myvector.begin() + number);

					ofstream file;
					file.open("Laba4.txt");
					if (!file.is_open())
					{
						cout << "Ошибка";
					}
					else
					{
						for (int i = 0; i < Myvector.size(); i++)
							file << Myvector[i];

					}
					system("cls");
					cout << "Выполнено";
					Sleep(1000);
				}
			}
			file.close();
			break;
		}
		case 5:
		{
			ifstream file;
			file.open("Laba4.txt");
			if (!file.is_open())
			{
				cout << "Ошибка";
			}
			else
			{
				int i = 0;
				vector<Student>myVector;
				while (!file.eof())
				{
					file >> st[i];
					if (file.eof())
					{
						break;
					}
					cout << st[i] << endl;
					myVector.push_back(st[i]);
					i++;
				}
				cout << "С какой фамилией студента удалить? ";
				string last_n;
				cin >> last_n;

				for (int i = 0; i < myVector.size(); i++)
				{
					if (st[i].surname == last_n)
					{
						myVector.erase(myVector.begin() + i);
						break;
					}
				}
				ofstream file;
				file.open("Laba4.txt");
				if (!file.is_open())
				{
					cout << "Ошибка";
				}
				else
				{
					for (int i = 0; i < myVector.size(); i++)
						file << myVector[i];
				}
				system("cls");
				cout << "Выполнено";
				Sleep(1000);
			}
			file.close();
			break;
		}
		case 6:
		{
			ifstream file;
			file.open("Laba4.txt");
			if (!file.is_open())
			{
				cout << "Ошибка";
			}
			else
			{
				int j = 0;
				vector<Student>myVector;
				while (!file.eof())
				{
					file >> st[j];
					if (file.eof())
					{
						break;
					}
					cout << st[j] << endl;
					myVector.push_back(st[j]);
					j++;
				}
				Student st_copy;
				for (int i = 0; i < j - 1; i++)
				{
					if (st[i].surname[0] > st[i + 1].surname[0])
					{

						st_copy = st[i];
						st[i] = st[i + 1];
						st[i + 1] = st_copy;
					}
					else
					{
						cout << "Ошибка!"; continue;
					}
				}
				ofstream file;
				file.open("Laba4.txt");
				if (!file.is_open())
				{
					cout << "Ошибка";
				}
				else
				{
					for (int i = 0; i < j; i++)
						file << st[i];
				}
				system("cls");
				cout << "Выполнено";
				Sleep(1000);


			}
			break;
		}
		case 7:
			return 0;
			break;

		}
	}
	system("pause");
	return 0;

}


void output_owner(Student st)
{
	cout << "Фамилия: " << st.surname << endl;
	cout << "Имя: " << st.name << endl;
	cout << "Отчество: " << st.patronymic << endl;
	cout << "Пол: " << st.floor << endl;
	cout << "Национальность: " << st.nationality << endl;
	cout << "День рождения: " << st.date_of_birth << endl;
	cout << "Адрес: " << st.home_address << endl;
	cout << "Номер телефона: " << st.phone_number << endl;
	cout << "Курс: " << st.course << endl;
}


ostream& operator << (ostream& os, const Student& student)
{
	os << student.surname << " " << student.name << " " << student.patronymic << " " << student.floor << " " << student.nationality
		<< " " << student.date_of_birth << " " << student.home_address << " " << student.phone_number << " " << student.course << "\n";
	return os;
}
istream& operator >> (istream& is, Student& student)
{
	is >> student.surname >> student.name >> student.patronymic >> student.floor >> student.nationality
		>> student.date_of_birth >> student.home_address >> student.phone_number >> student.course;
	return is;
}

