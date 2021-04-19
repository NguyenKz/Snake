#include "Map.h"
#include"Function.h"
Map::Map(int w, int h)
{
    this->size[0] = w;
    this->size[1] = h;
    this->point = 0;
    this->update_point = true;
    this->update_round = true;
}
void Map::draw()
{
    if (this->update_round) {
        for (int i = 0; i < this->get_h() + 3; i++)
        {
            goto_c('|', -1, i - 1);
            goto_c('|', this->get_h() + 1, i - 1);
        }
        for (int i = 0; i < this->get_w() + 3; i++)
        {
            goto_c('_', i - 1, -1);
            goto_c('-', i - 1, this->get_w() + 1);
        }
        this->update_round = false;
    }

  if (this->update_point) {
      goto_s("Diem: " + to_string(this->point), this->get_w() + 4, 1);
      this->update_point = false;
  }

}

int Map::get_w()
{
    return this->size[0];
}

int Map::get_h()
{
    return this->size[1];
}

void Map::add_point(int point)
{
    this->update_point = true;
    this->point += point;
}
