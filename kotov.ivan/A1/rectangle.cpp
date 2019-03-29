#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const point_t &pos, double width, double height):
  m_rect({pos, width, height})
{
  if (m_rect.width <= 0) 
  {
    std::cerr << "width must be positive\n";
    assert(false);
  }
  if (m_rect.height <= 0) 
  {
    std::cerr << "height must be positive\n";
    assert(false);
  }
}

double Rectangle::getArea() const
{
  return m_rect.height * m_rect.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return m_rect;
}

void Rectangle::move(const point_t &pos)
{
  m_rect.pos = pos;
}
  
void Rectangle::move(double dispX, double dispY)
{
  m_rect.pos.x += dispX;
  m_rect.pos.y += dispY;
}
