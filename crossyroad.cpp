#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
using namespace std; 
const int FPS = 100;
const int WIDTH = 9;
const int EZHEIGHT = 12;
const int MDHEIGHT = 18;
const int HDHEIGHT = 24;
bool gameGoing = 0;
int gamemode;

void initField(char** field);

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
    cin >> a;
    if (a == 1) {

        return 1;
        system("cls");
    }
    else if (a == 2) {

    }
}

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

int spawnCar(int& gamemode, int* carlanes, int** car) {
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    for (int i = 0; i < height; i++) {
        if (carlanes[i] == 1) {
            if (rand() % 8 == 1) {
                car[i][0] = 1;
                return car[i][0];
            }
        }
    }
}

void render(char**& field, int*& player, int& gamemode, int* carlanes, int** car)
{
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (carlanes[i] == 1) field[i][j] = '#';
            else field[i][j] = '.';
            field[0][j] = '=';
        }
    }
    field[player[1]][player[0]] = '@';
    for (int i = 0; i < height; i++) {
        if (car[i][0] == 1) field[i][0] = 'n';
    }
    for (int i = 0; i < height; i++) {
        if (carlanes[i] == 1)
        {
            for (int j = 0; j < WIDTH; j++) {
                if (car[i][j] == 1)field[i][j] = 'n';
                //swap(car[i][j], car[i][j++]);
            }
        }
    }
    system("cls");
    for (int i = 0; i < height; i++)
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
void updatePlayer(int*& player, int& dir) {
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
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
        if (player[1] < height - 1) {
            player[1]++;
        }
        break;
    }
}
//status: DONE

void initField(char** field) {
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < WIDTH; j++)
            field[i][j] = '.';
    }
}

bool winCheck(int*& player) {
    if (player[1] == 0) {
        return 1;
    }
    else return 0;
}

//int winMenu(bool victory) {
//    if (victory == 1) {
//        int a;
//        system("cls");
//        cout << "\\_)_        \\  ^   / o  __ | " << endl;
//        cout << " / (_) (_(    \\/ \\/ /  / / o " << endl;
//        cout << "Would you like to play again? (1 - Play Again, 2 - Menu)";
//        cin >> a;
//        if (a == 1) {
//            system("cls");
//            gameGoing = 1;
//            victory = 0;
//        }
//        else if (a == 2) {
//            system("cls");
//            menu(gameGoing, gamemode);
//        }
//    }
//}

int main()
{
    srand(time(NULL));
    gameGoing = menu(gameGoing, gamemode);
    system("cls");
    int b;
    cout << "Select difficulty from 1 to 3 (1 - Easy, 2 - Medium, 3 - Hard) Type anything else to go back." << endl;
    cin >> b;
    if (b == 1) {
        gamemode = 1;
    }
    else if (b == 2) {
        gamemode = 2;
    }
    else if (b == 3) {
        gamemode = 3;
    }
    //1 EASY
    //2 MEDIUM
    //3 HARD
    int height;
    if (gamemode == 1) height = EZHEIGHT;
    else if (gamemode == 2) height = MDHEIGHT;
    else if (gamemode == 3) height = HDHEIGHT;
    int carlanes[24];
    for (int i = 1; i < height - 2; i++) {
        carlanes[i] = rand() % 2;
    }
    int** car = new int* [24] {};
    for (int i = 0; i < 24; i++) {
        car[i] = new int[WIDTH] {};
    }

    //create field
    char** field = new char* [height];
    for (int i = 0; i < height; i++) {
        field[i] = new char[WIDTH] {};
    }
    //create player
    //1 IS DOWN
    //2 IS UP
    //3 IS LEFT
    //4 IS RIGHT
    int* player = new int[3] { (WIDTH / 2), (height - 1), 0 };

    initField(field);
    bool victory = 0;
    //game
    while (gameGoing == 1 && victory == 0) {
        int dir = keyboard();
        victory = winCheck(player);
        updatePlayer(player, dir);
        spawnCar(gamemode, carlanes, car);
        render(field, player, gamemode, carlanes, car);
        Sleep(FPS);
        keyboard();
    }
}
