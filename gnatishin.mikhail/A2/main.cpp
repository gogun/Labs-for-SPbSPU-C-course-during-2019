#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"

int main()
{
  gnatishin::Circle circle{gnatishin::point_t{5, 10}, 12};
  gnatishin::Shape *shapePointer = &circle;

  std::cout << " Circle Information:" << '\n';
  std::cout << "Area - " << shapePointer->getArea() << '\n';
  std::cout << "Width of Frame - " << shapePointer->getFrameRect().width << '\n';
  std::cout << "Height of Frame - " << shapePointer->getFrameRect().height << '\n';
  std::cout << "Position of the center is ("
      << shapePointer->getPosition().x << "; "
      << shapePointer->getPosition().y << ")\n";

  std::cout << "\n Actions:" << '\n';
  std::cout << "Move Circle for dx = 5, dy = -5" << '\n';
  shapePointer->move(5.0, -5.0);
  std::cout << "Position of the center is ("
      << shapePointer->getPosition().x << "; "
      << shapePointer->getPosition().y << ")\n";
  std::cout << "Move Circle to (0; 10)" << '\n';
  shapePointer->move({0.0, 10.0});
  std::cout << "Position of the center is ("
      << shapePointer->getPosition().x << "; "
      << shapePointer->getPosition().y << ")\n";
  std::cout << "Scaling circle by the factor of 3.0\n";
  shapePointer->scale(3.0);
  std::cout << "Area - " << shapePointer->getArea() << '\n';

  gnatishin::Rectangle rectangle{gnatishin::point_t{10, 15}, 5, 6};
  shapePointer = &rectangle;

  std::cout << "\n Rectangle Information:" << '\n';
  std::cout << "Area - " << shapePointer->getArea() << '\n';
  std::cout << "Width of Frame: " << shapePointer->getFrameRect().width << '\n';
  std::cout << "Height of Frame: " << shapePointer->getFrameRect().height << '\n';
  std::cout << "Position of the center is ("
      << shapePointer->getPosition().x << "; "
      << shapePointer->getPosition().y << ")\n";

  std::cout << "\n Actions:" << '\n';
  std::cout << "Move Rectangle for dx = 7.9, dy = -4.5" << '\n';
  shapePointer->move(7.9, -4.5);
  std::cout << "Position of the center is ("
      << shapePointer->getPosition().x << "; "
      << shapePointer->getPosition().y << ")\n";
  std::cout << "Move Rectangle to (-5; -10)" << '\n';
  shapePointer->move({-5.0, -10.0});
  std::cout << "Position of the center is ("
      << shapePointer->getPosition().x << "; "
      << shapePointer->getPosition().y << ")\n";
  std::cout << "Scaling rectangle by the factor of 2.0\n";
  shapePointer->scale(2.0);
  std::cout << "Area - " << shapePointer->getArea() << '\n';

  return 0;
}
