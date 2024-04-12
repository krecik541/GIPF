#include"structs_and_defines.h"

using namespace std;

void LOAD_GAME_BOARD(Game* game)
{
    if (game->t != nullptr)
    {
        for (int i = 0; i < BOARD_SIZE; i++)
            delete[]game->t[i];
        delete[]game->t;
    }
    int licz, blank = 0;
    cin >> game->S >> game->K >> game->GW >> game->GB;
    licz = game->S + 1;
    game->t = new board * [BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        game->t[i] = new board[BOARD_SIZE];
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            game->t[i][j].nameC = Aa + (char)j;
            game->t[i][j].value = '*';
            game->t[i][j].nameI = 0;
        }
    }

    for (int i = 0; i < game->S + 1; i++)
    {
        int k = licz;
        for (int j = 0; j < BOARD_SIZE; j++)
            if (k > 0 && (licz < BOARD_SIZE || licz == BOARD_SIZE))
            {
                game->t[j][i].nameI = k;
                k--;
            }
        licz++;
    }

    blank++;
    licz -= 2;
    for (int i = game->S + 1; i < BOARD_SIZE; i++)
    {
        int k = licz;
        for (int j = 0 + blank; j < BOARD_SIZE; j++)
            if (k > 0)
            {
                game->t[j][i].nameI = k;
                k--;
            }
        licz--;
        blank++;
    }

    int W = 0, B = 0;//W, B - liczba odpowiednio bialych i czarnych pionow na planszy
    cin >> game->resW >> game->resB >> game->move;
    licz = 0; //liczba pol na planszy
    string s;
    getline(cin, s);
    for (int i = 1; i < BOARD_SIZE - 1; i++)
    {
        getline(cin, s);
        int j = 0, x = 0;
        while (j < s.length())
        {
            if (s[j] != '_' && s[j] != BLACK && s[j] != WHITE)
            {
                j++;
                continue;
            }
            else
            {
                licz++;
                while (true)
                {
                    if (x < BOARD_SIZE)
                    {
                        if (game->t[i][x].nameI != 0)
                        {
                            game->t[i][x + 1].value = s[j];
                            if (s[j] == BLACK)
                                B++;
                            else if (s[j] == WHITE)
                                W++;
                            break;
                        }
                        else
                            x++;
                    }
                    else
                        break;
                }
                j++;
                x++;
            }
        }
    }

    int lp = 0;
    for (int i = game->S; i + 2 < BOARD_SIZE; i++)
        lp += i * 2;
    lp += BOARD_SIZE - 2;

    if (B + game->resB > game->GB)
    {
        cout << "WRONG_BLACK_PAWNS_NUMBER\n";
        game->clear();
    }
    else if (W + game->resW > game->GW)
    {
        cout << "WRONG_WHITE_PAWNS_NUMBER\n";
        game->clear();
    }
    else if (licz != lp)
    {
        cout << "WRONG_BOARD_ROW_LENGTH\n";
        game->clear();
    }
    else
    {
        int z = rowOfLengthK(game);
        if (z == 1)
            cout << "ERROR_FOUND_" << z << "_ROW_OF_LENGTH_K\n";
        else if (z > 1)
            cout << "ERROR_FOUND_" << z << "_ROWS_OF_LENGTH_K\n";
        else
            cout << "BOARD_STATE_OK\n";
    }
}

int rowOfLengthK(Game* game)
{
    int licz = 0;
    //HORIZONTAL
    for (int i = 1; i < BOARD_SIZE - 1; i++)
    {
        int len = 1;
        for (int j = 1; j < BOARD_SIZE - 1; j++)
        {
            if (game->t[i][j].value == game->t[i][j - 1].value && (game->t[i][j].value == BLACK || game->t[i][j].value == WHITE))
                len++;
            else
                len = 1;
            if (len >= game->K)
            {
                licz++;
                break;
            }
        }
    }

    //VERTICAL
    for (int i = 1; i < BOARD_SIZE - 1; i++)
    {
        int len = 1;
        for (int j = 1; j < BOARD_SIZE - 1; j++)
        {
            if (game->t[j][i].value == game->t[j - 1][i].value && (game->t[j][i].value == BLACK || game->t[j][i].value == WHITE))
                len++;
            else
                len = 1;
            if (len >= game->K)
            {
                licz++;
                break;
            }
        }
    }

    //DIAGONAL
    for (int i = 1; i < BOARD_SIZE; i++)
    {
        int len = 1, x = i, j = 1;
        while (x < BOARD_SIZE && j < BOARD_SIZE - 1)
        {
            if (game->t[x][j].value == game->t[x - 1][j - 1].value && (game->t[x][j].value == BLACK || game->t[x][j].value == WHITE))
                len++;
            else
                len = 1;
            if (len >= game->K)
            {
                licz++;
                break;
            }
            x++;
            j++;
        }
    }

    for (int i = 2; i < BOARD_SIZE; i++)
    {
        int len = 1, x = i, j = 1;
        while (x < BOARD_SIZE && j < BOARD_SIZE)
        {
            if (game->t[j][x].value == game->t[j - 1][x - 1].value && (game->t[j][x].value == BLACK || game->t[j][x].value == WHITE))
                len++;
            else
                len = 1;
            if (len >= game->K)
            {
                licz++;
                break;
            }
            x++;
            j++;
        }
    }
    return licz;
}