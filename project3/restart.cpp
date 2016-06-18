#include"restart.h"
#include<QFont>
#include<QGraphicsTextItem>


Restart::Restart(QWidget*parent):QGraphicsView()
{
   /* scene=new QGraphicsScene();
    scene->setSceneRect(0,0,400,300);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,300);*/
    button1=new QPushButton("RESTART",this);
    button1->setGeometry(QRect(QPoint(125,100),QSize(100,30)));
    button2=new QPushButton("EXIT",this);
    button2->setGeometry(QRect(QPoint(125,200),QSize(100,30)));

}
