#include "shape.hpp"
#include <iostream>

Shape::Shape(point_t pos):
  pos_(pos)
{}

void Shape::displayData() const
{
  std::cout << "\nPosition: (" << pos_.x << ';' << pos_.y << ')';
}

void Shape::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Shape::move(point_t dot)
{
  pos_ = dot;
}
