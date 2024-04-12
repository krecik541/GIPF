#include"structs_and_defines.h"

using namespace std;

void DO_MOVE(Game* game)
{
    int flag = BEFORE_DASH, x1I = 0, x2I = 0;
    string s;
    cin >> s;
    char x1C = s[0], x2C;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == DASH_INT)
            flag = AFTER_DASH_CHAR;
        else if (flag == BEFORE_DASH)
            x1I = x1I * 10 + s[i] - ZERO;
        else if (flag == AFTER_DASH_CHAR)
        {
            x2C = s[i];
            flag = AFTER_DASH_INT;
        }
        else if (flag == AFTER_DASH_INT)
            x2I = x2I * 10 + s[i] - ZERO;
    }

    if (!ifCorrectIndex(x1C, x1I, game))
        cout << "BAD_MOVE_" << x1C << x1I << "_IS_WRONG_INDEX\n";
    else if (!ifCorrectIndex(x2C, x2I, game))
        cout << "BAD_MOVE_" << x2C << x2I << "_IS_WRONG_INDEX\n";
    else if (!ifStartingField(x1C, x1I, game))
        cout << "BAD_MOVE_" << x1C << x1I << "_IS_WRONG_STARTING_FIELD\n";
    else if (!ifDestinationField(x2C, x2I, game))
        cout << "BAD_MOVE_" << x2C << x2I << "_IS_WRONG_DESTINATION_FIELD\n";
    else if (!ifNeighbor(x1C, x1I, x2C, x2I, game))
        cout << "UNKNOWN_MOVE_DIRECTION\n";
    else if (!FullRow(x1C, x1I, x2C, x2I, game))
        cout << "BAD_MOVE_ROW_IS_FULL\n";
    else
    {
        move(x1C, x1I, x2C, x2I, game->move, game);
        if (!collect(game))
            return;
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
        cout << "MOVE_COMMITTED\n";
    }
}

bool ifNeighbor(char x1C, int x1I, char x2C, int x2I, Game* game)
{
    int i = 0, j = 0, x1posI = 0, x1posJ = 0, x2posI = 0, x2posJ = 0;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
            if (game->t[i][j].nameC == x1C && game->t[i][j].nameI == x1I)
            {
                x1posI = i;
                x1posJ = j;
            }
            else if (game->t[i][j].nameC == x2C && game->t[i][j].nameI == x2I)
            {
                x2posI = i;
                x2posJ = j;
            }
    }
    if (abs(x1posI - x2posI) <= 1 && abs(x1posJ - x2posJ) <= 1)
        return true;
    return false;
}

bool ifStartingField(char x1C, int x1I, Game* game)
{
    int i = 0, j = 0, x1posI = 0, x1posJ = 0;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
            if (game->t[i][j].nameC == x1C && game->t[i][j].nameI == x1I)
            {
                x1posI = i;
                x1posJ = j;
            }
    }
    if (game->t[x1posI][x1posJ].value == GWIAZDKA && game->t[x1posI][x1posJ].nameI != 0)
        return true;
    return false;
}

bool ifDestinationField(char x2C, int x2I, Game* game)
{
    int i = 0, j = 0, x2posI = 0, x2posJ = 0;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
            if (game->t[i][j].nameC == x2C && game->t[i][j].nameI == x2I)
            {
                x2posI = i;
                x2posJ = j;
            }
    }
    if (game->t[x2posI][x2posJ].value != GWIAZDKA)
        return true;
    return false;
}

bool FullRow(char x1C, int x1I, char x2C, int x2I, Game* game)
{
    int i = 0, j = 0, x1posI = 0, x1posJ = 0, x2posI = 0, x2posJ = 0;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
            if (game->t[i][j].nameC == x1C && game->t[i][j].nameI == x1I)
            {
                x1posI = i;
                x1posJ = j;
            }
            else if (game->t[i][j].nameC == x2C && game->t[i][j].nameI == x2I)
            {
                x2posI = i;
                x2posJ = j;
                //cout << game->t[i][j].value << game->t[i][j].nameC << game->t[i][j].nameI << " " << i << " " << j << endl;
            }

    }
    int vecI = x2posI - x1posI, vecJ = x2posJ - x1posJ;
    i = x2posI;
    j = x2posJ;
    while (game->t[i][j].value != GWIAZDKA)
    {
        if (game->t[i][j].value == FLOOR_INT)
            return true;
        i += vecI;
        j += vecJ;
    }
    return false;
}

void move(char x1C, int x1I, char x2C, int x2I, char tmp, Game* game)
{
    int i = 0, j = 0, x1posI = 0, x1posJ = 0, x2posI = 0, x2posJ = 0;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
            if (game->t[i][j].nameC == x1C && game->t[i][j].nameI == x1I)
            {
                x1posI = i;
                x1posJ = j;
            }
            else if (game->t[i][j].nameC == x2C && game->t[i][j].nameI == x2I)
            {
                x2posI = i;
                x2posJ = j;
                //cout << game->t[i][j].value << game->t[i][j].nameC << game->t[i][j].nameI << " " << i << " " << j << endl;
            }

    }
    int vecI = x2posI - x1posI, vecJ = x2posJ - x1posJ;
    i = x2posI;
    j = x2posJ;
    while (game->t[i][j].value != GWIAZDKA)
    {
        if (game->t[i][j].value == FLOOR_INT)
        {
            game->t[i][j].value = tmp;
            return;
        }
        char tmp1 = game->t[i][j].value;
        game->t[i][j].value = tmp;
        tmp = tmp1;
        i += vecI;
        j += vecJ;
    }
}

bool ifCorrectIndex(char x1C, int x1I, Game* game)
{
    if ((int)x1C - Aa > BOARD_SIZE || x1I > BOARD_SIZE)
        return false;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
            if (game->t[i][j].nameC == x1C && game->t[i][j].nameI == x1I)
                return true;
    }
    return false;
}

bool collect(Game* game)
{
    int z = rowOfLengthK(game);
    string s;
    getline(cin, s);
    //cout << "*" << s << "*\n";
    if (z == 0)
        return true;
    if (s != "")
        return collectingPrecise(game, s);
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
                collecting(game, i, j, 0, 1);
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
                collecting(game, j, i, 1, 0);
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
                collecting(game, j, x, 1, 1);
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
                collecting(game, j, x, 1, 1);
                break;
            }
            x++;
            j++;
        }
    }
    return true;
}

void collecting(Game* game, int p1, int p2, int v1, int v2)
{
    char u = game->t[p1][p2].value;
    int p3 = p1 + v1, p4 = p2 + v2, dod = 0;
    while (game->t[p1][p2].value != GWIAZDKA && game->t[p1][p2].value != FLOOR_INT)
    {
        if (game->t[p1][p2].value == u)
            dod++;
        game->t[p1][p2].value = FLOOR_INT;
        p1 -= v1;
        p2 -= v2;
    }
    p1 = p3;
    p2 = p4;
    while (game->t[p1][p2].value != GWIAZDKA && game->t[p1][p2].value != FLOOR_INT)
    {
        if (game->t[p1][p2].value == u)
            dod++;
        game->t[p1][p2].value = FLOOR_INT;
        p1 += v1;
        p2 += v2;
    }
    if (u == BLACK)
        game->resB += dod;
    else
        game->resW += dod;
}

bool collectingPrecise(Game* game, string s)
{
    char color = s[1], x1C = s[4], x2C = s[7];
    int x1I = s[5] - ZERO, x2I = s[8] - ZERO;
    //cin >> color >> buf >> x1C >> x1I >> x2C >> x2I;
    //cout << color << " " << x1C << x1I << " " << x2C << x2I << endl;

    int a = abs(x1I - x2I), b = abs((int)x1C - (int)x2C);
    if ((a == b && a + 1 >= game->K) || (a + 1 >= game->K && b == 0) || (a == 0 && b + 1 >= game->K))
    {
        int v1 = (x2C - x1C), v2 = (x2I - x1I);
        if (v1 > 0)
            v1 = 1;
        else if (v1 == 0)
            v1 = 0;
        else
            v1 = -1;
        if (v2 > 0)
            v2 = 1;
        else if (v2 == 0)
            v2 = 0;
        else
            v2 = -1;
        int licz = 0;
        color -= ROZNICA;
        for (int i = 1; i < BOARD_SIZE; i++)
        {
            for (int j = 1; j < BOARD_SIZE; j++)
            {
                if (game->t[i][j].nameC == x1C && game->t[i][j].nameI == x1I)
                {
                    int z = i, q = j;
                    while (game->t[i][j].value == color)
                    {
                        licz++;
                        i -= v2;
                        j += v1;
                        if (game->t[i][j].nameC == x2C && game->t[i][j].nameI == x2I)
                            break;
                    }
                    if (licz != max(a, b))
                    {
                        cout << "WRONG_COLOR_OF_CHOSEN_ROW\n";
                        return false;
                    }
                    licz = 0;
                    i = z;
                    j = q;
                    while (game->t[i][j].value != FLOOR_INT && game->t[i][j].value != GWIAZDKA)
                    {
                        if (game->t[i][j].value == color)
                            licz++;
                        game->t[i][j].value = FLOOR_INT;
                        i -= v2;
                        j += v1;
                        //cout << game->t[i][j].nameC << game->t[i][j].nameI << endl;
                    }
                    i = z + v2;
                    j = q - v1;
                    while (game->t[i][j].value != FLOOR_INT && game->t[i][j].value != GWIAZDKA)
                    {
                        if (game->t[i][j].value == color)
                            licz++;
                        game->t[i][j].value = FLOOR_INT;
                        i += v2;
                        j -= v1;
                        //cout << game->t[i][j].nameC << game->t[i][j].nameI << endl;
                    }
                    if (color == BLACK)
                        game->resB += licz;
                    else
                        game->resW += licz;
                    return true;
                }
            }
        }
    }
    else
    {
        cout << "WRONG_INDEX_OF_CHOSEN_ROW\n";
        return false;
    }
    return true;
}