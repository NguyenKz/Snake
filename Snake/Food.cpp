#include "Food.h"
#include"Function.h"

Food::Food(Map map)
{
	this->reset(map);
}

int Food::get_x()
{
	return this->body[0];
}

int Food::get_y()
{
	return this->body[1];
}

void Food::reset(Map map)
{
	this->body[0] = random(0, map.get_w());
	this->body[1] = random(0, map.get_h());
}

void Food::draw()
{
	goto_c('E', this->body[0], this->body[1]);
}
