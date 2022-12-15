#include <iostream>
#include <conio.h>
#include <windows.h>
#include<fstream>
using namespace std;
bool gameOver;
const int width = 15;
const int height = 15;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int Tail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };   
// - ������������
eDirection dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
 // ���� ��� ���� ��� ����� ������ �� ������
    fruitX = rand() % width;
    fruitY = rand() % height;
 // ����� ������ ������� ������ 
    score = 0;
 // ����� ���� � ������ ����
}
void Draw()
{
    system("cls");
 // ����� ������� *Draw* ���� ����(clear)
    for (int i = 0; i < width + 2; i++)
        cout << "_";
    cout << endl;
 // ������ ���    
 // +2 ����� �� ��� �� ���� ����� 

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            if (k == 0)
 // ���� k = 0 �� ����� ����������� �� �������
                cout << "|";
            if (i == y && k == x)
                cout << "o";
            else if (i == fruitY && k == fruitX)
                cout << "X";
            else
            {
                bool print = false;
                for (int k = 0; k < Tail; k++)
                {
                    if (tailX[k] == k && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }


            if (k == width - 1)
/* -1 ����� �� �� �� ���������� � 0 � ��� �������� ��������� ����� ������� ������ 1 */
                cout << "|";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;
    cout << "Score:" << score << endl;
}
void Input()
{
    if (_kbhit())
// (�����)������� ��� ����� ��� ���� ���������� ����� �� ������ �� ����
    {
        switch (_getch())
// ������ ����� ������� (����) �� ����� �������� ��� ������ ����� ����������
        {
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
        }
    }
}
void Logic()
{
    switch (dir)
    {
/* ������� �� ��� ���
* ��� �������� � 40-50 ������� � ����� �� �� ����� �������� */
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
// ������� �� ������� ����
    if (x > width || x < 0 || y > height || y < 0)
            gameOver = true;
// ���� �� ���������� �� ����� ������� �� �� ������

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}
int main()
{
// ������� ��� ���� � ����� � ����������
    ofstream output;
    output.open("test1.txt");
    output << "Smth funny.";
    output.close();

    Setup();
    while (!gameOver)
    {
        Draw();
 // ���� ����� �� �� �� ������� ���� ������
        Input();
        Logic();
        Sleep(10); //sleep(10);
    }
    return 0;
}