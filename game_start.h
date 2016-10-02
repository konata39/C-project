#ifndef GAME_START_H
#define GAME_START_H
class gs:public QWidget
{
public:
    gs()
    {
        k=8;
    }
    gs& operator--()
    {
        Decrement();
        return *this;
    }
    void Decrement()
    {
        --k;
        if(k<-20) k=-20;
    }
    void paint(QPainter &event)
    {
            event.drawPixmap(-160+20*k,0, QPixmap("gs0.jpg"));
            event.drawPixmap(340-20*k,0, QPixmap("gs1.jpg"));
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
#endif // GAME_START_H
