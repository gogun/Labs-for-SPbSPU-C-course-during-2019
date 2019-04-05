<<<<<<< HEAD
#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cassert>
#include <cmath>
=======
#include "circle.hpp"
#include <cassert>

const double pi =3.14159265359;
>>>>>>> 88285cbc9e7fb8678fba0deb06bb01127088a644

Circle::Circle(const double radius, const point_t &center) :
  radius_(radius),
  center_(center)
{
<<<<<<< HEAD
  assert(radius > 0.0);
=======
  assert(radius >= 0.0);
>>>>>>> 88285cbc9e7fb8678fba0deb06bb01127088a644
}

double Circle::getArea() const
{
<<<<<<< HEAD
  return  M_PI * radius_ * radius_;
=======
  return pi * radius_ * radius_;
>>>>>>> 88285cbc9e7fb8678fba0deb06bb01127088a644
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2 ,center_};
}

void Circle::move(const double dx, const double dy)
{
<<<<<<< HEAD
  center_.x += dx;
  center_.y += dy;
=======
  center_.x = dx;
  center_.y = dy;
>>>>>>> 88285cbc9e7fb8678fba0deb06bb01127088a644
}

void Circle::move(const point_t & newPos)
{
  center_ = newPos;
}
