#pragma once
#include<string>
#include<iostream>
#include <windows.h>
#include<conio.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cstdint>
using namespace std;
#define DICH_X 5
#define DICH_Y 5
extern void gotoxy(int, int);
extern void goto_c(char, int, int);
extern void goto_s(string, int, int);
extern int random(int, int);
extern uint64_t timeSinceEpochMillisec();
