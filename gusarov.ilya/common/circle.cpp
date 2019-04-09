#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>
#include "base-types.hpp"


gusarov::Circle::Circle(const point_t &center, const double radius):
  radius_(radius),
  center_(center)
{
  assert(radius >= 0);
}
double gusarov::Circle::getArea() const
{
  return M_PI*pow(radius_, 2);
}
gusarov::rectangle_t gusarov::Circle::getFrameRect() const
{
  return {radius_*2, radius_*2, center_};
}
void gusarov::Circle::move(const double shiftX,const double shiftY)
{
  center_.x += shiftX;
  center_.y += shiftY;
}
void gusarov::Circle::move(const point_t &newPoint)
{
  center_ = newPoint;
}
void gusarov::Circle::printInfo() const
{
  std::cout << "Radius of circle is " << radius_ <<'\n'
            << "Center of circle is a point: ("<< center_.x<<";"<<center_.y<<")"<<'\n';
}
void gusarov::Circle::scale(double scale)
{
  assert(scale > 0);
  radius_ *= scale;
}
