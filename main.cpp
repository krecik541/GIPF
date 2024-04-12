#include <iostream>
#include <string>
#include"structs_and_defines.h"

/*
wykrywanie ciągów o dlugosci K
*/

using namespace std;

int main()
{
    Game game;
    string s;
    while (cin >> s)
    {
        if (s == "LOAD_GAME_BOARD")
            LOAD_GAME_BOARD(&game);
        else if (s == "PRINT_GAME_BOARD")
            PRINT_GAME_BOARD(&game);
        else if (s == "DO_MOVE")
            DO_MOVE(&game);
        else if (s == "GEN_ALL_POS_MOV")
            GEN_ALL_POS_MOV(&game, false);
        else if (s == "GEN_ALL_POS_MOV_NUM")
            GEN_ALL_POS_MOV(&game, true);
        else if (s == "IS_GAME_OVER")
            IS_GAME_OVER(&game);
    }
    return 0;
}