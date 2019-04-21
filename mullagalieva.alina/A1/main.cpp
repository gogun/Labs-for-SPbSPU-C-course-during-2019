#include <iostream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

int main()
{
  Circle circle{point_t{4.12, 6.7}, 3.5};
  Rectangle rectangle{7.65, 3.65, 8.91, 13.01};
  Triangle triangle{point_t{3.17, 8.1}, point_t{14.1, 1.7}, point_t{18.9, 7.3}};

  Shape* shapePointer = &circle;
  shapePointer->show();
  std::cout << "Moving to the point (1; 2.9)" << "\n";
  shapePointer->move({1, 2.9});
  shapePointer->show();

  shapePointer = &rectangle;
  shapePointer->show();
  std::cout << "Moving dx = 3.4, dy = 5.6" << "\n";
  shapePointer->move(3.4, 5.6);
  shapePointer->show();

  shapePointer = &triangle;
  shapePointer->show();
  std::cout << "Moving to the point (6.12; 7.34)" << "\n";
  shapePointer->move({6.12, 7.34});
  shapePointer->show();
    
  return 0;
}
