#include "circle.hpp"
#include <iostream>
#include <cassert>
#include<math.h>

Circle::Circle(const double & radius, const point_t & point) :
  radius_(radius),
  pos_(point)
{
  assert(radius > 0.0);
}

double Circle::getArea() const
{
  return (M_PI * (radius_ * radius_));
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, pos_};
}

void Circle::move(const double & dX, const double & dY)
{
  pos_.x += dX;
  pos_.y += dY;
}

void Circle::move(const point_t & point)
{
  pos_ = point;
}

void Circle::showInfo() const
{
  std::cout << "Information about circle\n";
  showCords();
  std::cout << "Area: " << getArea() << "\n";
}

void Circle::showCords() const
{
  std::cout << "Center: ";
  std::cout << "\n X: " << pos_.x;
  std::cout << "\n Y: " << pos_.y << "\n";
}

void Circle::showFrameRect() const
{
  rectangle_t rect = getFrameRect();
  std::cout << "\nBounded rectangle";
  std::cout << "\nWidth: " << rect.width;
  std::cout << "\nHeight: " << rect.height << "\n";
  showCords();
}
