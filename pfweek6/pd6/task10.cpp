#include <iostream>
#include <windows.h>
using namespace std;

void printmaze();
void gotoxy(int x, int y);
void printpacman(int x, int y);
void printghost(int x, int y);
char getCharAtxy(short int x, short int y);
void clear(int x, int y, char previous);
void erase(int x, int y);

main()
{
    int x=2;
    int y=2;
    string direction = "right";
    char previous = ' ';
    system ("cls");

    printmaze();
    printghost(x,y);
    while(1)
    {
        Sleep (200);
        int score=0 ;
                if (GetAsyncKeyState(VK_LEFT))
        {   
            char nextlocation = getCharAtxy(x-1 , y);
            if (nextlocation == ' ' || nextlocation == '.')
            {
                erase(x, y);
                x = x - 1;
                printpacman(x, y);
            }
            if(nextlocation == '.')
            {   gotoxy(25,15);
                cout<< "score = " << score+1;
            } 
        }

        if (GetAsyncKeyState(VK_RIGHT))
        {
            char nextlocation = getCharAtxy(x +1, y);
            if (nextlocation == ' ' || nextlocation == '.')
            {
                erase(x, y);
                x = x + 1;
                printpacman(x, y);
            }
            if(nextlocation == '.')
            {   gotoxy(25,15);
                cout<< "score = " << score;
            } 
        }

        if (GetAsyncKeyState(VK_UP))
        {
            char nextlocation = getCharAtxy(x, y-1);
            if (nextlocation == ' ' || nextlocation == '.')
            {
                erase(x, y);
                y = y - 1;
                printpacman(x, y);
            }
            if(nextlocation == '.')
            {   gotoxy(25,15);
                cout<< "score = " << score;
            }
        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            char nextlocation = getCharAtxy(x, y+1 );
            if (nextlocation == ' ' || nextlocation == '.')
            {
                erase(x, y);
                y = y + 1;
                printpacman(x, y);
            }
            if(nextlocation == '.')
            {   gotoxy(25,15);
                cout<< "score = " << score;
            }  
        }  
    }
}    
void printmaze()
{
    cout << "###########################" << endl;
    cout << "##                       ##" << endl;
    cout << "##              .........##" << endl;
    cout << "##                       ##" << endl;
    cout << "##                       ##" << endl;
    cout << "##                       ##" << endl;
    cout << "##                       ##" << endl;
    cout << "## .                     ##" << endl;
    cout << "## .                     ##" << endl;
    cout << "## .                     ##" << endl;
    cout << "## .                     ##" << endl;
    cout << "## .                     ##" << endl;
    cout << "###########################" << endl;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void clear(int x, int y, char previous)
{
    gotoxy(x,y);
    cout<< previous;
}
void printpacman(int x, int y)
{
    gotoxy(x,y);
    cout<< "P";
    Sleep(100);
}
void erase(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void printghost(int x, int y)
{
    gotoxy(x,y);
    cout<<"G";
}