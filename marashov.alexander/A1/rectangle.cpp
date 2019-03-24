#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(float posX, float posY, float width, float height)
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

Rectangle::Rectangle(const point_t &pos, float width, float height)
{
  m_figure.height = height;
  m_figure.width = width;
  m_figure.pos = pos;
}

float Rectangle::getArea() const
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

void Rectangle::move(float dltX, float dltY)
{
  m_figure.pos.x += dltX;
  m_figure.pos.y += dltY;
}
