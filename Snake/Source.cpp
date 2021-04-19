#include<iostream>
#include <windows.h>
#include<conio.h>
#include "Snake.h"
#include "Food.h"
#include "Map.h"
#include "Function.h"
using namespace std;
#define SPEED_GAME 40
int main() {
    bool is_running = true;
    Map map(20,20);
    Snake snake;
    Food food(map);
    uint64_t last_time_check = timeSinceEpochMillisec();
    while (is_running) {
        char key = 0;
        if (_kbhit()) {
            key = _getch();
        }
        switch (key)
        {
        case 27: {// ESC
            is_running = false;
            break;
        }
        case 75:
        case 'a':// trai
        case 'A':
            snake.move_left();
            break;
        case 77:
        case 'd':// phai
        case 'D':
            snake.move_right();
            break;
        case 72:
        case 'w':// len
        case 'W':
            snake.move_up();
            break;
        case 80:
        case 's':// xuong
        case 'S':
            snake.move_down();
            break;
        default:
            break;
        }

        if (timeSinceEpochMillisec() - last_time_check > SPEED_GAME) {

            snake.update(food, map);
            /*
            * Ve
            */
            snake.draw();
            food.draw();
            map.draw();
            last_time_check = timeSinceEpochMillisec();
        }
     
       
    }
    cout << "\n=============== DUNG ============\n";
	return 0;
}
