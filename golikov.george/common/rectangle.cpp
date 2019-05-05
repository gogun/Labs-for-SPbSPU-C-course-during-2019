#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>

golikov::Rectangle::Rectangle(const rectangle_t & figure):
  m_figure(figure)
{
  if ((figure.width <= 0) || (figure.height <= 0))
  {
    throw std::invalid_argument("Rectangle's width or height cannot be negative");
  }
}

double golikov::Rectangle::getArea() const
{
  return m_figure.width * m_figure.height;
}

golikov::rectangle_t golikov::Rectangle::getFrameRect() const
{
  return m_figure;
}

void golikov::Rectangle::move(const point_t & pos)
{
  m_figure.pos = pos;
}

void golikov::Rectangle::move(double dx, double dy)
{
  m_figure.pos.x += dx;
  m_figure.pos.y += dy;
}

void golikov::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Wouldn't multiply on a negative coefficient");
  }
  else
  {
    m_figure.height *= coefficient;
    m_figure.width *= coefficient;
  }
}

void golikov::Rectangle::showParams() const
{
  std::cout << "Rectangle: center - {" << m_figure.pos.x << ","
            << m_figure.pos.y << "}\n" << "Width - " << m_figure.width
            << '\n' << "Height - " << m_figure.height << '\n'
            << "Area - " << getArea() << '\n';
}
