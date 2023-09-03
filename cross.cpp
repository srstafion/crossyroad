#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
int width = 9;
int height = 24;

int spawnCar(int* carlanes, int** car) {
    for (int i = 0; i < height; i++) {
        if (carlanes[i] == 1) {
            if (rand() % 8 == 1) {
                car[i][0] = 1;
                return car[i][0];
            }
        }
    }
}

void render(char**& field, int* carlanes, int** car)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (carlanes[i] == 1) field[i][j] = '#';
            else field[i][j] = '.';
            field[0][j] = '=';
        }
    }
    for (int i = 0; i < height; i++) {
        if (car[i][0] == 1) field[i][0] = 'n';
    }
    for (int i = 0; i < height; i++) {
        if (carlanes[i] == 1)
        {
            for (int j = 0; j < width; j++) {
                if (car[i][j] == 1)field[i][j] = 'n';
                swap(car[i][j], car[i][j++]);
            }
        }
    }
    for (int i = 0; i < height; i++) {
        if (carlanes[i] == 1)
        {
            for (int j = 0; j < width; j++) {
                if (car[i][j] == 1) field[i][j] = 'n';
            }
        }
    }
    system("cls");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}
void initField(char** field) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            field[i][j] = '.';
    }
} 
int main() 
{
    int carlanes[24];
    for (int i = 1; i < height - 2; i++) {
        carlanes[i] = rand() % 2;
    }
    int** car = new int* [24] {};
    for (int i = 0; i < 24; i++) {
        car[i] = new int[width] {};
    }
    char** field = new char* [height];
    for (int i = 0; i < height; i++) {
        field[i] = new char[width] {};
    }
    while (true) {
        render(field, carlanes, car);
        spawnCar(carlanes, car);
        Sleep(500);
    }
}