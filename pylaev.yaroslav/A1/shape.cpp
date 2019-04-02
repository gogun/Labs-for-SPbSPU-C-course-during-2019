#include "SHAPE.HPP"

Shape::Shape(const point_t &center):
  center_(center)
{}

void Shape::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
};

void Shape::move(const point_t &pos)
{
  center_ = pos;
}
