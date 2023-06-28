#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
const int FPS = 100;
const int SIZE1 = 7;
const int SIZE2 = 24;

void initField(char** field);

void showArray(char** array) {
    int size = _msize(array) / sizeof(array[0]);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int keyboard() {
    if (_kbhit()) // слушатель нажатия на клаву
    {
        switch (_getch()) {
        case 80:
            return 1;
            break;
        case 72:
            return 2;
            break;
        case 75:
            return 3;
            break;
        case 77:
            return 4;
            break;
        }
    }
}

void render(char**& field, int*& player)
{
    for (int i = 0; i < SIZE2; i++)
    {
        for (int j = 0; j < SIZE1; j++)
        {
            field[i][j] = '*';
        }
    }

    field[player[0]][player[1]] = '@';
    system("cls");
    for (int i = 0; i < SIZE2; i++)
    {
        for (int j = 0; j < SIZE1; j++)
        {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

void initField(char** field) {
    for (int i = 0; i < SIZE2; i++) {
        for (int j = 0; j < SIZE1; j++)
            field[i][j] = '*';
    }
}

int main()
{
    //create field
    char** field = new char* [SIZE2];
    for (int i = 0; i < SIZE2; i++) {
        field[i] = new char[SIZE1] {};
    }
    //create player
    int dir = keyboard();
    int* player = new int[2] { 4, 23, 0 };

    initField(field);
    showArray(field);

    //game
    while (true) {

        render(field, player);
        Sleep(FPS);
        keyboard();

    }

}
