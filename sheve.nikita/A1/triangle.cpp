#include "triangle.hpp"
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <cassert>

Triangle::Triangle(const point_t &p1, const point_t &p2, const point_t &p3) :
  m_pos({ (p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3 }),
  m_a(p1),
  m_b(p2),
  m_c(p3)
{
  assert(getArea() > 0);
}

double Triangle::getArea() const
{
  const double area = ((m_b.x - m_a.x) * (m_c.y - m_a.y) - (m_c.x - m_a.x) * (m_b.y - m_a.y)) / 2;
  return area;
}

rectangle_t Triangle::getFrameRect() const
{
  const double maxX = std::max(std::max(m_a.x, m_b.x), m_c.x);
  const double maxY = std::max(std::max(m_a.y, m_b.y), m_c.y); 
  const double minX = std::min(std::min(m_a.x, m_b.x), m_c.x); 
  const double minY = std::min(std::min(m_a.y, m_b.y), m_c.y);
  const double width = maxX - minX;
  const double height = maxY - minY;
  return { { minX + width / 2, minY + height / 2 }, width, height };
}
void Triangle::move(const point_t &p)
{
  const double dx = p.x - m_pos.x;
  const double dy = p.y - m_pos.y;
  move(dx, dy);
}

void Triangle::move(double dx, double dy)
{
  m_pos.x += dx;
  m_a.x += dx;
  m_b.x += dx;
  m_c.x += dx;
  m_pos.y += dy;
  m_a.y += dy;
  m_b.y += dy;
  m_c.y += dy;
}
