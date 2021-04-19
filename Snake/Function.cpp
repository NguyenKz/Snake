#include "Function.h"

int random(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}
uint64_t timeSinceEpochMillisec() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
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
    COORD c = { x + DICH_X, y + DICH_Y };
    SetConsoleCursorPosition(h, c);
}
