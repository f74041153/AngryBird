#ifndef SCORE
#define SCORE


#include<QGraphicsTextItem>

class Score:public QGraphicsTextItem
{
    Q_OBJECT
public:
    Score(QGraphicsItem*parent=0);
    void increase();
    int getscore();
private:
    int s;

};

#endif // SCORE

