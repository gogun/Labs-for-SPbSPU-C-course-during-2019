#include "shape.hpp"

#include <iostream>
#include <cassert>

Shape::Shape(const point_t &position):
  position_(position)
{}

void Shape::printInfo() const
{
  std::cout << "\t center: (" << position_.x << ";" << position_.y << ")" << std::endl;
}

void Shape::move(const point_t &point)
{
  position_ = point;
}

void Shape::move(const double dx, const double dy)
{
  position_.x += dx;
  position_.y += dy;
}
