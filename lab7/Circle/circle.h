// circle.h

// Patrick Soga
// Section 2  Lab 7
// 3 November 2019
// circle.h: interface for circle class
class Circle {
  public:
    Circle();
    Circle(float);
    ~Circle();
    float getRadius();
    void setRadius(float);
    float circumference();
    float area();
    void info();
  private:
    float radius;
};

