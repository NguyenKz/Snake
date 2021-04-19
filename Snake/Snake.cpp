#include "Snake.h"
#include "Function.h"
Snake::Snake()
{
	this->reset();
}

bool Snake::is_die()
{
	return this->_is_die;
}

bool Snake::eat_food(Food food)
{
	/*
	* An moi.
	*/
	return (this->body[0][0] == food.get_x() && this->body[1][0] == food.get_y());
}

void Snake::update(Food& food, Map& map)
{
    this->tail_old[0] = this->body[0][this->len - 1];
    this->tail_old[1] = this->body[1][this->len - 1];

    for (int i = len - 1; i > 0; i--)
    {
        this->body[0][i] = this->body[0][i - 1];
        this->body[1][i] = this->body[1][i - 1];

    }
    switch (this->_vector)
    {
    case MOVE_UP://len
		this->body[1][0]--;
        break;
    case MOVE_DOWN: //xuong
        this->body[1][0]++;
        break;
    case MOVE_LEFT: // trai
        this->body[0][0]--;
        break;
    case MOVE_RIGHT: // phai
        this->body[0][0]++;
        break;
    default:
        break;
    }

    if (this->body[1][0] < 0) {
        this->body[1][0] = map.get_h();
    }
    else if (this->body[1][0] > map.get_h()) {
        this->body[1][0] = 0;
    }

    if (this->body[0][0] < 0) {
        this->body[0][0] = map.get_w();
    }
    else if (this->body[0][0] > map.get_w()) {
        this->body[0][0] = 0;
    }
	/*
	* An duoi minh ==> chet
	*/
	for (int i = 1; i < len; i++)
	{
		if (this->body[0][i] == this->body[0][0] && this->body[1][i] == this->body[1][0]) {
			this->_is_die = true;
			return;
		}
	}
	if (this->eat_food(food)) {
		food.reset(map);
		map.add_point(1);
		this->len++;
		if (this->len > MAX_LEN) {
			this->len = MAX_LEN;
		}
	}
}

void Snake::draw()
{
	/*
	* Ve
	*/
	goto_c(' ', this->tail_old[0], this->tail_old[1]);
	goto_c('#', this->body[0][1], this->body[1][1]);
	goto_c('O', this->body[0][0], this->body[1][0]);
}

void Snake::reset()
{
	this->_is_die = false;
	len = MIN_LEN;
	for (int i = 0; i < len; i++)
	{
		body[0][i] = START_X;
		body[1][i] = START_Y;

	}
}

void Snake::move_left()
{
	if (this->_vector != MOVE_RIGHT) {
		this->_vector = MOVE_LEFT;
	}
}
void Snake::move_right()
{
	if (this->_vector != MOVE_LEFT) {
		this->_vector = MOVE_RIGHT;
	}
}
void Snake::move_up()
{
	if (this->_vector != MOVE_DOWN) {
		this->_vector = MOVE_UP;
	}
}
void Snake::move_down()
{
	if (this->_vector != MOVE_UP) {
		this->_vector = MOVE_DOWN;
	}
}
