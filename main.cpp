/* This is my first simple code :) */

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

bool pause;
bool gameOver;


const int width = 10;
const int height = 10;
int x[50], y[50], len, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, UP, DOWN, RIGHT };
eDirection dir;


void Setup() {
    pause = false;
    gameOver = false;
    dir = STOP;
    len = 1;
    x[0] = width / 2 - 1;
    y[0] = height / 2 - 1;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw() {
    system("cls");
    string s = ""; for (int i = 0; i < width + 1; i++)
        s += "#";
    s += "\n";
    cout << s;
    for (int i = 0; i < width + 1; i++)
        s += "#";
    s += "\n";
    cout << s;
    s = "";
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1)
                s += "#";
            int ok = false;
            for (int k = 0; k < len; k++)
            {
                if (i == y[k] && j == x[k]) ok = true;
            }
            if (ok)
            {
                if (i == y[0] && j == x[0])
                    s += "@";
                else
                    s += "0";
            }
            else if (i == fruitY && j == fruitX)
                s += "F";
            else
                s += " ";
        }
        s += "\n";
    }
    cout << s;
    s = "";
    for (int i = 0; i < width + 1; i++)
        s += "#";
    s += "\n";
    cout << s;
    cout << " Score: " << score << endl;
    cout << " len: " << len << endl;
    for (int k = 0; k < len; k++) {
        cout << "(" << x[k] << ", " << y[k] << ") ";
    }
    cout << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        case 'p':
            pause = true;
            break;
        case 'c':
            pause = false;
            break;
        }
    }

}

void Logic() {
    for (int k = len - 1; k > 0; k--) {
        x[k] = x[k - 1];
        y[k] = y[k - 1];
    }
    switch (dir) {
    case LEFT:
        x[0]--;
        break;
    case RIGHT:
        x[0]++;
        break;
    case UP:
        y[0]--;
        break;
    case DOWN:
        y[0]++;
        break;
    }
    if (x[0] > width || x[0] < 0 || y[0] > height || y[0] < 0)
        gameOver = true;
    cout << "Game over" << gameOver << endl;
    if (x[0] == fruitX && y[0] == fruitY) {
        len++;
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

int main()
{
    srand(time(NULL));
    Setup();
    Draw();
    while (!gameOver) {
        Input();
        if (!pause) {
            Draw();
            Logic();
        }
        Sleep(150);
    }
    return 0;
}
