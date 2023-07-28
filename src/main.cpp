#include<iostream>
#include<conio.h>
#include<ctime>

#include "Snake.hpp"
#include "SnakeFunctions.hpp"
#include "Food.hpp"
#include "FoodFunctions.hpp"

using namespace std;

#define HEIGHT 25
#define WIDTH 50


Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food food;

int score;


void layout()
{
    COORD snakePos = snake.getPos();
    COORD foodPos = food.getPos();

    vector<COORD> snakeBody = snake.getBody();

    cout << "SCORE : " << score << endl;

    for(int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t#";
        for(int j = 0; j < WIDTH - 2; j++)
        {
            if(i == 0 || i == HEIGHT-1) cout << '#';

            else if(i == snakePos.Y && j+1 == snakePos.X){
                cout << '0';
            }
            else if(i == foodPos.Y && j+1 == foodPos.X){
                 cout << '@';
            }

            else
            {
                bool isBodyPart = false;
                for(int x = 0; x < snakeBody.size()-1; x++)
                {
                    if(i == snakeBody[x].Y && j+1 == snakeBody[x].X)
                    {
                        cout << 'o';
                        isBodyPart = true;
                        break;
                    }
                }

                if(!isBodyPart) {
                    cout << ' ';
                }
            }
        }
        cout << "#\n";
    }
}


int main()
{
    score = 0;
    srand(time(NULL));

    food.genFood();

    bool game_over = false;

    while(!game_over)
    {
        layout();

        if(kbhit())
        {
            switch(getch())
            {
                case 'w': snake.changeDir('w'); break;
                case 'a': snake.changeDir('a'); break;
                case 's': snake.changeDir('s'); break;
                case 'd': snake.changeDir('d'); break;
            }
        }

        if(snake.hit()) {
            game_over = true;
        }

        if(snake.eaten(food.getPos()))
        {
            food.genFood();
            snake.grow();
            score += 5;
        }

        snake.moveSnake();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
}
