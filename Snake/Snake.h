#pragma once
#include"Food.h"
#include "Map.h"
#define MAX_LEN 20
#define MIN_LEN 4
#define START_X 10
#define START_Y 10

#define MOVE_UP 0
#define MOVE_DOWN 1
#define MOVE_LEFT 2
#define MOVE_RIGHT 3

class Snake
{
private:
	int len;
	/*
	* body[0][i] = x[i]
	* body[1][i] = y[i]
	*/
	int body[2][MAX_LEN];
	int tail_old[2];
	bool _is_die;
	int _vector;

public:
	Snake();
	bool is_die();
	bool eat_food(Food);
	void update(Food&,Map&);
	void draw();
	void reset();
	void move_left();
	void move_right();
	void move_up();
	void move_down();
};

