#ifndef STAGE_H
#define STAGE_H
#include <QWidget>
#include <QApplication>
#include <QPainter>
#include <QKeyEvent>
class stage
{
public:
    virtual void paintStage(QPainter &)=0;
    virtual int life(int blood)=0;
    virtual float moveloc(float x)=0;
    virtual bool fall()=0;
    virtual bool jump()=0;
    void initiallocate(float x0,float y0);
    void movestage(float v);
    void startlocate();
    float returnstage_y();
    float returnstage_x();
protected:
    float xstage,ystage,v;
};
#endif // STAGE_H
