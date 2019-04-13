#include "rectangle.hpp"
#include <stdexcept>

kotov::Rectangle::Rectangle(const kotov::point_t & center, double widht, double heigth) :
  rect_({ center, widht, heigth})
{
  if ((rect_.width <= 0) || (rect_.height <= 0)) 
  {
    throw std::invalid_argument("Invalid width or height of rectangle");
  }
}

const char * kotov::Rectangle::getShapeName() const
{
  return "rectangle";
}

double kotov::Rectangle::getArea() const
{
  return rect_.height * rect_.width;
}

kotov::rectangle_t kotov::Rectangle::getFrameRect() const
{
  return rect_;
}

void kotov::Rectangle::move(const kotov::point_t & newCenter)
{
  rect_.pos = newCenter;
}
  
void kotov::Rectangle::move(double dX, double dY)
{
  rect_.pos.x += dX;
  rect_.pos.y += dY;
}

void kotov::Rectangle::scale(double scale)
{
  if (scale > 0) 
  {
    rect_.width *= scale;
    rect_.height *= scale;
  } 
  else 
  {
    throw std::invalid_argument("Invalid scale");
  }
}
