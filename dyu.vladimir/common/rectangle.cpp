#include "rectangle.hpp"
#include <iostream>
#include <cassert>

dyu::Rectangle::Rectangle(double width, double height, const point_t &pos):
  rect_(rectangle_t {width, height, pos})
{
  if ((width < 0.0) || (height < 0.0))
  {
    throw std::invalid_argument("rectangle width or height is wrong");
  }
}

double dyu::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

dyu::rectangle_t dyu::Rectangle::getFrameRect() const
{
  return rect_;
}

void dyu::Rectangle::move(const point_t &pos)
{
  rect_.pos.x = pos.x;
  rect_.pos.y = pos.y;
}

void dyu::Rectangle::move(double x, double y)
{
  rect_.pos.x += x;
  rect_.pos.y += y;
}

void dyu::Rectangle::scale(double coeficient)
{
  if (coeficient < 0)
  {
    throw std::invalid_argument("coeficient is wrong");
  }
  rect_.width *= coeficient;
  rect_.height *= coeficient;
}
