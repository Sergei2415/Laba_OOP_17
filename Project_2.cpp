#include <iostream>
#include <algorithm>
#include "Plenty.h"
using namespace std;



int main()
{
    setlocale(LC_ALL, "Russian");
    Plenty pl_1;

    pl_1.add_elem(2);
    pl_1.add_elem(3);
    pl_1.add_elem(2);
    pl_1.add_elem(6);
    pl_1.add_elem(7);

    pl_1.find_elem(3);

    int* plenty_1 = new int[5];
    pl_1.initialization_plenty(plenty_1, pl_1.get_data(), 5);

    //for (int i = 0; i < 5; i++)
       // cout << plenty_1[i] << " ";
    //
    Plenty pl_2(7);

    pl_2.add_elem(6);
    pl_2.add_elem(7);
    pl_2.add_elem(8);
    pl_2.add_elem(9);
    pl_2.add_elem(10);
    pl_2.add_elem(11);
    pl_2.add_elem(9);


    pl_2.find_elem(7);

    cout << pl_2 << endl;
    //cin >> pl_2;
    //cout << pl_2 << endl;


    Plenty pl_3 = pl_2;
    cout << pl_3 << endl;

    Plenty pl_4, pl_5, pl_6, pl_7, pl_8, pl_9, pl_10, pl_11;
    pl_4 = pl_2;
    cout << pl_4 << endl;

    cout << "Начало сложения pl_1 + pl_2" << endl;
    cout << pl_1 << endl;
    cout << pl_2 << endl;
    pl_5 = pl_1 + pl_2;
    cout << "Вывод" << endl;
    cout << pl_5 << endl;

    cout << "Начало умножения pl_1 * pl_2" << endl;
    cout << pl_1 << endl;
    cout << pl_2 << endl;
    pl_6 = pl_1 * pl_2;
    cout << "Вывод" << endl;
    cout << pl_6 << endl;

    cout << "Начало вычитания pl_1 - pl_2" << endl;
    cout << pl_1 << endl;
    cout << pl_2 << endl;
    pl_7 = pl_1 - pl_2;
    cout << "Вывод" << endl;
    cout << pl_7 << endl;

    cout << "Начало сложения с числом pl_1 + 1" << endl;
    cout << pl_1 << endl;
    cout << 1 << endl;
    pl_8 = pl_1 + 1;
    cout << "Вывод" << endl;
    cout << pl_8 << endl;

    pl_9 = pl_2;
    cout << "Начало сложения pl_9 += pl_1" << endl;
    cout << pl_9 << endl;
    cout << pl_1 << endl;
    pl_9 += pl_1;
    cout << "Вывод" << endl;
    cout << pl_9 << endl;

    pl_10 = pl_2;
    cout << "Начало умножения pl_10 *= pl_1" << endl;
    cout << pl_10 << endl;
    cout << pl_1 << endl;
    pl_10 *= pl_1;
    cout << "Вывод" << endl;
    cout << pl_10 << endl;

    pl_11 = pl_2;
    cout << "Начало вычитания pl_11 -= pl_1" << endl;
    cout << pl_11 << endl;
    cout << pl_1 << endl;
    pl_11 -= pl_1;
    cout << "Вывод" << endl;
    cout << pl_11 << endl;

    cout << "Начало сравнения pl_3 == pl_2" << endl;
    cout << pl_3 << endl;
    cout << pl_2 << endl;
    if (pl_3 == pl_2) 
        cout << "Условие выполняется." << endl;
    else
        cout << "Условие не выполняется." << endl;
    cout << "Начало сравнения pl_11 == pl_2" << endl;
    cout << pl_11 << endl;
    cout << pl_2 << endl;
    if (pl_11 == pl_2)
        cout << "Условие выполняется." << endl;
    else
        cout << "Условие не выполняется." << endl;

    cout << "Начало сравнения pl_3 != pl_2" << endl;
    cout << pl_3 << endl;
    cout << pl_2 << endl;
    if (pl_3 != pl_2)
        cout << "Условие выполняется." << endl;
    else
        cout << "Условие не выполняется." << endl;
    cout << "Начало сравнения pl_11 != pl_2" << endl;
    cout << pl_11 << endl;
    cout << pl_2 << endl;
    if (pl_11 != pl_2)
        cout << "Условие выполняется." << endl;
    else
        cout << "Условие не выполняется." << endl;

}
