#include <cassert>
#include <iostream>
#include <math.h>
#include "rectangle.hpp"
#include "triangle.hpp"

Triangle::Triangle(const point_t &first, const point_t &second, const point_t &third) :
    first_(first),
    second_(second),
    third_(third)
{

  pos_.x = (first.x + second.x + third.x) / 3;
  pos_.y = (first.y + second.y + third.y) / 3;

  a_ = sqrt((first_.x - second_.x) * (first_.x - second_.x)
            + (first_.y - second_.y) * (first_.y - second_.y));
  b_ = sqrt((third_.x - second_.x) * (third_.x - second_.x)
            + (third_.y - second_.y) * (third_.y - second_.y));
  c_ = sqrt((first_.x - third_.x) * (first_.x - third_.x)
            + (first_.y - third_.y) * (first_.y - third_.y));

  assert(a_ != 0 && b_ != 0 && c_ != 0);
}

double Triangle::getArea() const {

  double p = (a_ + b_ + c_) / 2;

  return sqrt(p * (p - a_) * (p - b_) * (p - c_));
}

void Triangle::writeInfo() const {
  std::cout << "Triangle info:\n"
            << "A side length - " << a_ << "\n"
            << "B side length - " << b_ << "\n"
            << "C side length - " << c_ << "\n"
            << "Center position: x = " << pos_.x << ", y = " << pos_.y << "\n"
            << "Area - " << getArea() << "\n\n";
}

rectangle_t Triangle::getFrameRect() const {

  double maxX = std::max(first_.x, std::max(second_.x, third_.x));
  double maxY = std::max(first_.y, std::max(second_.y, third_.y));

  double minX = std::min(first_.x, std::min(second_.x, third_.x));
  double minY = std::min(first_.y, std::min(second_.y, third_.y));

  double a = maxX - minX;
  double b = maxY - minY;
  return {pos_, a, b};
}

void Triangle::move(const point_t &pos) {
  const double dx = pos.x - pos_.x;
  const double dy = pos.y - pos_.y;
  move(dx, dy);
}

void Triangle::move(const double dx, const double dy) {
  pos_.x += dx;
  pos_.y += dy;

  first_.x += dx;
  first_.y += dy;

  second_.x += dx;
  second_.y += dy;

  third_.x += dx;
  third_.y += dy;
}
