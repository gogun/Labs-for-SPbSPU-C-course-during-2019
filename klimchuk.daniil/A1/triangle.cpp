#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

Triangle::Triangle(double side1, double side2, double side3, const point_t &center) :
  side1_(side1),
  side2_(side2),
  side3_(side3),
  pos_(center)
{
  assert((side1_ > 0) && (side2_ > 0) && (side3_ > 0));
  assert((side3_ + side2_) > side1_);
  assert((side1_ + side3_) > side2_);
  assert((side2_ + side1_) > side3_);
}

double Triangle::getArea() const
{
  double halfP = (side1_ + side2_ + side3_) / 2;
  return sqrt(halfP * (halfP - side1_) * (halfP - side2_) * (halfP - side3_));
}

rectangle_t Triangle::getFrameRect() const
{
  double area = Triangle::getArea();
  return {side1_, area * 2 / side1_, pos_};
}

void Triangle::move(const point_t &pos)
{
  pos_ = pos;
}

void Triangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Triangle::printInfo() const
{
  std::cout << "Triangle:"
      << std::endl << "  Side 1: " << side1_
      << std::endl << "  Side 2: " << side2_
      << std::endl << "  Side 3: " << side3_
      << std::endl << "  Position: "
      << std::endl << "    x: " << pos_.x
      << std::endl << "    y: " << pos_.y
      << std::endl << "  Area: " << this->getArea()
      << std::endl << std::endl;
}
