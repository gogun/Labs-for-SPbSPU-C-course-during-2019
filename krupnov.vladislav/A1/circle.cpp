#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>



Circle::Circle(const double &x, const double &y, const double &R) :
  posx_(x),
  posy_(y),
  r_(R)
{
  assert(r_ > 0);
}

double Circle::getArea() const
{
  return M_PI * r_ * r_;
}

double Circle::getRadius() const
{
  return r_;
}

rectangle_t Circle::getFrameRect() const
{
  return { 2 * r_, 2 * r_, center_ };
}

void Circle::setRadius(const double &R)
{
  assert(R > 0);
  r_ = R;
}

void Circle::move(const point_t &p)
{
  center_.x = p.x;
  center_.y = p.y;
}

void Circle::move(const double &x, const double &y)
{
  center_.x += x;
  center_.y += y;
}

void Circle::printInfo() const
{
  std::cout << "\n**********************\n";
  std::cout << "circle info:\ncenter=(" << center_.x << ";" << center_.y << ") \nradius=" << r_ << "\n"
    << "CIRCLE S=" << getArea() << "\n" << "FrameRect: width=" << getFrameRect().width
    << ",heigth=" << getFrameRect().height << ",pos=(" << getFrameRect().pos.x << ";"
    << getFrameRect().pos.y << ")\n";
  std::cout << "**********************\n";
}

void Circle::getCenterInfo() const
{
  std::cout << "Center X: " << posx_ << "Center Y: " << posy_;
}
