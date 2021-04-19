#pragma once

class Map
{
private:
	int size[2];
	int point;
	bool update_point;
	bool update_round;
public:
	Map(int w, int h);
	void draw();
	int get_w();
	int get_h();
	void add_point(int point);
};

