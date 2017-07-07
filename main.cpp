//char(21)
//char(210) pi sign

#include <iostream>
#include <windows.h>
#include <conio.h>

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27

using namespace std;

//Function Prototype
void drawMaze ();
void gotoXY (int , int );
void Movement();

//Global Variables
//char inputKey = {0};
int inputKey = 0;
int mapArrayOne [17][33] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,0,0,0,1,1,1,1,0,0,1},
    {1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1},
    {1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
    {1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2}
};

int main()
{
    drawMaze();

    Movement();

    system("Pause");
    return 0;
}

void drawMaze()
{
    for(int i = 0; i < 17; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            switch(mapArrayOne[i][j])
            {
            case 0:
                cout<<" ";
                break;
            case 1:
                cout<<char(219);
                break;
            case 2:
                cout<<" ";
                break;
            default :
                cout<<" ";
            }
        }
        cout<<" "<<endl;
    }
}

void gotoXY (int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Movement()
{
    int x = 1, y = 1;
    int xBefore = 1, yBefore = 1;
    while(true)
    {
        gotoXY(xBefore,yBefore);
        cout<<" ";

        gotoXY(x,y);
        cout<<char(1);  //Fun Face
        xBefore = x;
        yBefore = y;
        inputKey = getch();

        if(inputKey == 'w' || inputKey == 'W' ||  inputKey == KB_UP) //Go To UP
            y -= 1;
        else if(inputKey == 's' || inputKey == 'S' || inputKey == KB_DOWN) //Go To Down
            y += 1;
        else if(inputKey == 'a' || inputKey == 'A' || inputKey == KB_LEFT) //Go To Left
            x -= 1;
        else if(inputKey == 'd' || inputKey == 'D' || inputKey == KB_RIGHT) //Go To Right
            x += 1;

        if (mapArrayOne[y][x] == 1)
        {
            x = xBefore;
            y = yBefore;
        }
        else if(mapArrayOne[y][x] == 2)
        {
            x = xBefore;
            y = yBefore;
            cout<<endl<<char(2);
            cout<<"\tCongratulations"<<endl;
            break;
        }
    }
}
