#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>

Triangle::Triangle(const point_t &p1, const point_t &p2, const point_t &p3) :
  A_(p1),
  B_(p2),
  C_(p3)
{
  assert(getArea() > 0.0);
}

double Triangle::getArea() const
{
  double AB = getDistance(A_, B_);
  double AC = getDistance(A_, C_);
  double BC = getDistance(B_, C_);
  double halfP = (AB + AC + BC) / 2;
  return sqrt(halfP * (halfP - AB) * (halfP - AC) * (halfP - BC));
}

rectangle_t Triangle::getFrameRect() const
{
  double left = std::min(std::min(A_.x, B_.x), C_.x);
  double bot = std::min(std::min(A_.y, B_.y), C_.y);
  double height = std::abs(std::max(std::max(A_.y, B_.y), C_.y) - bot);
  double width = std::abs(std::max(std::max(A_.x, B_.x), C_.x) - left);
  return {width, height, findCenter()};
}

void Triangle::move(const point_t &pos)
{
  move(pos.x - findCenter().x, pos.y - findCenter().y);
}

void Triangle::move(double dx, double dy)
{
  A_.x += dx;
  B_.x += dx;
  C_.x += dx;
  A_.y += dy;
  B_.y += dy;
  C_.y += dy;
}

point_t Triangle::findCenter() const
{
  return point_t{(A_.x + B_.x + C_.x) / 3, (A_.y + B_.y + C_.y) / 3};
}

double Triangle::getDistance(const point_t &p1, const point_t &p2)
{
  return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

void Triangle::printInfo() const
{
  point_t center_ = findCenter();
  rectangle_t frame = getFrameRect();
  std::cout << "Triangle:"
      << std::endl << "  The apex coordinates of the triangle: "
      << std::endl << "    A {" << A_.x << "," << A_.y << "}"
      << std::endl << "    B {" << B_.x << "," << B_.y << "}"
      << std::endl << "    C {" << C_.x << "," << C_.y << "}"
      << std::endl << "  Center: "
      << std::endl << "    x: " << center_.x
      << std::endl << "    y: " << center_.y
      << std::endl << "  Frame rectangle for the triangle: "
      << std::endl << "    Width: " << frame.width
      << std::endl << "    Height: " << frame.height
      << std::endl << "  Area: " << this->getArea()
      << std::endl << std::endl;
}
