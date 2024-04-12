#include"structs_and_defines.h"

using namespace std;

Game::Game() : S(NULL), K(NULL), GW(NULL), GB(NULL), resW(NULL), resB(NULL), move(NULL)
{
    t = nullptr;
}

void Game::clear()
{
    if (t != nullptr)
    {
        for (int i = 0; i < 2 * S + 1; i++)
            delete[]t[i];
        delete[]t;
    }
    t = nullptr;
    S = NULL;
    K = NULL;
    GW = NULL;
    GB = NULL;
    resW = NULL;
    resB = NULL;
    move = NULL;
}

void Game::cpy(Game* a, Game b)
{
    a->GB = b.GB;
    a->GW = b.GW;
    a->K = b.K;
    a->move = b.move;
    a->resB = b.resB;
    a->resW = b.resW;
    a->S = b.S;
    a->t = new board * [2 * a->S + 1];
    for (int i = 0; i < a->S * 2 + 1; i++)
    {
        a->t[i] = new board[2 * a->S + 1];
        for (int j = 0; j < a->S * 2 + 1; j++)
        {
            a->t[i][j].value = b.t[i][j].value;
            a->t[i][j].nameC = b.t[i][j].nameC;
            a->t[i][j].nameI = b.t[i][j].nameI;
        }
    }
}