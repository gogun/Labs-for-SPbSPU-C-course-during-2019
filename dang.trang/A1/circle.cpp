#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle (double rCircle, const point_t &cpoint):
  rCircle_(rCircle),
  pos_(cpoint)
{
  assert(rCircle > 0);
}

double Circle::getArea() const
{
  return M_PI * rCircle_* rCircle_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2 * rCircle_, 2 * rCircle_, pos_};
}

void Circle::move(double mX, double mY)
{
  pos_.x += mX;
  pos_.y += mY;
}

void Circle::move(const point_t &point)
{
  pos_ = point;
}

void Circle::printInfo() const
{
  std::cout << "area_of_circle_=" << getArea()
    << "\n  Radius: " << rCircle_
    << "position_X_Y_" << pos_.x << " " << pos_.y << std::endl;
}

