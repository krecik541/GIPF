#include"structs_and_defines.h"

using namespace std;

void IS_GAME_OVER(Game* game)
{
    int empty = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (game->t[i][j].value == FLOOR_INT)
                empty++;
    if (empty == 0)
    {
        if (game->move == BLACK)
            cout << "THE_WINNER_IS_WHITE\n";
        else
            cout << "THE_WINNER_IS_BLACK\n";
        return;
    }
    else if (game->resB == 0 && game->move == BLACK)
        cout << "THE_WINNER_IS_WHITE\n";
    else if (game->resW == 0 && game->move == WHITE)
        cout << "THE_WINNER_IS_BLACK\n";
    else
        cout << "GAME_IN_PROGRESS\n";
}