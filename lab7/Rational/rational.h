// rational.h
// Patrick Soga
// Section 2  Lab 7
// 3 November 2019
// rational.h: rational class interface
class Rational {
  public:
    Rational();
    Rational(int, int);
    ~Rational();
    int getNumer();
    int getDenom();
    void setNumer(int);
    void setDenom(int);
    void print();
    Rational add(Rational);
    Rational subtract(Rational);
    Rational multiply(Rational);
    Rational divide(Rational);
  private:
    int numer;
    int denom;
};

