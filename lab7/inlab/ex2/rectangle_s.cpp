// rectangle_s.cpp
#include <iostream>
using namespace std;

struct Rectangle {
  float length;
  float width;
};

float find_perim(Rectangle);
float find_area(Rectangle);
void display(float, float);

int main()
{
  Rectangle rect;

  cout << "enter the rectangle's length and width: ";
  cin >> rect.length >> rect.width;

  float perim = find_perim(rect);
  float area = find_area(rect);

  display(perim, area);

  return 0;
}

float find_perim(Rectangle rect)
{
  float perim = 2*(rect.length+rect.width);
  return perim;
}

float find_area(Rectangle rect)
{
  float area = rect.length*rect.width;
  return area;
}

void display(float p, float a)
{
  cout << "the perimeter is: " << p << endl;
  cout << "the area is: " << a << endl;
}

