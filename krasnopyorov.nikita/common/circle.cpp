#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <math.h>
#include <stdexcept>

krasnopyorov::Circle::Circle(double radius, point_t dot):
  centre_(dot),
  r_(radius)
{
  if (r_ <= 0)
  {
    throw std::invalid_argument("Inccorect radius");
  }
}

double krasnopyorov::Circle::getArea() const
{
  return M_PI * r_ * r_;
}

double krasnopyorov::Circle::getRadius() const
{
  return r_;
}

krasnopyorov::rectangle_t krasnopyorov::Circle::getFrameRect() const
{
  return {2 * r_, 2 * r_, centre_};
}

void krasnopyorov::Circle::move(double deltax, double deltay)
{
  centre_.x += deltax;
  centre_.y += deltay;
}

void krasnopyorov::Circle::move(const point_t &dot)
{
  centre_ = dot;
}

void krasnopyorov::Circle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Inccorect scaling coefficient");
  }
  r_ *= k;
}

void krasnopyorov::Circle::writeChanges() const
{
  std::cout << "New coordinates of centre (" << centre_.x << "," << centre_.y << ")" << "\n";
}
