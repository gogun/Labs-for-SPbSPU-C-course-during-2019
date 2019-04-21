#include "rectangle.hpp"
#include <iostream>
#include <assert.h> 

troshev::Rectangle::Rectangle(const point_t &pos, double w, double h) :
	rectangle_({ pos, w, h })
{
  if ((rectangle_.height <= 0) || (rectangle_.width <= 0))
  {
    throw std::invalid_argument("Not positive parametrs");
  }
}


double troshev::Rectangle::getArea() const
{
  return rectangle_.height * rectangle_.width;
}

troshev::rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void troshev::Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void troshev::Rectangle::move(const point_t &point)
{
  rectangle_.pos = point;
}

void troshev::Rectangle::getInfo() const
{
  rectangle_t rec_ = getFrameRect();
  std::cout << "Point x : " << rec_.pos.x << std::endl;
  std::cout << "Point y : " << rec_.pos.y << std::endl;
  std::cout << "Rectangle height : " << rec_.height << std::endl;
  std::cout << "Rectangle width : " << rec_.width << std::endl;

}

void troshev::Rectangle::scale(double number)
{
  if (number <= 0)
  {
    throw std::invalid_argument("Not positive parametrs");
  }
  rectangle_.height *= number;
  rectangle_.width *= number;
}
