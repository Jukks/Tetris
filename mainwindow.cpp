#include "mainwindow.hh"
#include "ui_mainwindow.h"

#include "gamelogic.hh"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(WINDOW_TITLE);

    scene_ = new QGraphicsScene(this);

    ui->game_graphics_view->setStyleSheet("border-style: none");

    ui->game_graphics_view->setGeometry(GAME_POSITION_X, GAME_POSITION_Y,
                                        GAME_SIZE_X+1, GAME_SIZE_Y+1);
    ui->game_graphics_view->setScene(scene_);
    scene_->setSceneRect(0, 0, GAME_SIZE_X, GAME_SIZE_Y);

    game_logic = new GameLogic(ROWS, COLUMNS, this);

    for (int y=0; y<ROWS; y++){
        std::vector<QGraphicsRectItem*> row;
        game_grid.push_back(row);
        for(int x=0; x<COLUMNS; x++){
            game_grid.at(y).push_back(new QGraphicsRectItem(x*SQUARE_SIZE,
                                                    y*SQUARE_SIZE,
                                                    SQUARE_SIZE,
                                                    SQUARE_SIZE));
            game_grid.at(y).at(x)->setBrush(EMPTY);
            scene_->addItem(game_grid.at(y).at(x));
        }
    }
    game_logic->start_game();

}

MainWindow::~MainWindow()
{
    delete game_logic;
    for (int y=0; y<ROWS; y++){
        for(int x=0; x<COLUMNS; x++){
            delete game_grid.at(y).at(x);
        }
    }
    delete scene_;
    delete ui;
}

void MainWindow::set_block_color(int row, int column, QColor color)
{
    game_grid.at(row).at(column)->setBrush(color);
}

const QBrush MainWindow::get_block_color(int row, int column)
{
    return game_grid.at(row).at(column)->brush();
}
