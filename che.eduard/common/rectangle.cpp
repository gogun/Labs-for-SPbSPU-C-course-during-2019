#include "rectangle.hpp"
#include <stdexcept>

using namespace che;

che::Rectangle::Rectangle(const rectangle_t & rect):
  rectangle_(rect)
{
  if ((rectangle_.height < 0) || (rectangle_.width < 0)) 
  {
  throw std::invalid_argument("rectangle width and height can not be negative");
  }

}

double che::Rectangle::getArea() const
{
  return rectangle_.height * rectangle_.width;
}

che::rectangle_t che::Rectangle::getFrameRect() const
{
  return rectangle_;
}

void che::Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void che::Rectangle::move(const point_t & point)
{
  rectangle_.pos = point;
}

void che::Rectangle::scale(double coef)
{
  if (coef <= 0)
  {
	throw std::invalid_argument("Negativ parameter");
  }
  rectangle_.height *= coef;
  rectangle_.width *= coef;
}

