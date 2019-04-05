#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "CompositeShape.hpp"

int main()
{
  std::cout << "new Circle with center: (14;56) and radius = 5" << std::endl;
  maschenko::Circle circle1({14, 56}, 5);
  std::cout << "new Circle with center: (-53;123) and radius = 9" << std::endl;
  maschenko::Circle circle2({-53, 123}, 9);
  std::cout << "new Circle with center: (59;413) and radius = 32" << std::endl;
  maschenko::Circle circle3({59, 413}, 32);

  std::cout << std::endl << "---------------------------------------------" << std::endl << std::endl;

  std::cout << "new Rectangle with center (-5;32) and width 2, height = 7" << std::endl;
  maschenko::Rectangle rectangle1({-5, 32}, 2, 7);
  std::cout << "new Rectangle with center (39;-58) and width 8, height = 10" << std::endl;
  maschenko::Rectangle rectangle2({39, -58}, 8, 10);
  std::cout << "new Rectangle with center (59;-72) and width 5, height = 15" << std::endl;
  maschenko::Rectangle rectangle3({59, -72}, 5, 15);

  maschenko::Shape *p_circle1 = &circle1;
  maschenko::Shape *p_circle2 = &circle2;
  maschenko::Shape *p_circle3 = &circle3;
  maschenko::Shape *p_rect1 = &rectangle1;
  maschenko::Shape *p_rect2 = &rectangle2;
  maschenko::Shape *p_rect3 = &rectangle3;

  CompositeShape composite_shape(p_circle1);
  composite_shape.addShape(p_rect1);
  composite_shape.addShape(p_circle2);
  composite_shape.addShape(p_rect2);
  composite_shape.addShape(p_circle3);
  composite_shape.addShape(p_rect3);
  composite_shape.writeInfo();

  std::cout << "move CompositeShape in point with center: (-34,32)" << std::endl;
  composite_shape.move({-34, 32});
  composite_shape.writeInfo();

  std::cout << "move CompositeShape at the dx = 2, dy = -4" << std::endl;
  composite_shape.move(2, -4);
  composite_shape.writeInfo();

  std::cout << "scale CompositeShape with coefficient = 4" << std::endl;
  composite_shape.scale(4);
  composite_shape.writeInfo();
  return 0;
}