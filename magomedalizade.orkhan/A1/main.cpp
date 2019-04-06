#define _USE_MATH_DEFINES
#include "circle.hpp"
#include "rectangle.hpp"
#include <iostream>
#include <cmath> 
using namespace std;

int main()
{
  double dx = 2, dy = 2, height = 14, width = 20;
  point_t pos = { 5, 5 };

  Circle d(pos, 25);
  d.print();
  cout << "Area " << d.getArea() << endl;
  rectangle_t rt = d.getFrameRect();
  cout << "Limiting rectangle ";
  cout << "Center of FrameRect " << rt.pos.x << " " << rt.pos.y << " and width, height: " << rt.width << rt.height << endl;
  cout << "Move the center to a new point...\n";

  point_t NewCentre = { 75, 15 };
  d.move(NewCentre);
  d.move(dx, dy);
  d.print();
  cout << "Area " << d.getArea() << endl;
  rt = d.getFrameRect();
  cout << "Limiting rectangle ";
  cout << "Center of FrameRect " << rt.pos.x << " " << rt.pos.y << " and width, height: " << rt.width << rt.height << endl;
  

  // то же самое для прямоугольника
  Rectangle r(pos, height, width);
  r.print();

  cout << "Area " << r.getArea() << endl;
  rt = r.getFrameRect();
  cout << "Limiting rectangle ";
  cout << "Center of FrameRect " << rt.pos.x << " " << rt.pos.y << " and width, height: " << rt.width << rt.height << endl;
  cout << "Move the center to a new point...\n";

  NewCentre = { 100, 50 };
  r.move(NewCentre);
  r.move(dx, dy);
  r.print();
  cout << "Area " << r.getArea() << endl;
  rt = r.getFrameRect();
  cout << "Limiting rectangle ";
  cout << "Center of FrameRect " << rt.pos.x << " " << rt.pos.y << " and width, height: " << rt.width << rt.height << endl;
  system("Pause");
 return 0;
}
