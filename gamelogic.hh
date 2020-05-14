/*
 * Class containing the game logic for a tetris game
 */
#ifndef GAMELOGIC_HH
#define GAMELOGIC_HH

#include "tetromino.hh"

#include <vector>


class GameLogic
{
public:
    GameLogic(const int rows, const int columns);
    ~GameLogic();
private:
    std::vector<Tetromino*> tetrominos;
    std::vector<std::vector<bool>> game_grid;
    Tetromino* current_tetromino;
};

#endif // GAMELOGIC_HH
