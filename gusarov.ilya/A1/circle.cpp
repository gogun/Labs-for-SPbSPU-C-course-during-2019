#define _USE_MATH_DEFINES
#include "circle.hpp"
#include "base-types.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Circle::Circle(const point_t &center, const double radius):
  radius_(radius),
  center_(center)
{
  assert(radius >= 0);
}
double Circle::getArea() const
{
  return M_PI*pow(radius_, 2);
}
rectangle_t Circle::getFrameRect() const
{
  return {radius_*2, radius_*2, center_};
}
void Circle::move(const double shiftX,const double shiftY)
{
  center_.x += shiftX;
  center_.y += shiftY;
}
void Circle::move(const point_t &newPoint)
{
  center_ = newPoint;
}
void Circle::printInfo() const
{
  std::cout << "Radius of circle is " << radius_ <<'\n'
            << "Center of circle is a point: ("<< center_.x<<";"<<center_.y<<")"<<'\n';
}
