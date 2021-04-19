#pragma once
#include"Map.h"
class Food
{
private:
	int body[2];
public:
	Food(Map);
	int get_x();
	int get_y();
	void reset(Map);
	void draw();
};

