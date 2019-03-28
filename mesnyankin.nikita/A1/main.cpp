#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"


int main()
{
  Rectangle rectangle_object(10, 10, {20,20});
 
  std::cout << "Rectangle width is " << rectangle_object.getWidth() << std::endl;
  std::cout << "Rectangle height is " << rectangle_object.getHeight() << std::endl;
  std::cout << "Rectangle centre position is " << rectangle_object.getPos().x << " // "
      << rectangle_object.getPos().y << std::endl;
  std::cout << "Rectangle area is " << rectangle_object.getArea() << std::endl;
  std::cout << "Frame rectangle is the same: " << rectangle_object.getFrameRect().width
      << " / " << rectangle_object.getFrameRect().height
          << " / with the centre in point "
              << rectangle_object.getFrameRect().pos.x << " / "
                  << rectangle_object.getFrameRect().pos.y << std::endl;
  rectangle_object.showData();
  std::cout << "==================================" << std::endl;
  std::cout << "Let's try to move our rectangle by void move(double, double)!" << std::endl;
  
  rectangle_object.move(5,5);
  
  std::cout << "Rectangle width is " << rectangle_object.getWidth() << std::endl;
  std::cout << "Rectangle height is " << rectangle_object.getHeight() << std::endl;
  std::cout << "Rectangle centre position is "
      << rectangle_object.getPos().x
          << " // " << rectangle_object.getPos().y << std::endl;
  std::cout << "Rectangle area is " << rectangle_object.getArea() << std::endl;
  std::cout << "Frame rectangle is the same: "
      << rectangle_object.getFrameRect().width << " / "
          << rectangle_object.getFrameRect().height << " / with the centre in point "
              << rectangle_object.getFrameRect().pos.x << " / "
                  << rectangle_object.getFrameRect().pos.y << std::endl;
  rectangle_object.showData();
  std::cout << "==================================" << std::endl;

  std::cout << "Let's try to move our rectangle by void move(point_t)!" << std::endl;
  rectangle_object.move({30,30});

  std::cout << "Rectangle width is " << rectangle_object.getWidth() << std::endl;
  std::cout << "Rectangle height is " << rectangle_object.getHeight() << std::endl;
  std::cout << "Rectangle centre position is "
      << rectangle_object.getPos().x << " // "
          << rectangle_object.getPos().y << std::endl;
  std::cout << "Rectangle area is " << rectangle_object.getArea() << std::endl;
  std::cout << "Frame rectangle is the same: "
      << rectangle_object.getFrameRect().width << " / "
          << rectangle_object.getFrameRect().height << " / with the centre in point "
              << rectangle_object.getFrameRect().pos.x << " / "
                  << rectangle_object.getFrameRect().pos.y << std::endl;
  rectangle_object.showData();
  std::cout << "==================================" << std::endl;

  Circle circle_object(5, { 5,5 });

  std::cout << "Circle centre x is " << circle_object.getPos().x
      << " and y: " << circle_object.getPos().y << std::endl;
  std::cout << "Circle radius is " << circle_object.getRadius() << std::endl;
  std::cout << "Circle area is " << circle_object.getArea() << std::endl;
  std::cout << "Circle frame rectagle characteristics: " << std::endl;
  std::cout << "Width: " << circle_object.getFrameRect().width << std::endl;
  std::cout << "Height: " << circle_object.getFrameRect().height << std::endl;
  std::cout << "Position: " << circle_object.getFrameRect().pos.x
      << "," << circle_object.getFrameRect().pos.y << std::endl;
  circle_object.showData();

  std::cout << "==================================" << std::endl;
  std::cout << "Let's try to move circle centre by void(double, double)!" << std::endl;
  circle_object.move(7, 7);

  std::cout << "Circle centre x is " << circle_object.getPos().x
      << " and y: " << circle_object.getPos().y << std::endl;
  std::cout << "Circle radius is " << circle_object.getRadius() << std::endl;
  std::cout << "Circle area is " << circle_object.getArea() << std::endl;
  std::cout << "Circle frame rectagle characteristics: " << std::endl;
  std::cout << "Width: " << circle_object.getFrameRect().width << std::endl;
  std::cout << "Height: " << circle_object.getFrameRect().height << std::endl;
  std::cout << "Position: " << circle_object.getFrameRect().pos.x
      << "," << circle_object.getFrameRect().pos.y << std::endl;
  circle_object.showData();

  std::cout << "==================================" << std::endl;
  std::cout << "Let's try to move circle centre by void(point_t)!" << std::endl;
  circle_object.move({ 7, 7 });

  std::cout << "Circle centre x is " << circle_object.getPos().x
      << " and y: " << circle_object.getPos().y << std::endl;
  std::cout << "Circle radius is " << circle_object.getRadius() << std::endl;
  std::cout << "Circle area is " << circle_object.getArea() << std::endl;
  std::cout << "Circle frame rectagle characteristics: " << std::endl;
  std::cout << "Width: " << circle_object.getFrameRect().width << std::endl;
  std::cout << "Height: " << circle_object.getFrameRect().height << std::endl;
  std::cout << "Position: " << circle_object.getFrameRect().pos.x
      << "," << circle_object.getFrameRect().pos.y << std::endl;
  circle_object.showData();

  return 0;
}
