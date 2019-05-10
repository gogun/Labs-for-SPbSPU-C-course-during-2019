#include "circle.hpp"

#include <cmath>
#include <cassert>

Circle::Circle(const double radius, const point_t& pos):
  centre_(pos),
  radius_(radius)
{
  assert(radius_ > 0);
}

double Circle::getArea() const
{
  return M_PI * pow(radius_, 2);
}

rectangle_t Circle::getFrameRect() const
{
  double diametr = 2 * radius_;
  return {diametr, diametr, centre_};
}

void Circle::move(const point_t& point)
{
  centre_ = point;
}

void Circle::move(const double dx, const double dy)
{
  centre_.x += dx;
  centre_.y += dy;
}

std::string Circle::getName() const
{
  return "Circle";
}
