#include "rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(const rectangle_t& figure):
  m_figure(figure)
{
  assert((figure.width > 0) && (figure.height > 0));
}

double Rectangle::getArea() const
{
<<<<<<< HEAD
  return m_figure.width * m_figure.height;
=======
  return m_figure.width* m_figure.height;
>>>>>>> 8405d27ad9ed79ce78febe68465bc0967796a1cb
}

rectangle_t Rectangle::getFrameRect() const
{
  return m_figure;
}

void Rectangle::move(const point_t& pos)
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
<<<<<<< HEAD
            << m_figure.pos.y << "}\n" << "Width - " << m_figure.width
            << '\n' << "Height - " << m_figure.height << '\n'
            << "Area - " << getArea() << '\n';
=======
      << m_figure.pos.y << "}\n" << "Width - " << m_figure.width
      << '\n' << "Height - " << m_figure.height << '\n'
      << "Area - " << getArea() << '\n';
>>>>>>> 8405d27ad9ed79ce78febe68465bc0967796a1cb
}
