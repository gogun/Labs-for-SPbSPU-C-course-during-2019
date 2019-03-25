#include "circle.hpp"
#include <cmath>

Circle::Circle(const point_t & pos, double radius) : 
  m_pos(pos)
{
  if(radius < 0) {
    m_radius = - radius;
  } else {
    m_radius = radius;
  }
}

         
double Circle::getArea() const
{ 
  return M_PI * m_radius * m_radius;
}
  
rectangle_t Circle::getFrameRect() const
{
  return rectangle_t {
    2 * m_radius, 
    2 * m_radius, 
    m_pos
  };
}
  
void Circle::move(const point_t & pos)  
{
  m_pos = pos;
}
  
void Circle::move(double dispX, double dispY)  
{
  m_pos.x += dispX;
  m_pos.y += dispY;
}
