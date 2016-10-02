#include "stage_jump.h"
#include "qtimer.h"
void stage_jump::paintStage(QPainter &event)
{
    event.drawPixmap(xstage,ystage, QPixmap("stage_jump.jpg"));
}
int stage_jump::life(int blood)
{
    blood+=1;
    if(blood>10) return 10;
    else return blood;
}
float stage_jump::moveloc(float x)
{
    return x;
}
bool stage_jump::fall()
{
    return true;
}
bool stage_jump::jump()
{
    return true;
}
