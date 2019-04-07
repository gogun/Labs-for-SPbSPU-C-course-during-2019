#include "rectangle.hpp"
#include <iostream>
#include <assert.h> 

Rectangle::Rectangle(const point_t &pos, double w, double h) :
  rectangle_({ pos, w, h })
{
  if ((rectangle_.height <= 0) || (rectangle_.width <= 0))
  {
    throw std::invalid_argument("Not positive parametrs");
  }
}

double Rectangle::getArea() const
{
  return rectangle_.height * rectangle_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::move(const point_t &point)
{
  rectangle_.pos = point;
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void Rectangle::getInfo() const
{
  rectangle_t rectangle = getFrameRect();
  std::cout << "Rectangle height = " << rectangle.height << std::endl;
  std::cout << "Rectangle width = " << rectangle.width << std::endl;
  std::cout << "Point x = " << rectangle.pos.x << std::endl;
  std::cout << "Point y = " << rectangle.pos.y << std::endl;
}

void trofimov::Rectangle::scale(double cScaling)
{
  if (cScaling <= 0)
    {
	  throw std::invalid_argument("Not positive parametrs");
	}
  rectangle_.height *= cScaling;
  rectangle_.width *= cScaling;
}
