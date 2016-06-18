#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTransform>
#include <QtMath>

class GameItem : public QObject
{
    Q_OBJECT
public:
    GameItem(b2World *world);
    virtual ~GameItem();
    static void setGlobalSize(QSizeF worldsize, QSizeF windowsize);
    b2Body *g_body;//A rigid body
    QGraphicsPixmapItem g_pixmap;
public slots:
    void paint();
protected:
    QSizeF g_size;
    static QSizeF g_worldsize, g_windowsize;
    b2World *g_world;

};

#endif // GAMEITEM_H
