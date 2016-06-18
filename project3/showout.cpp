#include"showout.h"
#include"mainwindow.h"
#include"restart.h"


void Showout::showout()//function to start whole game
{
    Restart *restart_win=new Restart();
    restart_win->show();
    //QObject::connect(restart_win->button1,SIGNAL(clicked()),this,SLOT(show());//go back start window play again
    //QObject::connect(restart_win->button1,SIGNAL(clicked()),,SLOT(close()));//last game window close
  //  QObject::connect(restart_win->button1,SIGNAL(clicked()),restart_win,SLOT(close()));//last game restart window close
    //QObject::connect(restart_win->button2,SIGNAL(clicked()),w,SLOT(QUITSLOT()));//quit whole game
    //QObject::connect(restart_win->button2,SIGNAL(clicked()),sw,SLOT(close()));//quit whole game
    //QObject::connect(window->button2,SIGNAL(clicked()),window,SLOT(close()));//quit whole game*/

}
