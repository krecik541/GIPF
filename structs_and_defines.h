#pragma once
#include<string>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#define Aa (char)'a'
#define BOARD_SIZE 2 * game->S + 1
#define BOARD_SIZE1 2 * w->S + 1
#define ZERO (char)'0'
#define GWIAZDKA '*'
#define DASH_INT (char)'-'
#define FLOOR_INT (char)'_'
#define BEFORE_DASH 0
#define AFTER_DASH_CHAR 1
#define AFTER_DASH_INT 2
//roznica pomiedzy kodami ascii wielkiej i malej litery
#define ROZNICA 32 
#define BUF 6
#define BLACK 'B'
#define WHITE 'W'

struct board {
    int nameI;
    char nameC, value;
};

struct Game {
    int S, K, GW, GB;
    int resW, resB;
    char move;
    board** t;
    Game();
    void cpy(Game* a, Game b);
    void clear();
};

void LOAD_GAME_BOARD(Game* game);
int rowOfLengthK(Game* game);


void PRINT_GAME_BOARD(Game* game);


void DO_MOVE(Game* game);
bool ifNeighbor(char x1C, int x1I, char x2C, int x2I, Game* game);
bool ifStartingField(char x1C, int x1I, Game* game);
bool ifDestinationField(char x2C, int x2I, Game* game);
bool FullRow(char x1C, int x1I, char x2C, int x2I, Game* game);
void move(char x1C, int x1I, char x2C, int x2I, char tmp, Game* game);
bool ifCorrectIndex(char x1C, int x1I, Game* game);
bool collect(Game* game);
void collecting(Game* game, int p1, int p2, int v1, int v2);
bool collectingPrecise(Game* game, std::string s);


void GEN_ALL_POS_MOV(Game* game, bool num);
/*Game* do_move(Game* game, char x1C, int x1I, char x2C, int x2I);
bool collectD(Game* game, vector<Game*>& tab);
int vecAdd(vector<Game*>& tab, Game* w);*/

void IS_GAME_OVER(Game* game);