#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(rectangle_t in_rect) :
  rect_(in_rect)
{
  if ((rect_.width <= 0) || (rect_.height <= 0))
  {
    std::cerr << "Invalid width of height of rectangle." << std::endl;
  }
}

Rectangle::Rectangle(double posX, double posY, double width, double height)
{
  rect_.pos.x = posX;
  rect_.pos.y = posY;
  rect_.width = width;
  rect_.height = height;
}

double Rectangle::getArea() const
{
  return (rect_.width) * (rect_.height);
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(point_t goal)
{
  rect_.pos = goal;
}

void Rectangle::move(double dx, double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void Rectangle::show() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << std::endl << "Coordinates of centre Rect :(" << rect_.pos.x
  << ";" << rect_.pos.y << ")" << std::endl
  << "Frame rectangle width = " << rectangle.width
  << ", height = " << rectangle.height << std::endl
  << "Area = " << getArea() << std::endl;
}

