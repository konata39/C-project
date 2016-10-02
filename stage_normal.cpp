#include "stage_normal.h"
#include "qtimer.h"
void stage_normal::paintStage(QPainter &event)
{
    event.drawPixmap(xstage,ystage, QPixmap("stage_normal.jpg"));
}
int stage_normal::life(int blood)
{
    blood++;
    if(blood>10) return 10;
    else return blood;
}
float stage_normal::moveloc(float x)
{
    return x;
}
bool stage_normal::fall()
{
    return true;
}
bool stage_normal::jump()
{
    return false;
}
