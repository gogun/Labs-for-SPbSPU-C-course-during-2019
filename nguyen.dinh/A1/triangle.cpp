#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>

Triangle::Triangle(const point_t &corner_1, const point_t &corner_2, const point_t &corner_3):
  m_corner_1(corner_1),
  m_corner_2(corner_2),
  m_corner_3(corner_3),
  m_center({(m_corner_1.x + m_corner_2.x + m_corner_3.x) / 3, (m_corner_1.y + m_corner_2.y + m_corner_3.y) / 3})
{
  assert(getArea() > 0);
}

double Triangle::getArea() const
{
  return (std::fabs(m_corner_1.x - m_corner_3.x) * (m_corner_2.y - m_corner_3.y) - std::fabs(m_corner_2.x - m_corner_3.x) * (m_corner_1.y - m_corner_3.y)) / 2;
}

rectangle_t Triangle::getFrameRect() const
{
  const double maxX = std::max(std::max(m_corner_1.x, m_corner_2.x), m_corner_3.x);
  const double minX = std::min(std::min(m_corner_1.x, m_corner_2.x), m_corner_3.x);
  const double maxY = std::max(std::max(m_corner_1.y, m_corner_2.y), m_corner_3.y);
  const double minY = std::min(std::min(m_corner_1.y, m_corner_2.y), m_corner_3.y);
  const double width = maxX - minX;
  const double height = maxY - minY;
  const point_t position = {minX + width / 2, minY + height / 2};
  return {width, height, position};
}

void Triangle::move(const point_t &point)
{
  const double dx = point.x - m_center.x;
  const double dy = point.y - m_center.y;
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
  m_center.x += dx;
  m_center.y += dy;
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
