#include "Rectangle.hpp"
#include <iostream>
#include <stdexcept>

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(rectangle_t in_rect) :
rect_(in_rect)
{
}

Rectangle::Rectangle(double xx, double yy, double width, double height)
{
  rect_.pos.x = xx;
  rect_.pos.y = yy;
  rect_.width = width;
  rect_.height = height;
}
<<<<<<< HEAD
=======
/*
Rectangle::~Rectangle()
{
}*/
>>>>>>> 21efff2bf96f287fe3008cc78e0d089cb8fec88f

double Rectangle::getArea() const
{
  return (rect_.width)*(rect_.height);
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
  std::cout << "\nRectangle center: " << rect_.pos.x << " , " << rect_.pos.y << std::endl;
  std::cout << "Width:" << rect_.width << "\nHeight: " << rect_.height << std::endl;
}
