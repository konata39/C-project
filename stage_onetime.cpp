#include "stage_onetime.h"
#include "qtimer.h"
void stage_onetime::paintStage(QPainter &event)
{
    event.drawPixmap(xstage,ystage, QPixmap("stage_onetime.jpg"));
}
int stage_onetime::life(int blood)
{
    blood+=1;
    if(blood>10) return 10;
    else return blood;
}
float stage_onetime::moveloc(float x)
{
    return x;
}
bool stage_onetime::fall()
{
    return false;
}
bool stage_onetime::jump()
{
    return false;
}
