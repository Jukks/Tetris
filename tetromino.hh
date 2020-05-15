/*
 * Class depicting a single tetromino of a tetris game
 */

#ifndef TETROMINO_HH
#define TETROMINO_HH

#include <QColor>

#include <string>
#include <vector>

class Tetromino
{
public:
    Tetromino(int type);
    const std::vector<std::vector<bool>> get_current_rotation();
    const std::vector<std::vector<bool>> get_next_rotation();
private:
    std::vector<std::vector<std::vector<bool>>> rotations;
    int current_rotation;
    QColor color;
};

#endif // TETROMINO_HH
