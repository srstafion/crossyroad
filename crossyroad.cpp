#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
const int FPS = 100;
const int SIZE1 = 7;
const int SIZE2 = 24;

void initField(char** field);

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

void render(char**& field, int*& player, int*& obstacle)
{
    for (int i = 0; i < SIZE2; i++)
    {
        for (int j = 0; j < SIZE1; j++)
        {
            field[i][j] = '*';
        }
    }
    field[player[1]][player[0]] = '@';
    field[obstacle[1]][obstacle[0]] = '-';
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

void updatePlayer(int*& player, int &dir) {
    player[2] = dir;
    switch (player[2]) {
    case 4:
        if (player[1] < SIZE1 - 1) {
            player[1]++;
        }
        break;
    case 3:
        if (player[1] > 0) {
            player[1]--;
        }
        break;
    case 1:
        if (player[0] > 0) {
            player[0]--;
        }
        break;
    case 2:
        if (player[0] < SIZE2 - 1) {
            player[0]++;
        }
        break;
    }
}

void updateObstacle(int*& obstacle) {
    if (obstacle[0] > SIZE1 - 1) obstacle[0]--;
    else if (obstacle[0] == 0) obstacle[0] = SIZE1 - 1;
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
    //1 up 2 down 3 left 4 right 0 stationary
    int dir = keyboard();
    int* player = new int[3] { 3, 23, 0 };

    int* obstacle = new int[2]{ 6, 15 };

    initField(field);

    //game
    while (true) {
        updatePlayer(player, dir);
        updateObstacle(obstacle);
        render(field, player, obstacle);
        Sleep(FPS);
        keyboard();
    }

}
