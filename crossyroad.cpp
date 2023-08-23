#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
const int FPS = 100;
const int WIDTH = 9;
const int HEIGHT = 24;

void initField(char** field);

//1 IS DOWN
//2 IS UP
//3 IS LEFT
//4 IS RIGHT
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
//status: DONE

void render(char**& field, int*& player)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (i == 0) field[i][j] = '=';
            else field[i][j] = '*';
        }
    }
    field[player[1]][player[0]] = '@';
    system("cls");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

//1 IS DOWN
//2 IS UP
//3 IS LEFT
//4 IS RIGHT
void updatePlayer(int*& player, int &dir) {
    player[2] = dir;
    switch (player[2]) {
    case 4:
        if (player[0] < WIDTH - 1) {
            player[0]++;
        }
        break;
    case 3:
        if (player[0] > 0) {
            player[0]--;
        }
        break;
    case 2:
        if (player[1] > 0) {
            player[1]--;
        }
        break;
    case 1:
        if (player[1] < HEIGHT - 1) {
            player[1]++;
        }
        break;
    }
}
//status: DONE

void initField(char** field) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            field[i][j] = '*';
    }
}

bool winCheck(int*& player, bool gameGoing) {
    if (player[1] == 0) {
        gameGoing = false;
    }
    else gameGoing = true;
    return gameGoing;
}

bool menu(bool gameGoing, int gamemode) {
    int a;
    system("cls");
    cout << "  _                    __              " << endl;
    cout << " / ` _ _   _  _        )_) _   _   _ ) " << endl;
    cout << "(_. ) (_) (  ( (_(    / ( (_) (_( (_(  " << endl;
    cout << "          _) _)  _)                    " << endl << endl;;
    cout << "Select your action (press the number):" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Highscore" << endl;
    cout << "3. Game Difficulty" << endl;
    cin >> a;
    if (a == 1) {
        return 1;
        system("cls");
    }
    else if (a == 2) {

    }
    else if (a == 3) {
        system("cls");
        int b;
        cout << "Select difficulty from 1 to 3 (1 - Easy, 2 - Medium, 3 - Hard) Type anything else to go back." << endl;
        cout << "Current difficulty: "; 
        if (gamemode == 1) cout << "Easy";
        else if (gamemode == 2) cout << "Medium";
        else if (gamemode == 3) cout << "Hard";
        cout << endl;
        cin >> b;
        if (b == 1) {
            gamemode = 1;
            menu(gameGoing, gamemode);
        }
        else if (b == 2) {
            gamemode = 2;
            menu(gameGoing, gamemode);
        }
        else if (b == 3) {
            gamemode = 3;
            menu(gameGoing, gamemode);
        }
        else menu(gameGoing, gamemode);
    }
}

int main()
{
    //1 EASY
    //2 MEDIUM
    //3 HARD
    int gamemode = 1;

    //create field
    char** field = new char* [HEIGHT];
    for (int i = 0; i < HEIGHT; i++) {
        field[i] = new char[WIDTH] {};
    }
    //create player
    //1 IS DOWN
    //2 IS UP
    //3 IS LEFT
    //4 IS RIGHT
    int* player = new int[3] { (WIDTH/2), 23, 0 };

    initField(field);
    bool gameGoing = false;
    menu(gameGoing, gamemode);
    //game
    while (gameGoing == 1) {
        int dir = keyboard();
        winCheck(player, gameGoing);
        updatePlayer(player, dir);
        render(field, player);
        Sleep(FPS);
        keyboard();
    }

}
