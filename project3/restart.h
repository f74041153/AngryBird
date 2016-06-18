#ifndef RESTART
#define RESTART

#include<QGraphicsView>
#include<QWidget>
#include<QGraphicsScene>
#include<QGraphicsTextItem>
#include<QPushButton>
class Restart:public QGraphicsView
{
public:
    Restart(QWidget*parent=0);
    QGraphicsScene*scene;
    QPushButton*button1;
    QPushButton*button2;

};

#endif // RESTART

