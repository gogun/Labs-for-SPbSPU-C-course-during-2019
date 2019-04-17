#include "rectangle.hpp"
#include <stdexcept>

stebnevsky::Rectangle::Rectangle(const rectangle_t & rect_init):
  m_rect(rect_init)
{
  if ((m_rect.width <= 0.0) || (m_rect.height <= 0.0))
  {
    throw std::invalid_argument("Width and height of rectangle must be greater than zero");
  }
}

double stebnevsky::Rectangle::getArea() const
{
  return m_rect.height * m_rect.width;
}

stebnevsky::rectangle_t stebnevsky::Rectangle::getFrameRect() const
{
  return m_rect;
}

void stebnevsky::Rectangle::move(const point_t & point)
{
  m_rect.pos = point;
}

void stebnevsky::Rectangle::move(double dx, double dy)
{
  m_rect.pos.x += dx;
  m_rect.pos.y += dy;
}

void stebnevsky::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient of scaling must be greater than zero");
  }
  m_rect.width *= coefficient;
  m_rect.height *= coefficient;
}
