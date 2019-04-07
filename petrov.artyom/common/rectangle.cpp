#include "rectangle.hpp"
#include <stdexcept>

petrov::Rectangle::Rectangle(rectangle_t rectangle) :
  rectangle_(rectangle)
{
  if (rectangle.width <= 0)
  {
    throw std::invalid_argument("Width must be greater than 0");
  }
  if (rectangle.height <= 0)
  {
    throw std::invalid_argument("Height must be greater than 0");
  }
}

petrov::Rectangle::Rectangle(point_t centre, double width, double height) :
  Rectangle({width, height, centre})
{

}

double petrov::Rectangle::getArea() const
{
  return rectangle_.height * rectangle_.width;
}

petrov::rectangle_t petrov::Rectangle::getFrameRect() const
{
  return rectangle_;
}

void petrov::Rectangle::move(const point_t & centre)
{
  rectangle_.pos = centre;
}

void petrov::Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void petrov::Rectangle::scale(double scaleCoef)
{
  rectangle_.width *= scaleCoef;
  rectangle_.height *= scaleCoef;
}

petrov::point_t petrov::Rectangle::getCentre() const
{
  return rectangle_.pos;
}

double petrov::Rectangle::getWidth() const
{
  return rectangle_.width;
}

double petrov::Rectangle::getHeight() const
{
  return rectangle_.height;
}
