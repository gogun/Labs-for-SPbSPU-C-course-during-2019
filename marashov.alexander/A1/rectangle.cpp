#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double posX, double posY, double width, double height)
{
  if (width <= 0 || height <= 0)
  {
    std::cerr << "Rectangle: width and height must be positive";
    exit(1);
  }
  m_figure.height = height;
  m_figure.width = width;
  m_figure.pos.x = posX;
  m_figure.pos.y = posY;
}

Rectangle::Rectangle(const point_t &pos, double width, double height)
{
  m_figure.height = height;
  m_figure.width = width;
  m_figure.pos = pos;
}

double Rectangle::getArea() const
{
  return m_figure.width * m_figure.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return m_figure;
}

point_t Rectangle::getCenter() const
{
  return m_figure.pos;
}

void Rectangle::move(const point_t& pos)
{
  m_figure.pos.x = pos.x;
  m_figure.pos.y = pos.y;
}

void Rectangle::move(double dltX, double dltY)
{
  m_figure.pos.x += dltX;
  m_figure.pos.y += dltY;
}
