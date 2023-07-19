#pragma once
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include"num.h"

using namespace std;


class Game
{
public:
	int score;
	int move_or_not;
	Num square[5][5];
	Game();
	void Show_start();

	int Win_or_lose();
	void Init_move();
	void Move_up();
	void Move_down();
	void Move_right();
	void Move_left();
	
	void Summon_new();

	void Update();
	~Game();
};
