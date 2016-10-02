#include "stages.h"
stage *getstage()
{
    int stage_NUM;
    stage *ptr;
    stage_NUM=rand()%16;
    if (stage_NUM==1||stage_NUM==2||stage_NUM==3||stage_NUM==8||stage_NUM==10||stage_NUM==11||stage_NUM==12)ptr=new stage_normal;
    else if (stage_NUM==4||stage_NUM==6||stage_NUM==13)ptr=new stage_right;
    else if (stage_NUM==5)ptr=new stage_poison;
    else if (stage_NUM==9)ptr=new stage_onetime;
    else if (stage_NUM==14)ptr=new stage_jump;
    else ptr=new stage_left;
    return ptr;
}
