/*
 * Class containing the game logic for a tetris game
 */
#ifndef GAMELOGIC_HH
#define GAMELOGIC_HH

#include "tetromino.hh"

#include <QTimer>

#include <vector>
#include <random>

class MainWindow;

class GameLogic
{
public:
    GameLogic(const int rows, const int columns, MainWindow* ui_);
    ~GameLogic();
    void start_game();

private slots:
    void move_down();
private:

    bool xyz;

    std::vector<Tetromino*> tetrominos;
    std::vector<std::vector<bool>> game_grid;
    Tetromino* current_tetromino;
    MainWindow* ui;
    QTimer* timer;

    const int MOVE_INTERVAL = 400;

    std::default_random_engine random_gen;
    std::uniform_int_distribution<int> distr;

    int origin_x;
    int origin_y;

    void place_new_tetromino();

    std::vector<std::vector<int>> current_blocks;
};

#endif // GAMELOGIC_HH
