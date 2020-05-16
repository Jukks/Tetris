#include "gamelogic.hh"
#include "mainwindow.hh"

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

    origin_y = -5;
    origin_x = -5;
}
GameLogic::~GameLogic(){
    for(int i=0; i<7; i++){
        delete tetrominos.at(i);
    }
    delete timer;
}

void GameLogic::start_game()
{
    current_tetromino = tetrominos.at(0);
    GameLogic::place_new_tetromino();
}

void GameLogic::place_new_tetromino()
{
    current_blocks.clear();
    const std::vector<std::vector<bool>>& temp = current_tetromino->get_current_rotation();
    for(unsigned short int y=0; y<temp.size(); y++){
        for(unsigned short int x=0; x<temp.at(y).size(); x++){
            if(temp.at(y).at(x)){
                current_blocks.push_back({origin_y+y, origin_x+x});
            }
        }
    }

    for(unsigned int i=0; i<current_blocks.size(); i++){
        if(current_blocks.at(i).at(0) < 0){
            // y too small
            // increase y by 1 for all blocks and update origin
            for(std::vector<int>& v : current_blocks){
                v.at(0)++;
            }
            origin_y++;
            i=-1;
            continue;
        }
        else if(current_blocks.at(i).at(0) >= int(game_grid.size())){
            // y too large
            for(std::vector<int>& v : current_blocks){
                v.at(0)--;
            }
            origin_y--;
            i=-1;
            continue;
        }
        if(current_blocks.at(i).at(1) < 0){
            // x too small
            for(std::vector<int>& v : current_blocks){
                v.at(1)++;
            }
            origin_x++;
            i=-1;
            continue;
        }
        else if(current_blocks.at(i).at(1) >= int(game_grid.at(0).size())){
            // x too large
            for(std::vector<int>& v : current_blocks){
                v.at(1)--;
            }
            origin_x--;
            i=-1;
            continue;
        }
    }

    for(std::vector<int>& v : current_blocks){
        ui->set_block_color(v.at(0), v.at(1), current_tetromino->get_color());
    }
    //ui->set_block_color(origin_y, origin_x, QColor("green"));
}

































