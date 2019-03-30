#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t & center, double width, double height) :
  m_rect_({center, width, height})
{
  if (m_rect_.width <= 0) 
  {
    std::cerr << "width must be positive\n";
    assert(false);
  }
  if (m_rect_.height <= 0) 
  {
    std::cerr << "height must be positive\n";
    assert(false);
  }
}

double Rectangle::getArea() const
{
  return m_rect_.height * m_rect_.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return m_rect_;
}

void Rectangle::move(const point_t & newCenter)
{
  m_rect_.pos = newCenter;
}
  
void Rectangle::move(double dispX, double dispY)
{
  m_rect_.pos.x += dispX;
  m_rect_.pos.y += dispY;
}
