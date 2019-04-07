#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cmath> 
using namespace std;

Circle::Circle(const point_t &pos, const double radius_) :
  Shape(pos),
  radius_(radius_)
{
}

double Circle::getArea()
{
  return M_PI * radius_ * radius_;
}

const rectangle_t Circle::getFrameRect()
{
  rectangle_t cur = { radius_ * 2, radius_ * 2, pos_ };
  return cur;
}

void Circle::move(const point_t &NewCentre)
{
  pos_ = NewCentre;
}

void Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::print()
{
  cout << "Circle with the center ( " << pos_.x << pos_.y << " ) and Radius = " << radius_ << endl;
}
