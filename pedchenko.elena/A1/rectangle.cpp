#include "rectangle.hpp"
#include <iostream>
#include <cassert>


Rectangle::Rectangle(const point_t & center, double width, double height):

  rect_({center, width, height})

{

  assert((width > 0.0) && (height > 0.0));

}



double Rectangle::getArea() const

{

  return rect_.height * rect_.width;

}



rectangle_t Rectangle::getFrameRect() const

{

  return rect_;

}



void Rectangle::move(double dx, double dy)

{

  rect_.pos.x += dx;

  rect_.pos.y += dy;

}



void Rectangle::move(const point_t & point)

{

  rect_.pos = point;

}

void Rectangle::writeInfo() const

{

  rectangle_t rectangle = getFrameRect();

  std::cout << "Information about the Rectangle: \n";

  std::cout << "Width: " << rectangle.width << "\n";

  std::cout << "Heigth: " << rectangle.height << "\n";

  std::cout << "Center: (" << rectangle.pos.x << "," << rectangle.pos.y << ") \n";

  std::cout << "Area: " << getArea() << "\n";

  std::cout << "Frame Rectangle: width = " << rectangle.width << " ,height = " << rectangle.height << "\n"

            << std::endl;

}

