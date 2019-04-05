#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void writeFrameRectInfo(const Shape &shape)
{
  rectangle_t frameRect = shape.getFrameRect();
  std::cout << "Frame Rectangle: " << "Centre: " << '(' << frameRect.centre.x << ", " << frameRect.centre.y << ')'
            << " Width: " << frameRect.width << " Height: " << frameRect.height << std::endl;
}

void writeArea(const Shape &shape)
{
  std::cout << "Area is " << shape.getArea() << std::endl;
}

int main()
{
  std::cout << "Rectangle with centre (0, 0), width = 10 and height = 10" << std::endl;
  Rectangle rectangle({{0, 0}, 10, 10});
  writeArea(rectangle);
  writeFrameRectInfo(rectangle);

  std::cout << "Circle with centre (0, 0) and radius = 10" << std::endl;
  Circle circle({0, 0}, 10);
  writeArea(circle);
  writeFrameRectInfo(circle);
  
  std::cout << "Moving rectangle along Ox and Oy (dx = 30 and dy = 30)" << std::endl;
  rectangle.move(30, 30);
  writeArea(rectangle);
  writeFrameRectInfo(rectangle);

  std::cout << "Moving circle to the point (20, 20)" << std::endl;
  circle.move({20, 20});
  writeArea(circle);
  writeFrameRectInfo(circle);

  return 0;
}
