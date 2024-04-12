# GIPF

This code implements a solver for the game GIPF, including functions to make moves, check move validity, collect pieces, generate possible moves, and check game status. Below is a brief description of what each major function in this code accomplishes:

DO_MOVE(Game* game):

Reads a move input from the user in the form of two positions (e.g., 'A1-B2').
Parses the input to determine the starting and ending positions.
Validates the move by checking various conditions (correct indices, starting field, destination field, neighboring positions, etc.).
If the move is valid, it executes the move and updates the game state.
ifNeighbor(char x1C, int x1I, char x2C, int x2I, Game* game):

Checks if two given positions are adjacent on the game board (within 1 square distance horizontally, vertically, or diagonally).
ifStartingField(char x1C, int x1I, Game* game):

Determines if a specified starting field is valid for making a move (e.g., not empty and containing a piece).
ifDestinationField(char x2C, int x2I, Game* game):

Checks if the destination field for a move is valid (e.g., not a special marker like '*').
FullRow(char x1C, int x1I, char x2C, int x2I, Game* game):

Checks if the path between two positions is clear (no obstacles or full rows of pieces that would block movement).
move(char x1C, int x1I, char x2C, int x2I, char tmp, Game* game):

Executes a move from a starting position to an ending position, moving pieces along the path and updating the game board accordingly.
collect(Game* game):

Checks for and collects pieces if any rows of pieces of a certain length (K) are formed horizontally, vertically, or diagonally on the board.
Handles the process of collecting pieces and updating game state after each move.
GEN_ALL_POS_MOV(Game* game, bool num):

Generates all possible moves for the current game state.
Iterates through each position on the board and attempts moves in all possible directions.
Validates each move and adds valid game states to a vector of possible game positions (tab).
do_move(Game* game, char x1C, int x1I, char x2C, int x2I, vector<Game*>& tab):

Attempts to execute a move on the game board and validates the move.
If the move is valid, it adds the resulting game state to a vector (tab) of possible game positions.
IS_GAME_OVER(Game* game):

Checks if the game is over based on the current game state.
Determines if there are no empty spaces left on the board or if one player has run out of pieces.
Outputs the result of the game (winner or game in progress).
LOAD_GAME_BOARD(Game* game):

Reads input to initialize the game board and game parameters.
Constructs the game board based on the input and initializes game state variables.
These functions collectively provide the logic necessary to play and solve the game GIPF. The solver reads input moves, executes them, checks game conditions, generates possible moves, and determines the game outcome. Each function plays a specific role in managing game state and executing game actions.
