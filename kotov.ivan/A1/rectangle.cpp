#include "rectangle.hpp"

Rectangle::Rectangle(const point_t &pos, const double width, const double height)
{
  m_pos = pos;
  m_width = width;
  m_height = height;
}

double Rectangle::getArea() const
{ 
  return m_width * m_height;
}
  
rectangle_t Rectangle::getFrameRect() const 
{
  return rectangle_t {m_width, m_height, m_pos};
}
  
void Rectangle::move(const point_t &pos)  
{
  m_pos = pos;
}
  
void Rectangle::move(const double dispX, const double dispY)  
{
  m_pos.x += dispX;
  m_pos.y += dispY;
}
