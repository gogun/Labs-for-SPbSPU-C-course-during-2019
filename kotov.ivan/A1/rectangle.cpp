#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(const point_t &pos, double width, double height):
  m_pos(pos),
  m_width(width),
  m_height(height)
{
  if(m_width <= 0) {
    std::cerr<< "width must be positive\n";
  }
  if(m_height <= 0) {
    std::cerr<< "height must be positive\n";
  }
}

double Rectangle::getArea() const
{
  return m_width * m_height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t 
  {
    m_width,
    m_height,
    m_pos
  };
}

void Rectangle::move(const point_t &pos)
{
  m_pos = pos;
}
  
void Rectangle::move(double dispX, double dispY)
{
  m_pos.x += dispX;
  m_pos.y += dispY;
}
