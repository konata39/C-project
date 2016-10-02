#ifndef STAGE_NORMAL_H
#define STAGE_NORMAL_H
#include "stage.h"
#include <QWidget>
#include <QApplication>
#include <QPainter>
#include <QKeyEvent>
class stage_normal:public stage,public QWidget
{
public:
     virtual void paintStage(QPainter &);
     virtual int life(int blood);
     virtual float moveloc(float x);
     virtual bool fall();
     virtual bool jump();
};
#endif // STAGE_NORMAL_H
