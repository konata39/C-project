#ifndef STAGE_RIGHT_H
#define STAGE_RIGHT_H
#include "stage.h"
#include <QWidget>
#include <QApplication>
#include <QPainter>
#include <QKeyEvent>
class stage_right:public stage,public QWidget
{
public:
     virtual void paintStage(QPainter &);
     virtual int life(int blood);
     virtual float moveloc(float x);
     virtual bool fall();
     virtual bool jump();
};
#endif // STAGE_NORMAL_H
