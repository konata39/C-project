#include "stage_left.h"
#include "qtimer.h"
void stage_left::paintStage(QPainter &event)
{
    event.drawPixmap(xstage,ystage, QPixmap("stage_left.jpg"));
}
int stage_left::life(int blood)
{
    blood++;
    if(blood>10) return 10;
    else return blood;
}
float stage_left::moveloc(float x)
{
    x-=1.5;
    return x;
}
bool stage_left::fall()
{
    return true;
}
bool stage_left::jump()
{
    return false;
}

