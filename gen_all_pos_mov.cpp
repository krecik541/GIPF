#include"structs_and_defines.h"
#include<vector>
#include<string>

using namespace std;

int vecAdd(vector<Game*>& tab, Game* w);
bool collectD(Game* game, vector<Game*>& tab);
Game* do_move(Game* game, char x1C, int x1I, char x2C, int x2I, vector<Game*>& tab);

void GEN_ALL_POS_MOV(Game* game, bool num)
{
    int o[BUF][2] = { {1,0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1} };
    //int o[4][2] = { {1,0}, {0, 1}, {0, -1}, {-1, 0}};
    vector<Game*>tab;
    Game* w;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            for (int p = 0; p < BUF; p++)
            {
                w = new Game;
                w->cpy(w, *game);
                if (w->t[i][j].value == GWIAZDKA)
                {
                    if (i + o[p][0] >= 0 && i + o[p][0] < BOARD_SIZE && j + o[p][1] >= 0 && j + o[p][1] < BOARD_SIZE);
                    else
                        continue;
                    w = do_move(w, w->t[i][j].nameC, w->t[i][j].nameI, w->t[i + o[p][0]][j + o[p][1]].nameC, w->t[i + o[p][0]][j + o[p][1]].nameI, tab);
                }
            }
        }
    }

    if (!num)
    {
        for (int i = 0; i < tab.size(); i++)
        {
            PRINT_GAME_BOARD(tab[i]);
        }
    }
    else
        cout << tab.size() << "_UNIQUE_MOVES\n";
}

Game* do_move(Game* game, char x1C, int x1I, char x2C, int x2I, vector<Game*>& tab)
{
    if (!ifCorrectIndex(x1C, x1I, game))
        return nullptr;
    else if (!ifCorrectIndex(x2C, x2I, game))
        return nullptr;
    else if (!ifStartingField(x1C, x1I, game))
        return nullptr;
    else if (!ifDestinationField(x2C, x2I, game))
        return nullptr;
    else if (!ifNeighbor(x1C, x1I, x2C, x2I, game))
        return nullptr;
    else if (!FullRow(x1C, x1I, x2C, x2I, game))
        return nullptr;
    else
    {
        move(x1C, x1I, x2C, x2I, game->move, game);
        collectD(game, tab);
        return game;
    }
}

bool collectD(Game* game, vector<Game*>& tab)
{
    Game* w;
    if (game->move == WHITE)
    {
        game->resW--;
        game->move = BLACK;
    }
    else
    {
        game->resB--;
        game->move = WHITE;
    }
    int z = rowOfLengthK(game);
    if (z == 0)
    {
        w = new Game;
        w->cpy(w, *game);
        vecAdd(tab, w);
        return true;
    }
    //doprecyzowanie

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
                w = game;
                collecting(w, i, j, 0, 1);
                //collectD(w, tab);
                vecAdd(tab, w);
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
                w = game;
                collecting(w, j, i, 1, 0);
                //collectD(w, tab);
                vecAdd(tab, w);
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
                w = game;
                collecting(w, j, x, 1, 1);
                //collectD(w, tab);
                vecAdd(tab, w);
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
                w = game;
                collecting(w, j, x, 1, 1);
                //collectD(w, tab);
                vecAdd(tab, w);
                break;
            }
            x++;
            j++;
        }
    }
    return true;
}

int vecAdd(vector<Game*>& tab, Game* w)
{
    int p = 0;
    bool uniq = true;
    for (p = 0; p < tab.size(); p++)
    {
        /*if (tab[p]->move != w->move || tab[p]->resB != w->resB || tab[p]->resW != w->resW)
                break;*/
        int q = 0, e = 0;
        for (q = 0; q < BOARD_SIZE1; q++)
        {
            for (e = 0; e < BOARD_SIZE1; e++)
                if (tab[p]->t[q][e].value != w->t[q][e].value)
                    break;
            if (e != BOARD_SIZE1)
                break;
        }
        if (q == BOARD_SIZE1 && e == BOARD_SIZE1)
        {
            uniq = false;
            break;
        }
    }
    if (uniq || tab.size() == 0)
        tab.push_back(w);
    return 0;
}