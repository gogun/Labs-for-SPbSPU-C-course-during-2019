#include <cmath>
#include <iostream>
#include <algorithm>
#include "triangle.hpp"

Triangle::Triangle(const point_t &corner_1,const point_t &corner_2,const point_t &corner_3):
  m_corner_1(corner_1),
  m_corner_2(corner_2),
  m_corner_3(corner_3),
  m_center({(m_corner_1.x + m_corner_2.x + m_corner_3.x) / 3, (m_corner_1.y + m_corner_2.y + m_corner_3.y) / 3})
{
  assert(getArea() > 0);
}

double Triangle::getArea() const
{
  const double side1 = sqrt(pow(m_corner_1.x - m_corner_2.x, 2) + pow(m_corner_1.y - m_corner_2.y, 2));
  const double side2 = sqrt(pow(m_corner_1.x - m_corner_3.x, 2) + pow(m_corner_1.y - m_corner_3.y, 2));
  const double side3 = sqrt(pow(m_corner_2.x - m_corner_3.x, 2) + pow(m_corner_2.y - m_corner_3.y, 2));
  const double perimeter = side1 + side2 + side3;
  const double radius = sqrt(((perimeter  / 2 - side1) * (perimeter / 2 - side2) * (perimeter / 2 - side3)) / (perimeter / 2));
  
  return radius * perimeter  / 2 ;
}

rectangle_t Triangle::getFrameRect() const
{
  const double minheight = std::min(std::min(m_corner_1.y, m_corner_2.y), m_corner_3.y);
  const double minwidth = std::min(std::min(m_corner_1.x, m_corner_2.x), m_corner_3.x);
  const double maxheight = std::max(std::min(m_corner_1.y, m_corner_2.y), m_corner_3.y);
  const double maxwidth = std::max(std::min(m_corner_1.x, m_corner_2.x),m_corner_3.x);
  
  point_t center{ minwidth + (maxwidth - minwidth) / 2 , minheight + (maxheight - minheight) / 2 };
  
  return {maxwidth - minwidth, maxheight - minheight, center};
}

void Triangle::move(const point_t &pos)
{
  const double dx = pos.x - m_center.x;
  const double dy = pos.y - m_center.y;
  move(dx, dy);
  
}

void Triangle::move(const double dx, const double dy)
{
  m_corner_1.x += dx;
  m_corner_2.x += dx;
  m_corner_3.x += dx;
  m_corner_1.y += dy;
  m_corner_2.y += dy;
  m_corner_3.y += dy;
  
  m_center.x = (m_corner_1.x + m_corner_2.x + m_corner_3.x) / 3;
  m_center.y = (m_corner_1.y + m_corner_2.y + m_corner_3.y) / 3;
}

void Triangle::printInfo() const
{
  std::cout << "Triangle" << std::endl << "Corner 1 (" << m_corner_1.x << "; " << m_corner_1.y
  << ")" << std::endl << "Corner 2 (" << m_corner_2.x << "; " << m_corner_2.y << ")" << std::endl
  << "Corner 3 (" << m_corner_3.x << "; " << m_corner_3.y << ")" << std::endl << "Center: ("
  << m_center.x << "; " << m_center.y << ")" << std::endl << "Area: " << getArea() << std::endl
  << "Rectangle Frame:" << std::endl << "Width = " << getFrameRect().width << " Height = "
  << getFrameRect().height << std::endl << "Center: (" << getFrameRect().pos.x << "; "
  << getFrameRect().pos.y << ")" << std::endl << std::endl;
}
