#include "game.h"
#include "num.h"






Game::Game()
{
    score = 0;
}
void Game::Show_start()
{
	cout << "************************************************" << endl;
	cout << "********	输入1开始游戏		********" << endl;
	cout << "********	输入0结束游戏		********" << endl;
	cout << "********	wasd控制移动方向 	********" << endl;
	cout << "************************************************" << endl;
	cout << "************************************************" << endl;
    cout << "********        2023.7.19-小奀          ********" << endl;
    cout << "************************************************" << endl;
}

int Game::Win_or_lose()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (square[i][j].number == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}
void Game::Init_move()
{
    
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            square[i][j].can_mix = 0;
        }
    }
    move_or_not = 0;
}
void Game::Move_up()
{
    Game::Init_move();
    for (int j = 1; j <= 4; j++)
    {
        for (int i = 1 + 1; i <= 4; i++)
        {
            while (square[i][j].number != 0 && (square[i - 1][j].number == 0 || (square[i][j].number == square[i - 1][j].number && !square[i - 1][j].can_mix && !square[i][j].can_mix)) && i > 1)
            {

                if (square[i - 1][j].number == 0)
                {
                    square[i - 1][j] = square[i][j];
                    square[i][j].number = 0;
                    move_or_not = 1;
                }
                else if (square[i][j].number == square[i - 1][j].number && !square[i - 1][j].can_mix && !square[i][j].can_mix)
                {
                    square[i - 1][j].number += square[i][j].number;
                    square[i][j].number = 0;
                    score += square[i - 1][j].number;
                    square[i - 1][j].can_mix = 1;
                    move_or_not = 1;
                }
                i--;
            }
        }
    }

}
void Game::Move_down()
{
    Game::Init_move();
    for (int j = 1; j <= 4; j++)
    {
        for (int i = 4 - 1; i > 0; i--)
        {
            while (square[i][j].number != 0 && (square[i + 1][j].number == 0 || (square[i][j].number == square[i + 1][j].number && !square[i + 1][j].can_mix && !square[i][j].can_mix)) && i < 4)
            {

                if (square[i + 1][j].number == 0)
                {
                    square[i + 1][j] = square[i][j];
                    square[i][j].number = 0;
                    move_or_not = 1;
                }
                else if (square[i][j].number == square[i + 1][j].number && !square[i + 1][j].can_mix && !square[i][j].can_mix)
                {
                    square[i + 1][j].number += square[i][j].number;
                    square[i][j].number = 0;
                    score += square[i + 1][j].number;
                    square[i + 1][j].can_mix = 1;
                    move_or_not = 1;
                }
                i++;
            }
        }
    }
}
void Game::Move_right()
{
    Game::Init_move();
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 4-1; j > 0; j--)
        {
            while (square[i][j].number != 0 && (square[i][j + 1].number == 0 || (square[i][j].number == square[i][j + 1].number && !square[i][j + 1].can_mix && !square[i][j].can_mix)) && j < 4)
            {

                if (square[i][j + 1].number == 0)
                {
                    square[i][j + 1] = square[i][j];
                    square[i][j].number = 0;
                    move_or_not = 1;
                }
                else if (square[i][j].number == square[i][j + 1].number && !square[i][j + 1].can_mix && !square[i][j].can_mix)
                {
                    square[i][j + 1].number += square[i][j].number;
                    square[i][j].number = 0;
                    score += square[i][j + 1].number;
                    square[i][j + 1].can_mix = 1;
                    move_or_not = 1;
                }
                j++;
            }
        }
    }
}
void Game::Move_left()
{
    Game::Init_move();
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1 + 1; j <= 4; j++)
        {
            while (square[i][j].number != 0 && (square[i][j-1].number == 0 || (square[i][j].number == square[i][j-1].number && !square[i][j-1].can_mix && !square[i][j].can_mix)) && j > 1)
            {

                if (square[i][j-1].number == 0)
                {
                    square[i][j-1] = square[i][j];
                    square[i][j].number = 0;
                    move_or_not = 1;
                }
                else if (square[i][j].number == square[i][j-1].number && !square[i][j-1].can_mix && !square[i][j].can_mix)
                {
                    square[i][j-1].number += square[i][j].number;
                    square[i][j].number = 0;
                    score += square[i][j-1].number;
                    square[i][j-1].can_mix = 1;
                    move_or_not = 1;
                }
                j--;
            }
        }
    }
}

void Game::Summon_new()
{
    srand((unsigned int)time(NULL));
    int ret1 = rand() % 4 + 1;//生成1~4的随机数
    int ret2 = rand() % 4 + 1;//生成1~4的随机数
    while (square[ret1][ret2].number != 0)
    {
        ret1 = rand() % 4 + 1;//生成1~4的随机数
        ret2 = rand() % 4 + 1;//生成1~4的随机数
    }
    square[ret1][ret2].number = (rand() % 2 + 1) * 2;
}

void Game::Update()
{
    system("cls");
    /*printf("|----|----|----|----|\n");
    printf("|%4d|%4d|%4d|%4d|\n", square[1][1].number, square[1][2].number, square[1][3].number, square[1][4].number);
    printf("|----|----|----|----|\n");
    printf("|%4d|%4d|%4d|%4d|\n", square[2][1].number, square[2][2].number, square[2][3].number, square[2][4].number);
    printf("|----|----|----|----|\n");
    printf("|%4d|%4d|%4d|%4d|\n", square[3][1].number, square[3][2].number, square[3][3].number, square[3][4].number);
    printf("|----|----|----|----|\n");
    printf("|%4d|%4d|%4d|%4d|\n", square[4][1].number, square[4][2].number, square[4][3].number, square[4][4].number);
    printf("|----|----|----|----|\n");*/
    printf("|----|----|----|----|\n");
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if(square[i][j].number!=0)
            {
                printf("|%4d", square[i][j].number);
            }
            else
            {
                printf("|    ");
            }
        }
        printf("|\n");
        printf("|----|----|----|----|\n");
    }
    printf("分数：%d", score);

}
Game::~Game()
{

}