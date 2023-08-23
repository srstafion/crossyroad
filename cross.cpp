#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
int width = 9;
int height = 24;

//X1 <   X2 >   Y1 ^   Y2 V
int* player = new int[2] {(width/2), 24};

bool GOver;

bool carPos;
void carLane(bool carPos, int width) {
    for (int i = 0; i <= width; i++) {
        carPos = false;
    }
}
void MoveCar(bool carPos) {
    
}
void Draw() {

}
void KeyIn() {

}


int main()
{
    srand(time(NULL));
    carLane(carPos, 9);
    cout << endl;
    for (int i = 0; i < 9; i++) {
        if (i == true) cout << '#';
        else cout << '_';
    }
    MoveCar(carPos); 
    cout << endl;
    for (int i = 0; i < 9; i++) {
        if (i == true) cout << '#';
        else cout << '_';
    }
    while (!GOver) {
        Draw();
        KeyIn();
    }
}