#include "shape.hpp"

Shape::Shape(point_t cnt) : center_(cnt)
{
}

void Shape::move(const double dx,const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Shape::move(const point_t & newp)
{
  center_.x = newp.x;
  center_.y = newp.y;
}
