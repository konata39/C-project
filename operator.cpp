class Flo
{
public:
    Flo(float f):fl(f){};
    Flo operator%(Flo int& other) {
            x=fl;
            x=fl%other;
            fl=x;
            return fl;
        }
    /*Flo operator%(float const& other) const {
            return std::fmod(val, other);
        }*/
private:
    float fl;
    int x;
};
