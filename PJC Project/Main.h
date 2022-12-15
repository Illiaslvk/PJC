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
// - перечисление
eDirection dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
 // ділим для того щоб змійка стояла по центру
    fruitX = rand() % width;
    fruitY = rand() % height;
 // через рандом ставимо фрукти 
    score = 0;
 // общий счёт с начала игры
}
void Draw()
{
    system("cls");
 // очищує функцію *Draw* тоже саме(clear)
    for (int i = 0; i < width + 2; i++)
        cout << "_";
    cout << endl;
 // верхня лінія    
 // +2 через то щоб не було дирок 

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            if (k == 0)
 // якщо k = 0 то збоку появляється ця границя
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
/* -1 через то шо ми стартували з 0 і шоб получити правильне число потрібно відняти 1 */
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
// (кбхіт)функція яка вертає ТРУ якщо користувач нажав на кнопку на клаві
    {
        switch (_getch())
// іменно через функцію (ГЕТЧ) ми можем побачити яку кнопку нажав користувач
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
/* відповідає за сам рух
* йде перевірка з 40-50 строкою і через це ми можем рухатись */
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
// відповідає за границі ігри
    if (x > width || x < 0 || y > height || y < 0)
            gameOver = true;
// якщо ми дотронимся до якоїсь сторони то ми помрем

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}
int main()
{
// створюэ тхт файл в папці з заваданням
    ofstream output;
    output.open("test1.txt");
    output << "Smth funny.";
    output.close();

    Setup();
    while (!gameOver)
    {
        Draw();
 // мигає через то шо ми постійно його малюєм
        Input();
        Logic();
        Sleep(10); //sleep(10);
    }
    return 0;
}