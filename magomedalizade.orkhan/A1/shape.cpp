#include "Shape.hpp"

Shape::Shape(const point_t &place):
  place_(place)
{
};

void Shape::move(const double dx, const double dy)
{
  place_.x = place_.x + dx;
  place_.y = place_.y + dy;
};

void Shape::move(point_t &a)
{
  place_ = a;
};
