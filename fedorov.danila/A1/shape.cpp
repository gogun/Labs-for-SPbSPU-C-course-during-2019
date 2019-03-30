#include "shape.hpp"

#include <iostream>
#include <cassert>



Shape::Shape(const point_t &position) :
  position_(position)
{}

void Shape::printInfo() const
{
  std::cout << "\t center: (" << position_.x << ";" << position_.y << ")" << std::endl;
}

void Shape::move(const point_t &point)
{
  position_ = point;
  assert(position_.x > 0 && position_.y > 0);
}

void Shape::move(double dx, double dy)
{
  position_.x += dx;
  position_.y += dy;
  assert(position_.x > 0 && position_.y > 0);
}
