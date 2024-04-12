#include"structs_and_defines.h"

using namespace std;

void PRINT_GAME_BOARD(Game* game)
{
    if (game->t == nullptr)
        cout << "EMPTY_BOARD\n";
    else
    {
        int x = BOARD_SIZE - game->S - 1;
        cout << game->S << " " << game->K << " " << game->GW << " " << game->GB << endl << game->resW << " " << game->resB << " " << game->move << endl;
        for (int i = 1; i < game->S; i++)
        {
            for (int j = 0; j < x; j++)
                cout << " ";
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (game->t[i][j].value != '*')
                    cout << game->t[i][j].value << " ";
            }
            x--;
            cout << endl;
        }

        for (int i = game->S; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
                if (game->t[i][j].value != '*')
                    cout << game->t[i][j].value << " ";
                else
                    cout << " ";
            cout << endl;
        }
    }
}