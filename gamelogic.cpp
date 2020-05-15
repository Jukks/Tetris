#include "gamelogic.hh"
//#include "mainwindow.hh"

GameLogic::GameLogic(const int rows, const int columns, MainWindow* ui_)
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
    ui = ui_;
    timer = new QTimer();

    //setup random engine
    distr= std::uniform_int_distribution<int>(0, tetrominos.size()-1);
    int seed = time(0);
    random_gen.seed(seed);
    distr(random_gen);
}
GameLogic::~GameLogic(){
    for(int i=0; i<7; i++){
        delete tetrominos.at(i);
    }
    delete timer;
}

void GameLogic::start_game()
{
    current_tetromino = tetrominos.at(distr(random_gen));
    //ui->get_block_color(0,0);
}
