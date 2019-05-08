#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const rectangle_t & figure):
  m_figure(figure)
{
  assert((figure.width > 0) && (figure.height > 0));
}

double Rectangle::getArea() const
{
  return m_figure.width * m_figure.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return m_figure;
}

void Rectangle::move(const point_t & pos)
{
  m_figure.pos = pos;
}

void Rectangle::move(double dx, double dy)
{
  m_figure.pos.x += dx;
  m_figure.pos.y += dy;
}

void Rectangle::showParams() const
{
  std::cout << "Rectangle: center - {" << m_figure.pos.x << ","
            << m_figure.pos.y << "}\nWidth - " << m_figure.width
            << "\nHeight - " << m_figure.height << '\n'
            << "Area - " << getArea() << '\n';
}
