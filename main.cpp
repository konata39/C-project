#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QPrinter>
#include <QFileDialog>
#include <QPrintDialog>
#include <QPainter>
#include <QKeyEvent>
#include<iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "qtimer.h"
#include "widget.h"

using namespace std;
static stage *stage_ptr;
static stage *stage_ptr1;
static stage *stage_ptr2;
static stage *stage_ptr3;
apWidget::apWidget(QWidget* parent):QWidget(parent)
{
    stage_ptr=getstage();
    stage_ptr1=getstage();
    stage_ptr2=getstage();
    stage_ptr3=getstage();
    stage_ptr->initiallocate(100.0,50.0);
    stage_ptr1->initiallocate(20.0,185.0);
    stage_ptr2->initiallocate(120.0,310.0);
    stage_ptr3->initiallocate(200.0,465.0);
    sit=0;
    le=0;
    inp=0;
    oup=0;
    mode=0;
    ri=0;
    jump=0;
    fall=0;
    blood=10;
    v=-3;
    y=60;
    v0=3;
    x=170;
    loc=0;
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(25);
}
void apWidget::keyPressEvent(QKeyEvent* event)
{
    if(event->key()==Qt::Key_Left) {le=1;}
    else if(event->key()==Qt::Key_Right) {ri=1;}
    //else if(event->key()==Qt::Key_Up) y-=100;
    //else if(event->key()==Qt::Key_Down) y+=100;
    else if(event->key()==Qt::Key_Space) {mode=1;}
    else if(event->key()==Qt::Key_Q) {exit(0) ;}
}
void apWidget::keyReleaseEvent(QKeyEvent* event)
{
    if(event->key()==Qt::Key_Left) {le=0;}
    else if(event->key()==Qt::Key_Right) {ri=0;}
}
void apWidget::paintEvent(QPaintEvent *event) {
    // «Ø¥ßQPainter
    if(mode==0)
    {
        QPainter title(this);
        title.drawPixmap(0,0, QPixmap("gs0.jpg"));
        title.drawPixmap(180,0, QPixmap("gs1.jpg"));
        inp=1;
    }
    else if(mode==1)
    {
    QPainter painter(this);
    painter.drawPixmap(0,0, QPixmap("back.jpg"));
    /*if(x<200&&z>0) painter.drawPixmap(x+=z,y, QPixmap("6V9tORO.jpg"));
    else if(x>=200&&z>0) z=(-z);
    else if(x<=0&&z<0) z=(-z);
    else painter.drawPixmap(x+=z,y, QPixmap("6V9tORO.jpg"));*/
    x0=stage_ptr->returnstage_x();
    y0=stage_ptr->returnstage_y();
    x1=stage_ptr1->returnstage_x();
    y1=stage_ptr1->returnstage_y();
    x2=stage_ptr2->returnstage_x();
    y2=stage_ptr2->returnstage_y();
    x3=stage_ptr3->returnstage_x();
    y3=stage_ptr3->returnstage_y();
    QFont font("Times", 16);
    painter.setFont(font);
    stage_ptr->paintStage(painter);
    stage_ptr1->paintStage(painter);
    stage_ptr2->paintStage(painter);
    stage_ptr3->paintStage(painter);
    if(le==1) x-=3;
    if(ri==1) x+=3;
    painter.drawPixmap(0,0, QPixmap("top.png"));
    if(blood!=0&&y<560)
    {
        if(jump!=0)
    {
        if(jump!=1)y=y-9;
        if(y<35) {blood-=4; if(blood<0) blood=0;jump=1;}
        painter.drawPixmap(x,y, QPixmap("Naegi_DR_Icon.png"));
        jump--;
    }
    else
        {
            if(y+40>=y0&&y+40<=y0+12&&x+32>x0&&x<x0+84&&fall<2)
        {
            painter.drawPixmap(x,y0-40, QPixmap("Naegi_DR_Icon.png"));
            y+=v;
            x=stage_ptr->moveloc(x);
            if(sit==0)
            {
                blood=stage_ptr->life(blood);
                sit=1;
            }
            if(stage_ptr->fall()==false)fall++;
            if(stage_ptr->jump()==true)jump=15;
            if(y<35) {blood-=4; if(blood<0) blood=0;fall=2;}
        }
    else if(y+40>=y1&&y+40<=y1+12&&x+32>x1&&x<x1+84&&fall<2)
        {
            painter.drawPixmap(x,y1-40, QPixmap("Naegi_DR_Icon.png"));
            y+=v;
            x=stage_ptr1->moveloc(x);
            if(sit==0)
            {
                blood=stage_ptr1->life(blood);
                sit=1;
            }
            if(stage_ptr1->fall()==false)fall++;
            if(stage_ptr1->jump()==true)jump=15;
           if(y<35) {blood-=4; if(blood<0) blood=0;fall=2;}
        }
    else if(y+40>=y2&&y+40<=y2+12&&x+32>x2&&x<x2+84&&fall<2)
        {
            painter.drawPixmap(x,y2-40, QPixmap("Naegi_DR_Icon.png"));
            y+=v;
            x=stage_ptr2->moveloc(x);
            if(sit==0)
            {
                blood=stage_ptr2->life(blood);
                sit=1;
            }
            if(stage_ptr2->fall()==false)fall++;
            if(stage_ptr2->jump()==true)jump=15;
            if(y<35) {blood-=4; if(blood<0) blood=0;fall=2;}
        }
    else if(y+40>=y3&&y+40<=y3+12&&x+32>x3&&x<x3+84&&fall<2)
        {
            painter.drawPixmap(x,y3-40, QPixmap("Naegi_DR_Icon.png"));
            y+=v;
            x=stage_ptr3->moveloc(x);
            if(sit==0)
            {
                blood=stage_ptr3->life(blood);
                sit=1;
            }
            if(stage_ptr3->fall()==false)fall++;
            if(stage_ptr3->jump()==true)jump=15;
            if(y<35) {blood-=4; if(blood<0) blood=0;fall=2;}
        }
    //else if(y+20<y1||y>y1+18||x+20<x1||x>x1+88){painter.drawPixmap(x,y, QPixmap("unn.png")); y=y+5;}
    else if(y+40>=80&&fall==2) {painter.drawPixmap(x,y, QPixmap("Naegi_DR_Icon.png")); y=y+5; sit=0; fall=0;}
    else {painter.drawPixmap(x,y, QPixmap("Naegi_DR_Icon.png")); y=y+v0; sit=0;}
        }
    //paintStage(event);
    stage_ptr->movestage(v);
    stage_ptr1->movestage(v);
    stage_ptr2->movestage(v);
    stage_ptr3->movestage(v);
    //v+=a;
    }
    else painter.drawPixmap(x,y, QPixmap("Naegi_DR_Icon.png"));
    if(stage_ptr->returnstage_y()<-18)
        {
            stage_ptr=getstage();
    stage_ptr->startlocate();
    }
    if(stage_ptr1->returnstage_y()<-18)
        {stage_ptr1=getstage();
    stage_ptr1->startlocate();
    }
    if(stage_ptr2->returnstage_y()<-18)
        {stage_ptr2=getstage();
    stage_ptr2->startlocate();
    }
    if(stage_ptr3->returnstage_y()<-18)
        {stage_ptr3=getstage();
    stage_ptr3->startlocate();
    }
    s=QString::number(blood);
    painter.drawText(10, 18,"life: "+s+"/10");
    loc+=1;
    ll=QString::number(loc/100);
    painter.drawText(270, 18,"stage: "+ll);
    a=loc;
    if(a%500==1)
    {
        v0++;
        if(v0>10) v0=10;
        a=0;
    }
    /*if(a0>=1)
    {
        v0++;
        a=0;
    }*/
        game_start.paint(painter);
            --game_start;
            if(blood!=0&&y<560)
            {
                game_over.paint(painter);
        --game_over;
            }

            //if(game_start.ret()==0) inp==0;
    if(blood==0||y>=560)
    {
        QPainter paii(this);
            game_over.paint(paii);
            ++game_over;
            if(game_over.ret()==8) mode=2;
    }
    }
    else
        {
            QPainter pain(this);
            pain.drawPixmap(0,0, QPixmap("GO1.jpg"));
            pain.drawPixmap(180,0, QPixmap("GO0.jpg"));
            blood=10;
            stage_ptr=getstage();
    stage_ptr1=getstage();
    stage_ptr2=getstage();
    stage_ptr3=getstage();
    stage_ptr->initiallocate(100.0,50.0);
    stage_ptr1->initiallocate(20.0,185.0);
    stage_ptr2->initiallocate(120.0,310.0);
    stage_ptr3->initiallocate(200.0,465.0);
    sit=0;
    le=0;
    ri=0;
    jump=0;
    fall=0;
    blood=10;
    v=-3;
    y=60;
    v0=3;
    x=170;
    loc=0;
        }
}
/*void apWidget::paintStage(QPaintEvent *event) {
    QPainter painter2(this);
    painter2.drawPixmap(20,20, QPixmap("unnamed.png"));
}*/
int main(int argc, char *argv[]) {
    srand(time(NULL));
    QApplication app(argc, argv);
    apWidget *mapWidget=new apWidget();
    mapWidget->setWindowTitle("QPainter");
    mapWidget->resize(360 , 540);
    mapWidget->show();

    return app.exec();
}
