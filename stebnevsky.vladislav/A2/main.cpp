#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void printInfo(const stebnevsky::Shape & shape)
{
  stebnevsky::rectangle_t temp_rect = shape.getFrameRect();
  std::cout << "Area: " << shape.getArea() << std::endl;
  std::cout << "Center:" << std::endl;
  std::cout << "x = " << temp_rect.pos.x << std::endl;
  std::cout << "y = " << temp_rect.pos.y << std::endl;
  std::cout << "Other Info:" << std::endl;
  std::cout << "width = " << temp_rect.width << std::endl;
  std::cout << "height = " << temp_rect.height << std::endl;
}

int main()
{
  stebnevsky::Circle circle({15.0, 13.0}, 2.0);

  std::cout << "CIRCLE" << std::endl;
  printInfo(circle);
  std::cout << "after movement:" << std::endl;
  circle.move(15.0, 17.0);
  printInfo(circle);
  std::cout << "after movement:" << std::endl;
  circle.move({20.0, 20.0});
  printInfo(circle);
  std::cout << "after scale:" << std::endl;
  circle.scale(2.0);
  printInfo(circle);

  stebnevsky::Rectangle rectangle({{3.0, 23.0}, 3.0, 2.0});

  std::cout << "RECTANGLE" << std::endl;
  printInfo(rectangle);
  std::cout << "after movement:" << std::endl;
  rectangle.move(7.0, 17.0);
  printInfo(rectangle);
  std::cout << "after movement:" << std::endl;
  rectangle.move({20.0, 10.0});
  printInfo(rectangle);
  std::cout << "after scale:" << std::endl;
  rectangle.scale(2.0);
  printInfo(rectangle);

  return 0;
}
