#include "gamelogic.hh"

GameLogic::GameLogic(const int rows, const int columns)
{
    for (int y=0; y<rows; y++){
        std::vector<bool> b;
        game_grid.push_back(b);
        for(int x=0; x<columns; x++){
            game_grid.at(y).push_back(false);
        }
    }
    for(int i=0; i<7; i++){
        tetrominos.push_back(new Tetromino(i));
    }
}
GameLogic::~GameLogic(){
    for(int i=0; i<7; i++){
        delete tetrominos.at(i);
    }
}
