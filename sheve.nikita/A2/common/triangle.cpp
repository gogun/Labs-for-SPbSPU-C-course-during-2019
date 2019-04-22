#include "triangle.hpp"
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <stdexcept>

sheve::Triangle::Triangle(const point_t &p1, const point_t &p2, const point_t &p3) :
m_pos({ (p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3 }),
m_a(p1),
m_b(p2),
m_c(p3)
{
  const double areaTriangle = getArea();
  if (areaTriangle <= 0.0) {
    throw std::invalid_argument("Triangle's argument is invalid.");
  }
}

double sheve::Triangle::getArea() const
{
  double area = ((m_b.x - m_a.x) * (m_c.y - m_a.y) - (m_c.x - m_a.x) * (m_b.y - m_a.y)) / 2;
  return area;
}

sheve::rectangle_t sheve::Triangle::getFrameRect() const
{
  double maxX = std::max(std::max(m_a.x, m_b.x), m_c.x);
  double maxY = std::max(std::max(m_a.y, m_b.y), m_c.y);
  double minX = std::min(std::min(m_a.x, m_b.x), m_c.x);
  double minY = std::min(std::min(m_a.y, m_b.y), m_c.y);
  double width = maxX - minX;
  double height = maxY - minY;
  return { { minX + width / 2, minY + height / 2 }, width, height };
}

void sheve::Triangle::move(const point_t &p)
{
  double dx = p.x - m_pos.x;
  double dy = p.y - m_pos.y;
  move(dx, dy);
}

void sheve::Triangle::move(const double dx, const double dy)
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

sheve::triangle_t sheve::Triangle::getSides() const
{
   const double sideAB = std::abs(
           std::sqrt(std::pow(m_a.x - m_b.x, 2) + std::pow(m_a.y - m_b.y, 2)));
   const double sideBC = std::abs(
           std::sqrt(std::pow(m_b.x - m_c.x, 2) + std::pow(m_b.y - m_c.y, 2)));
   const double sideCA = std::abs(
           std::sqrt(std::pow(m_c.x - m_a.x, 2) + std::pow(m_c.y - m_a.y, 2)));

   return {sideAB, sideBC, sideCA};
}

void sheve::Triangle::scale(double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Triangle's argument of scale is invalid.");
  }
  else
  {
    m_a = { m_pos.x + (m_a.x - m_pos.x) * coefficient, m_pos.y + (m_a.y - m_pos.y) * coefficient };
    m_b = { m_pos.x + (m_b.x - m_pos.x) * coefficient, m_pos.y + (m_b.y - m_pos.y) * coefficient };
    m_c = { m_pos.x + (m_c.x - m_pos.x) * coefficient, m_pos.y + (m_c.y - m_pos.y) * coefficient };
  }
}

void sheve::Rectangle::printInfo() const
{
  std::cout << "Center: " << m_pos.x << ", " << m_pos.y << std::endl;
  std::cout << "A: " << m_a << std::endl;
  std::cout << "B: " << m_b << std::endl;
  std::cout << "C: " << m_c << std::endl;
  std::cout << "Triangle area: " << getArea() << std::endl;
  std::cout << "Frame rectangle:" << std::endl;
  std::cout << "-Center: " << getFrameRect().pos.x << ", " << getFrameRect().pos.y << std::endl;
  std::cout << "-Width: " << getFrameRect().width << std::endl;
  std::cout << "-Height: " << getFrameRect().height << std::endl;
  std::cout << std::endl;
}
