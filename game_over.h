#ifndef GAME_OVER_H
#define GAME_OVER_H
#include <QApplication>
#include <QWidget>
class go:public QWidget
{
public:
    go()
    {
        k=0;
    }
    go& operator++()
    {
        Increment();
        return *this;
    }
    go& operator--()
    {
        Decrement();
        return *this;
    }
    void Increment()
    {
        ++k;
        if(k>=9) k=8;
    }
    void Decrement()
    {
        --k;
        if(k<-1) k=-1;
    }
    void paint(QPainter &event)
    {
            event.drawPixmap(-160+20*k,0, QPixmap("GO1.jpg"));
            event.drawPixmap(340-20*k,0, QPixmap("GO0.jpg"));
    }
    void setnum(int s)
    {
        k=s;
    }
    int ret()
    {
        return k;
    }
private:
    int k;
};
#endif // GAME_OVER_H
