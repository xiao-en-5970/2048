#include<iostream>
#include<string>
#include<conio.h>
#include"game.h"
#include"num.h"


int main()
{
	Game game;
	game.Show_start();
	int choice;
	cout << "请输入你的选择" << endl;
	cin >> choice;
	while (true)
	{
		if (choice == 0)
		{
			cout << "感谢游玩!" << endl;
			exit(0);
		}
		else if (choice == 1)
		{
			system("cls");
			char c;
			game.Summon_new();
			game.Update();
			while (true)
			{
				c = _getch();
				if (c == 'a')
				{
					game.Move_left();
				}
				else if (c == 'd')
				{
					game.Move_right();
				}
				else if (c == 's')
				{
					game.Move_down();
				}
				else if (c == 'w')
				{
					game.Move_up();
				}
				if(game.move_or_not == 1)
				{
					game.Summon_new();
				}
				game.Update();
				if (!game.Win_or_lose())
				{
					system("cls");
					cout << "你输了！" << endl;
					system("pause");
					exit(0);
				}
			}
			
		}
		else
		{
			system("cls");
			game.Show_start();
			cout << "请输入你的选择" << endl;
			cin >> choice;
		}
	}
	return 0;
}