
#include <iostream>
#include <ctime>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;
int main() {


    srand(time(NULL));
    int number;
    cout << "Enter the number of matrix pairs " << endl;
    cin >> number;

    string str = "Laba4.3.1.txt";
    ofstream fout1;
    fout1.open(str);
    fout1.close();

    string str2 = "Laba4.3.2.txt";
    ofstream fout3;
    fout3.open(str2);
    fout3.close();


    for (int iterator = 0; iterator < number; iterator++)
    {

        system("cls");
        int i, j, sizeRow1, sizeCol1;
        cout << "Enter the number of rows of the matrix: ";
        cin >> sizeRow1;
        cout << "Enter the number of columns in the matrix: ";
        cin >> sizeCol1;

        int matr1[20][20];


        fout1.open(str, ofstream::app);
        if (!fout1.is_open()) cout << "Error";
        else
        {
            for (i = 0; i < sizeRow1; i++)
                for (j = 0; j < sizeCol1; j++)
                    matr1[i][j] = rand() % 15;

            cout << "Matrix №1:\n";
            fout1 << "Matrix №1:\n";
            for (i = 0; i < sizeRow1; i++) {
                cout << endl;
                for (j = 0; j < sizeCol1; j++) {
                    cout << matr1[i][j] << "\t";
                    fout1 << matr1[i][j] << "\t";
                }
                fout1 << endl;
            }
            fout1.close();
            fout1 << endl;
        }
        int sizeRow2, sizeCol2;
        cout << "\n\nEnter the number of rows of the second matrix: ";
        cin >> sizeRow2;

        while (sizeRow2 != sizeCol1)
        {
            cout << "The number of rows of the 2nd mattress should correspond to the number of columns of the 1st!\n";
            cout << "\nВведите количество строк второй матрицы:";
            cin >> sizeRow2;
        }
        cout << "Enter the number of rows of the second matrix: ";
        cin >> sizeCol2;


        int matr2[20][20];

        ofstream fout2;
        fout2.open(str, ofstream::app);
        if (!fout2.is_open()) cout << "Error";
        else
        {

            cout << "Matrix № 2\n";
            fout2 << "Matrix № 2\n";
            for (i = 0; i < sizeRow2; i++)
            {
                cout << endl;
                for (j = 0; j < sizeCol2; j++)
                {
                    matr2[i][j] = rand() % 9;
                    cout << matr2[i][j] << "\t";
                    fout2 << matr2[i][j] << "\t";
                }
                fout2 << endl;
            }
            fout2 << "______________________________\n\n";

            fout2.close();
        }
        int matr3[20][20];


        for (i = 0; i < sizeRow1; i++)
            for (j = 0; j < sizeCol2; j++)
            {
                matr3[i][j] = 0;
                for (int z = 0; z < sizeRow2; z++)
                    matr3[i][j] = matr3[i][j] + matr1[i][z] * matr2[z][j];
            }

        string str2 = "Laba4.3.2.txt";
        ofstream fout3;
        fout3.open(str2, ofstream::app);
        if (!fout3.is_open()) cout << "Error";
        else
        {
            cout << "\n\nMatrix Multiplication Result " << iterator + 1 << ":\n";
            fout3 << "Matrix Multiplication Result " << iterator + 1 << ":\n";
            for (i = 0; i < sizeRow1; i++)
            {
                cout << endl;
                for (j = 0; j < sizeCol2; j++)
                {
                    fout3 << matr3[i][j] << "\t";;
                    cout << matr3[i][j] << "\t";
                }
                fout3 << endl;
            }
            fout3 << "____________________________\n\n";
            cout << endl << endl;
            system("pause");
        }

    }
    system("cls");
    ifstream fil1;
    fil1.open("Laba4.3.1.txt");
    if (!fil1.is_open()) cout << "Error";
    else
    {
        cout << "Matrices from the first file " << endl;
        string s;
        while (!fil1.eof())
        {
            string s = "";
            getline(fil1, s);
            cout << s << endl;
        }
        fil1.close();
    }
    cout << "====================================\n\n";
    ifstream fil2;
    fil2.open("Laba4.3.2.txt");
    if (!fil2.is_open()) cout << "Error";
    else
    {
        cout << "Matrices from the second file " << endl;
        string s;
        while (!fil2.eof())
        {
            string s = "";
            getline(fil2, s);
            cout << s << endl;
        }
        fil2.close();
    }

    return 0;
}

