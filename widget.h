#ifndef WIDGET_H
#define WIDGET_H
#include <string>
#include "stages.h"
#include "game_over.h"
#include "game_start.h"
class apWidget : public QWidget {
public:
    apWidget(QWidget* parent = 0);
protected:
    void paintEvent(QPaintEvent *);
    //void paintStage(QPaintEvent *);
    virtual void keyReleaseEvent(QKeyEvent *event);
     virtual void keyPressEvent(QKeyEvent *event);

private:
    int x;
    int y;
    int z,z0;
    int blood,loc,fall,jump;
    int mode,v0,a;
    bool sit,le,ri,inp,oup;
    float v;
    float x0,x1,x2,x3;
    float y0,y1,y2,y3;
    go game_over;
    gs game_start;
    QString s,ll;
};
#endif // WIDGET_H
