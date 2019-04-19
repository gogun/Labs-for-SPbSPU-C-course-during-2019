#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Circle::Circle (double Rcircle, const point_t &cpoint):
  cR_(Rcircle),
  pos_(cpoint)
{
  assert(Rcircle > 0);
}

double Circle::getArea() const
{
  return M_PI * cR_ * cR_;
}

rectangle_t Circle::getFrameRect() const
{
  return {2.0 * cR_, 2.0 * cR_, pos_};
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
  std::cout << "area_of_circle_=" << this->getArea() << std::endl
			<< "\n  Radius: " << cR_
			<< "position_X_Y_" << pos_.x << " " << pos_.y << std::endl;
}

