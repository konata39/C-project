#include "stage_poison.h"
#include "qtimer.h"
void stage_poison::paintStage(QPainter &event)
{
    event.drawPixmap(xstage,ystage, QPixmap("stage_poison.jpg"));
}
int stage_poison::life(int blood)
{
    blood-=4;
    if(blood<0) return 0;
    else return blood;
}
float stage_poison::moveloc(float x)
{
    return x;
}
bool stage_poison::fall()
{
    return true;
}

bool stage_poison::jump()
{
    return false;
}
