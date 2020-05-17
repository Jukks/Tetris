/*
 * Class containing the UI elements
 */

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QBrush>
#include <QGraphicsRectItem>
#include <QColor>
#include <QString>

#include <vector>

class GameLogic;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void set_block_color(int row, int column, QColor color);
    const QBrush get_block_color(int row, int column);
public slots:
    void testfunc();

private:

    Ui::MainWindow *ui;
    QGraphicsScene* scene_;

    //variables indicating game position and size
    static const int GAME_POSITION_Y = 50;
    static const int GAME_POSITION_X = 50;

    static const int GAME_SIZE_Y = 480;
    static const int GAME_SIZE_X = 240;

    static const int SQUARE_SIZE = 20;

    static const int ROWS = GAME_SIZE_Y / SQUARE_SIZE;
    static const int COLUMNS = GAME_SIZE_X / SQUARE_SIZE;

    std::vector<std::vector<QGraphicsRectItem*>> game_grid;

    const QString WINDOW_TITLE = "Tetris";

    const QColor EMPTY = QColor("white");

    GameLogic* game_logic;
};
#endif // MAINWINDOW_HH
