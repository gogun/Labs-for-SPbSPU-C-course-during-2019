#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void printInfo(Shape * shape)
{
  rectangle_t frameRect = shape->getFrameRect();

  std::cout<<"Area is "<<shape->getArea()<<";\nCentre is ["<<frameRect.pos.x<<","<<frameRect.pos.y<<"];\n";
  std::cout<<"Width of frame rectangle is "<<frameRect.width<<", height is "<<frameRect.height<<";\n";
}

int main()
{
  Circle c({1, 2.4}, 5); // Circle with centre at point [1, 2.4] and radius 5
  Shape * shape = &c;

  std::cout<<"--------------------Circle--------------------\n";
  printInfo(shape);

  shape->move(5, 0.6);  // Move by some value
  std::cout<<"\nMove 1.1:\n";
  printInfo(shape);

  shape->move({-3, -1}); // Move to the point
  std::cout<<"\nMove 1.2:\n";
  printInfo(shape);

  Rectangle r({3, 2}, 5, 4); // Rectangle with centre at point [3, 2], width 5 and heigh 4
  shape = &r;

  std::cout<<"\n-------------------RECTANGLE-------------------\n";
  printInfo(shape);

  shape->move(31.5, 5); // Move by some value
  std::cout<<"\nMove 2.1:\n";
  printInfo(shape);

  shape->move({-11, 2}); // Move to the point
  std::cout<<"\nMove 2.2:\n";
  printInfo(shape);

  Rectangle s({4, 15}, 11); // Square with centre at point [4, 15] and side 11
  shape = &s;

  std::cout<<"\n--------------------SQUARE--------------------\n";
  printInfo(shape);

  shape->move(0, 0); // Move by some value
  std::cout<<"\nMove 3.1:\n";
  printInfo(shape);

  shape->move({0, 0}); // Move to the point
  std::cout<<"\nMove 3.2:\n";
  printInfo(shape);

  return 0;
}
