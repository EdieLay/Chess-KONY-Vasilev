// Vasilev CHESS Koroleva.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <Windows.h>
#include <iomanip>
#include <ctime>

using namespace std;

int c = 0, maxamount = 0;

void showdesk(int** desk, int n)
{
    int i, j, x = 0, y = 0;
    int** fulldesk = new int* [n];
    for (i = 0; i < n; i++)
        fulldesk[i] = new int[n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fulldesk[i][j] = 0;
    for (i = 1; i <= maxamount; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (desk[0][j] == i)
                x = j;
            if (desk[1][j] == i)
                y = j;
        }
        fulldesk[y][x] = i;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (fulldesk[i][j] > 0)
            {
                HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_BLUE);
                cout << std::left << std::setfill(' ') << std::setw(3) << fulldesk[i][j];
            }
            else
            {
                HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_RED);
                cout << std::left << std::setfill(' ') << std::setw(3) << fulldesk[i][j];
            }
        }
        cout << endl;
    }
}

void removequeen(int** arr, int len, int num)
{
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < len; i++)
        if (arr[j][i] == num)
        {
            arr[j][i] = 0;
            break;
        }
}

void checkngofree(int** A, int** diag, int y, int x, int n)
{
    //int i;
    if ((x < n) && (y < n))
    {
        if ((A[0][x] == 0) && (A[1][y] == 0) && (diag[0][x+y] == 0) && (diag[1][x+abs(y-n+1)] == 0))
        {
            c++;
            if (c > maxamount)
                maxamount = c;
            /*for (i = 0; i < n; i++)
            {
                if (A[i][x] == 0)
                    A[i][x] = c;
                if (A[y][i] == 0)
                    A[y][i] = c;
                if ((y + i + 1 < n) && (x + i + 1 < n) && (A[y + i + 1][x + i + 1] == 0))
                    A[y + i + 1][x + i + 1] = c;
                if ((y - i - 1 < n) && (x + i + 1 >= 0) && (A[y - i - 1][x + i + 1] == 0))
                    A[y - i - 1][x + i + 1] = c;
                if ((y - i - 1 >= 0) && (x - i - 1 >= 0) && (A[y - i - 1][x - i - 1] == 0))
                    A[y - i - 1][x - i - 1] = c;
                if ((y + i + 1 < n) && (x - i - 1 >= 0) && (A[y + i + 1][x - i - 1] == 0))
                    A[y + i + 1][x - i - 1] = c;
            }*/
            A[0][x] = c;
            A[1][y] = c;
            diag[0][x + y] = c;
            diag[1][x + abs(y - n+1)] = c;
            checkngofree(A, diag, 0, x + 1, n);
            if (maxamount != n)
            {
                removequeen(A, n, c);
                removequeen(diag, 2 * n - 1, c);
                c--;
                checkngofree(A, diag, y + 1, x, n);
            }
        }
        else
        {
            checkngofree(A, diag, y + 1, x, n);
        }
    }
}

int main()
{
    unsigned int start_time = clock();
    int n, i, j;
    cout << "Input size of desk: ";
    while (1)
    {
        cin >> n;
        if (cin.fail() || n <= 2)
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Error! Size must be integer number greater than 2." << endl;
        }
        else break;
    }
    int** desk = new int* [2];
    for (i = 0; i < 2; i++)
        desk[i] = new int[n];
    for (i = 0; i < 2; i++)
        for (j = 0; j < n; j++)
            desk[i][j] = 0;
    int** diag = new int* [2];
    for (i = 0; i < 2; i++)
        diag[i] = new int[2*n-1];
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2*n-1; j++)
            diag[i][j] = 0;
    checkngofree(desk, diag, 0, 0, n);
    cout << maxamount << endl;
    showdesk(desk, n);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "runtime = " << clock() / 1000.0 << endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
