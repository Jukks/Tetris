#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(WINDOW_TITLE);

    scene_ = new QGraphicsScene(this);

    ui->game_graphics_view->setStyleSheet("border-style: none");

    ui->game_graphics_view->setGeometry(GAME_POSITION_X, GAME_POSITION_Y,
                                        GAME_SIZE_X+1, GAME_SIZE_Y+1);
    ui->game_graphics_view->setScene(scene_);
    scene_->setSceneRect(0, 0, GAME_SIZE_X, GAME_SIZE_Y);

    for (int y=0; y<ROWS; y++){
        for(int x=0; x<COLUMNS; x++){
            game_grid[y][x] = new QGraphicsRectItem(x*SQUARE_SIZE,
                                                    y*SQUARE_SIZE,
                                                    SQUARE_SIZE,
                                                    SQUARE_SIZE);
            game_grid[y][x]->setBrush(EMPTY);
            scene_->addItem(game_grid[y][x]);
        }
    }
}


MainWindow::~MainWindow()
{
    for (int y=0; y<ROWS; y++){
        for(int x=0; x<COLUMNS; x++){
            delete game_grid[y][x];
        }
    }
    delete scene_;
    delete ui;
}
