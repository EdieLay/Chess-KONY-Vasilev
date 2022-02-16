// Vasilev SiAKOD Chess Koni.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int c = 0;
vector<pair<int, int>> moves;
vector<pair<int, int>>::iterator p;

void findngofree(int** A, int i, int j, int n)
{
    c++;
    //cout << c << endl;
    A[i][j] = c;
    moves.push_back(make_pair(i, j));
    p = moves.end() - 1;
    if (((*p).first - 2 >= 0) && ((*p).second - 1 >= 0) && (A[(*p).first - 2][(*p).second - 1] == 0))
    {
        findngofree(A, (*p).first - 2, (*p).second - 1, n);
        if (c != n * n)
        {
            c--;
            A[(*p).first][(*p).second] = 0;
            p--;
            moves.pop_back();
        }
    }
    if (((*p).first - 2 >= 0) && ((*p).second + 1 < n) && (A[(*p).first - 2][(*p).second + 1] == 0))
    {
        findngofree(A, (*p).first - 2, (*p).second + 1, n);
        if (c != n * n)
        {
            c--;
            A[(*p).first][(*p).second] = 0;
            p--;
            moves.pop_back();
        }
    }
    if (((*p).first - 1 >= 0) && ((*p).second + 2 < n) && (A[(*p).first - 1][(*p).second + 2] == 0))
    {
        findngofree(A, (*p).first - 1, (*p).second + 2, n);
        if (c != n * n)
        {
            c--;
            A[(*p).first][(*p).second] = 0;
            p--;
            moves.pop_back();
        }
    }
    if (((*p).first + 1 < n) && ((*p).second + 2 < n) && (A[(*p).first + 1][(*p).second + 2] == 0))
    {
        findngofree(A, (*p).first + 1, (*p).second + 2, n);
        if (c != n * n)
        {
            c--;
            A[(*p).first][(*p).second] = 0;
            p--;
            moves.pop_back();
        }
    }
    if (((*p).first + 2 < n) && ((*p).second + 1 < n) && (A[(*p).first + 2][(*p).second + 1] == 0))
    {
        findngofree(A, (*p).first + 2, (*p).second + 1, n);
        if (c != n * n)
        {
            c--;
            A[(*p).first][(*p).second] = 0;
            p--;
            moves.pop_back();
        }
    }
    if (((*p).first + 2 < n) && ((*p).second - 1 >= 0) && (A[(*p).first + 2][(*p).second - 1] == 0))
    {
        findngofree(A, (*p).first + 2, (*p).second - 1, n);
        if (c != n * n)
        {
            c--;
            A[(*p).first][(*p).second] = 0;
            p--;
            moves.pop_back();
        }
    }
    if (((*p).first + 1 < n) && ((*p).second - 2 >= 0) && (A[(*p).first + 1][(*p).second - 2] == 0))
    {
        findngofree(A, (*p).first + 1, (*p).second - 2, n);
        if (c != n * n)
        {
            c--;
            A[(*p).first][(*p).second] = 0;
            p--;
            moves.pop_back();
        }
    }
    if (((*p).first - 1 >= 0) && ((*p).second - 2 >= 0) && (A[(*p).first - 1][(*p).second - 2] == 0))
    {
        findngofree(A, (*p).first - 1, (*p).second - 2, n);
        if (c != n * n)
        {
            c--;
            A[(*p).first][(*p).second] = 0;
            p--;
            moves.pop_back();
        }
    }
}

int main()
{
    int n, i, j, k, l;
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
    int** desk = new int* [n];
    for (i = 0; i < n; i++)
        desk[i] = new int[n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            desk[i][j] = 0;
    cout << "Input first coordinate of starting point: ";
    while (1)
    {
        cin >> k;
        if (cin.fail() || k < 1 || k > n)
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Error! Coordinate must be integer number from 1 to " << n << "." << endl;
        }
        else break;
    }
    cout << "Input second coordinate of starting point: ";
    while (1)
    {
        cin >> l;
        if (cin.fail() || l < 1 || l > n)
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Error! Coordinate must be integer number from 1 to " << n << "." << endl;
        }
        else break;
    }
    findngofree(desk, k - 1, l - 1, n);
    for (i = 0; i < n; i++)
    {
        cout << endl;
        for (j = 0; j < n; j++)
            cout << desk[i][j] << "\t";
    }
    cout << endl;
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
