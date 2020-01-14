// rational.h
// Patrick Soga
// Section 2  Lab 8
// 10 November 2019
// rational.h: rational class interface
using namespace std;
class Rational {
  // Overloading ostream and istream
  friend ostream & operator<< (ostream & os, Rational &);
  friend istream & operator>> (istream & is, Rational &);
  
  public:
  
    Rational();
    Rational(int, int);
    ~Rational();
    int getNumer();
    int getDenom();
    void setNumer(int);
    void setDenom(int);
    void setRational(int, int);
    void reduce();
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);
  private:
    int numer;
    int denom;
};

