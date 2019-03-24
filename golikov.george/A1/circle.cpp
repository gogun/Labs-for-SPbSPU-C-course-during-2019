#include "circle.hpp" 
#include <cmath> 
#include <iostream> 

/* Circle::Circle(double centerX, double centerY, double radius)
{ 
m_center.x = centerX; 
m_center.y = centerY; 
m_radius = radius; 
} */

/*Circle::Circle(point_t& center, double radius)
{ 
if (radius <= 0) 
{ 
std::cerr << "Circle: radius must be positive";
exit(1); 
} 
m_center = center; 
m_radius = radius; 
} */

double Circle::getArea() const
{
  return  M_PI * m_radius * m_radius;
}

rectangle_t Circle::getFrameRect() const
{
  return {m_center, m_radius * 2, m_radius * 2};
}

void Circle::move(const point_t &pos)
{
  m_center = pos;
}

void Circle::move(const double dltX, const double dltY)
{
  m_center.x += dltX;
  m_center.y += dltY;
}
