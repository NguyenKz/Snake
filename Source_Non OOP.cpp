#include<iostream>
#include <windows.h>
#include<conio.h>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
#define HUONG_LEN 0
#define HUONG_XUONG 1
#define HUONG_TRAI 2
#define HUONG_PHAI 3

#define DICH_X 5
#define DICH_Y 5
void gotoxy(int, int);
void goto_c(char, int, int);
void goto_s(string, int, int);
/*
random(min,max)
*/
int random(int, int);
int main() {
 /*   gotoxy(10, 10);
	cout << "Hahah\n";*/
    bool is_running = true;
    const int max_len = 14;
    int len = 3;
    int *x = new int[max_len];
    int* y = new int[max_len];
    
    int x_ban_dau = 10;
    int y_ban_dau = 10;

    for (int i = 0; i < len; i++)
    {
        x[i] =x_ban_dau;
        y[i] =y_ban_dau;
    }

    int x_old = x[len - 1];
    int y_old = y[len - 1];

    int food_x = random(0,20);
    int food_y = random(0,20);

    int point_game = 0;

    /*
    * 0: Len
    * 1: xuong
    * 2: trai
    * 3: phai
    * 
    */
    int vector_game = 0;

    for (int i = 0; i < 23; i++)
    {
        goto_c('|', -1, i - 1);
        goto_c('|', 21, i - 1);
    }
    for (int i = 0; i < 23; i++)
    {
        goto_c('_',i-1, -1);
        goto_c('-',i-1, 21);
    }

    goto_s("Diem: " + to_string(point_game)+"   ", 24, 2);
    while (is_running) {
        char key = 0;
        if (_kbhit()) {
            key = _getch();
            //cout << "Key: "<<key<<"  val: "<<(int)key<<endl ;
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
            if (vector_game != HUONG_PHAI) {
                vector_game = HUONG_TRAI;
            }
            break;
        case 77:
        case 'd':// phai
        case 'D':
            if (vector_game != HUONG_TRAI) {
                vector_game = HUONG_PHAI;
            }
            break;
        case 72:
        case 'w':// len
        case 'W':
            if (vector_game != HUONG_XUONG) {
                vector_game = HUONG_LEN;
            }
            break;
        case 80:
        case 's':// xuong
        case 'S':
            if (vector_game != HUONG_LEN) {
                vector_game = HUONG_XUONG;
            }
            break;
        default:
            break;
        }

        switch (vector_game)
        {
        case HUONG_LEN://len
            x_old = x[len - 1];
            y_old = y[len - 1];

            for (int i = len - 1; i > 0; i--)
            {
                x[i] = x[i - 1];
                y[i] = y[i - 1];

            }

            y[0]--;
            break;
        case HUONG_XUONG: //xuong
            x_old = x[len - 1];
            y_old = y[len - 1];
            for (int i = len - 1; i > 0; i--)
            {
                x[i] = x[i - 1];
                y[i] = y[i - 1];

            }

            y[0]++;
            break;
        case HUONG_TRAI: // trai
            x_old = x[len - 1];
            y_old = y[len - 1];

            for (int i = len - 1; i > 0; i--)
            {
                x[i] = x[i - 1];
                y[i] = y[i - 1];

            }

            x[0]--;
            break;
        case HUONG_PHAI: // phai
            x_old = x[len - 1];
            y_old = y[len - 1];
            for (int i = len - 1; i > 0; i--)
            {
                x[i] = x[i - 1];
                y[i] = y[i - 1];

            }

            x[0]++;
            break;
        default:
            break;
        }

        if (y[0] < 0) {
            y[0] = 20;
        }
        else if (y[0] > 20) {
            y[0] = 0;
        }
        if (x[0] < 0) {
            x[0] = 20;
        }
        else if (x[0] > 20) {
            x[0] = 0; 
        }
        /*
        * An duoi minh ==> chet
        */
        for (int i = 1; i <len ; i++)
        {
            if (x[i] == x[0] && y[i] == y[0]) {
                is_running = false;
                cout << "Ban thua";
                break;
            }
        }
        /*
        * An moi.
        */
        if (x[0] == food_x && y[0] == food_y) {
            food_x = random(0, 20);
            food_y = random(0, 20);
            len++;
            if (len > max_len) {
                len = max_len;
            }
            point_game++;
            goto_s("Diem: " + to_string(point_game) + "   ", 24, 2);
           
            
        }

        /*
        * Ve
        */
        goto_c(' ', x_old, y_old);
        goto_c('#', x[1], y[1]);
        goto_c('O', x[0], y[0]);
        goto_c('E', food_x, food_y);

        Sleep(100);
   
        goto_s("Huong: "+to_string(vector_game),24, 1);
      
       
    }
    cout << "\n=============== DUNG ============\n";
	return 0;
}

int random(int min, int max) {
    srand(time(NULL));
    return rand() % (max-min + 1) + min;
}
void goto_s(string s, int x, int y) {
    gotoxy(x, y);
    cout << s;
}
void goto_c(char c, int x, int y) {
    gotoxy(x, y);
    cout << c;
}


void gotoxy(int x, int y)
{
    x = x * 2;
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x+DICH_X, y+DICH_Y };
    SetConsoleCursorPosition(h, c);
}
