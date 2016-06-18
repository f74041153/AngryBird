#include"score.h"
#include<QFont>

Score::Score(QGraphicsItem*parent):QGraphicsTextItem(parent)
{
    s=0;
    setPlainText(QString("SCORE:")+QString::number(s));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Terminal",28));

}
void Score::increase()
{
    s=s+1000;
    setPlainText(QString("SCORE:")+QString::number(s));
}
int Score::getscore()
{
    return s;

}
