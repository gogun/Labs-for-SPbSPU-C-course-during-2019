#include <iostream>
#include "shape.hpp"

Shape::Shape(const point_t & pos):
  m_pos(pos)
{}

void Shape::printData() const
{
  this -> printFeatures();

  std::cout << "x: " << this -> m_pos.x << "\n"
    << "y: " << this -> m_pos.y << "\n"
    << "area: " << this -> printArea() << "\n";

  rectangle_t frameRect = this -> printFrameRect();

  std::cout << "framing rectangle:\n"
    << "  width: " << frameRect.width << "\n"
    << "  height: " << frameRect.height << "\n"
    << "  x: " << frameRect.pos.x << "\n"
    << "  y: " << frameRect.pos.y << "\n";
}
