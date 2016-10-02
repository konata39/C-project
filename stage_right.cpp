#include "stage_right.h"
#include "qtimer.h"
void stage_right::paintStage(QPainter &event)
{
    event.drawPixmap(xstage,ystage, QPixmap("stage_right.jpg"));
}
int stage_right::life(int blood)
{
    blood++;
    if(blood>10) return 10;
    else return blood;
}
float stage_right::moveloc(float x)
{
    x+=1.5;
    return x;
}
bool stage_right::fall()
{
    return true;
}
bool stage_right::jump()
{
    return false;
}
