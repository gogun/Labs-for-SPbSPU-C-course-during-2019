#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

const double scale_rate1 = 3.42;
const double scale_rate2 = 2.93;

void printRectangle(const karpenko::Shape & shape)
{
  const karpenko::rectangle_t frameRect = shape.getFrameRect();
  std::cout << "Width is " << frameRect.width;
  std::cout << "; Height is " << frameRect.height << ";\n";
  std::cout << "Center on [" << frameRect.pos.x << ";";
  std::cout << frameRect.pos.y << "];\n";
  std::cout << "Area of rectangle is " << shape.getArea() << ";\n\n";
}

void printCircle(const karpenko::Shape & shape)
{
  const karpenko::rectangle_t frameRect = shape.getFrameRect();
  std::cout << "Width of frame circle rectangle is " << frameRect.width;
  std::cout << "; Height of frame circle rectangle is " << frameRect.height << ";\n";
  std::cout << "Center on [" << frameRect.pos.x << ";" << frameRect.pos.y << "];\n";
  std::cout << "Area of circle is " << shape.getArea() << ";\n\n";
}

int main()
{
  karpenko::Rectangle rectangle({1.2, 4.33, {3.2, 4.7}});

  std::cout << "Rectangle demonstration started.\n\n";
  printRectangle(rectangle);
  std::cout << "Moving to coordinates...\n";
  rectangle.move(5.0, 4.0);
  printRectangle(rectangle);
  std::cout << "Moving to point...\n";
  rectangle.move({3.0, 3.0});
  printRectangle(rectangle);

  std::cout << "Applies scaling with coefficient = "
    << scale_rate1 << "\n";
  rectangle.scale(scale_rate1);
  printRectangle(rectangle);
  std::cout << "End program for Rectangle;\n\n";


  karpenko::Circle circle({-5.0, {1.0, 2.0}});

  std::cout << "Circle demonstration started.\n";
  printCircle(circle);
  std::cout << "Moving to coordinates...\n";
  circle.move(5.0, 6.0);
  printCircle(circle);
  std::cout << "Moving to point...\n";
  circle.move({3.0, 3.0});
  printCircle(circle);

  std::cout << "Applies scaling with coefficient = "
    << scale_rate1 << "\n";
  circle.scale(scale_rate2);
  printCircle(circle);
  std::cout << "End program for Circle;\n";
  return 0;
}
