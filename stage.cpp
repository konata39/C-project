#include"stage.h"
#include <cstdlib>
#include <ctime>
void stage::startlocate()
{
    ystage=540;
    xstage=rand()%250+10;
}
void stage::movestage(float v)
{
    ystage+=v;
}
void stage::initiallocate(float x0,float y0)
{
    xstage=x0;
    ystage=y0;
}
float stage::returnstage_y()
{
    return ystage;
}
float stage::returnstage_x()
{
    return xstage;
}
