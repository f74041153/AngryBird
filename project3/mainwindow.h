#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include<QKeyEvent>
#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include"dangon.h"
#include"block.h"
#include"enemy.h"
#include"bird_one.h"
#include"score.h"
#include<QPushButton>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void build_a_castle();
signals:
    void quitGame();
private slots:
    void tick();
    void QUITSLOT();
    void create_bird();
    void renew_mainwindow();
    void restart();
    void clock();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;//an array of pointers to items of type
    QTimer timer,timer1;
    b2Vec2 start_point;
    Bird *bird[5];
    Bird*birdie;
    Land*land;
    Dangon *rope;
    Enemy *enemy[4];
    b2MouseJoint* joint;
    Block *brick[5][5];
    int count;//who next
    void keyPressEvent(QKeyEvent*event);
    int k_count;
    int j_count;
    int space_count;
    int L_count;
    Score*score;
    QPushButton*button1;
    QPushButton*button2;
};

#endif // MAINWINDOW_H
