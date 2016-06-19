#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"block.h"
#include<QKeyEvent>
#include<my_contact_listener.h>
#include"bird_two.h"
#include"bird_three.h"
#include"bird_four.h"
#include"score.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::restart()
{
    button1=new QPushButton(this);
    button1->setIcon(QIcon(":/restart.png"));
    button1->setIconSize(QSize(50,50));
    button1->setGeometry(QRect(QPoint(100,7),QSize(50,50)));
    button2=new QPushButton(this);
    button2->setIcon(QIcon(":/exit.png"));
    button2->setIconSize(QSize(50,50));
    button2->setGeometry(QRect(QPoint(50,7),QSize(50,50)));
    button1->show();
    button2->show();
    QObject::connect(button1,SIGNAL(clicked()),this,SLOT(renew_mainwindow()));//go back start window play again
    QObject::connect(button2,SIGNAL(clicked()),this,SLOT(QUITSLOT()));//quit whole game
    QObject::connect(button2,SIGNAL(clicked()),this,SLOT(close()));
}
 void MainWindow::renew_mainwindow()
{
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    restart();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/background.jpg")));

    world = new b2World(b2Vec2(0.0f, -9.8f));
    GameItem::setGlobalSize(QSizeF(32,18),size());

    land=new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(960,90),world,scene);
    itemList.push_back(land);

    rope = new Dangon(2.5f,3.0f,1.5f,&timer,QPixmap(":/slingshot.png").scaled(45,45),world,scene);
    itemList.push_back(rope);

    build_a_castle();

    bird[0] = new Bird_one(2.0f,6.3f,0.5f,&timer,QPixmap(":/bird.png").scaled(30,30),world,scene);
    birdie=bird[0];
    itemList.push_back(birdie);

    b2ContactListener* m_contactListener=new My_contact_listener();
    world->SetContactListener(m_contactListener);

    score=new Score();
    score->setPos(50,50);
    scene->addItem(score);

    space_count=0;
    j_count=0;
    k_count=0;
    L_count=0;
    count=0;
    connect(&timer,SIGNAL(timeout()),this,SLOT(create_bird()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(clock()));
    timer.start(100/6);
    joint=NULL;


}
void MainWindow::showEvent(QShowEvent *)
{
    renew_mainwindow();
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    QMouseEvent *k= (QMouseEvent *)event;
    if(event->type() == QEvent::MouseButtonPress)
    {
          b2MouseJointDef jointDef;
          jointDef.bodyA = land->g_body;
          jointDef.bodyB = birdie->g_body;
          jointDef.collideConnected = true;
          jointDef.target.x=(k->x())*32/960+1.0;
          jointDef.target.y=(k->y()-540)*18/540*(-1)+1.0;
          joint = (b2MouseJoint*)world->CreateJoint(&jointDef);
          start_point.x=(k->x())*32/960+1.0;
          start_point.y=(k->y()-540)*18/540*(-1)+1.0;
          joint->SetTarget(b2Vec2((k->x())*32/960+1.0,(k->y()-540)*18/540*(-1)+1.0));
    }
    if(event->type() == QEvent::MouseMove)
    {

      if(joint!=NULL)
      {
         joint->SetTarget(b2Vec2((k->x())*32/960+1.0,(k->y()-540)*18/540*(-1)+1.0));

      }
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
         if (joint != NULL)
        {
          joint->SetTarget(b2Vec2((k->x())*32/960+1.0,(k->y()-540)*18/540*(-1)+1.0));
          world->DestroyJoint(joint);
          joint = NULL;

          b2Vec2 vec1,vec2;
          int strength =70;
          vec1.x= (start_point.x-(k->x())*32/960-1.0)*strength;
          vec1.y= (start_point.y-(k->y()-540)*18/540*(-1)-1.0)*strength;
          vec2.x=birdie->g_body->GetPosition().x;
          vec2.y=birdie->g_body->GetPosition().y;
          if(birdie->g_body->GetPosition().x==2.0)
          {
            birdie->g_body->ApplyLinearImpulse(vec1,vec2,1);
          }
        }
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
   emit quitGame();
}

void MainWindow::tick()
{
   world->Step(1.0/60.0,6,2);
   scene->update();
}

void MainWindow::QUITSLOT()
{
   std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::create_bird()
{

   if((birdie->g_body->GetPosition().x!=2&&birdie->g_body->GetLinearVelocity().x==0)||birdie->g_body->GetPosition().x>32||birdie->g_body->GetPosition().x<0)
  {
      switch(count)
      {
        case(0):
          bird[1] = new Bird_one(2.0f,6.3f,0.5f,&timer,QPixmap(":/blue.png").scaled(30,30),world,scene);
          count=count+1;
          birdie=bird[1];
        break;
        case(1):
         bird[2] = new Bird_two(2.0f,6.3f,0.5f,&timer,QPixmap(":/Bird1.png").scaled(30,30),world,scene);
          count=count+1;
          birdie=bird[2];
        break;
        case(2):
          bird[3] = new Bird_three(2.0f,6.3f,0.5f,&timer,QPixmap(":/Bird2.png").scaled(30,30),world,scene);
          count=count+1;
          birdie=bird[3];
        break;
        case(3):
          bird[4] = new Bird_four(2.0f,6.3f,0.5f,&timer,QPixmap(":/Bird3.png").scaled(30,30),world,scene);
          count=count+1;
          birdie=bird[4];
        break;
      }
    }

}
void MainWindow::build_a_castle()
{
    int k=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {

            if(j%2==1&&i%2==1)
            {
                enemy[k]=new Enemy(17.0+i,4+j,0.5f,&timer,QPixmap(":/enemy.png").scaled(30,30),world,scene);
                itemList.push_back(enemy[k]);
                k++;

            }else
            {
               brick[i][j]= new Block(17.0+i,4+j,1.0,1.0f,&timer,QPixmap(":/bricks1.png").scaled(30,30),world,scene);
                itemList.push_back(brick[i][j]);
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent*event)
{
    if(event->key()==Qt::Key_Space)
    {
       space_count++;
       if(space_count==1)
       {
         if(birdie==bird[1])
         {
             bird[1]->key();
         }
       }
     }
    if(event->key()==Qt::Key_K)
    {

        if(birdie==bird[2])
        {
          k_count++;
          if(k_count==1)
          {
             static_cast<Bird_two*>(bird[2])->bird_friend=new Bird_two(bird[2]->g_body->GetPosition().x,bird[2]->g_body->GetPosition().y,0.75f,&timer,QPixmap(":/Bird1.png").scaled(45,45),world,scene);
             bird[2]->key();
          }
        }
    }
    if(event->key()==Qt::Key_J)
    {
        if(birdie==bird[3])
        {
          j_count++;
          if(j_count==1)
          {
              static_cast<Bird_three*>(bird[3])->bird_friend=new Bird_three(bird[3]->g_body->GetPosition().x,bird[3]->g_body->GetPosition().y,0.75f,&timer,QPixmap(":/Bird2.png").scaled(45,45),world,scene);
              (bird[3])->key();
          }
        }
    }
    if(event->key()==Qt::Key_L)
    {
        if(birdie==bird[4])
        {
          L_count++;
          if(L_count==1)
          {
              (bird[4])->key();
          }
        }
    }
}
void MainWindow::clock()
{
  if(enemy[0]->temp==1)
  {
    score->increase();
    enemy[0]->temp=-1;

  }
  if(enemy[1]->temp==1)
  {
    score->increase();
    enemy[1]->temp=-1;

  }
  if(enemy[2]->temp==1)
  {
    score->increase();
    enemy[2]->temp=-1;

  }
  if(enemy[3]->temp==1)
  {
    score->increase();
    enemy[3]->temp=-1;

  }

}

