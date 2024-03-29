#include "triangle.hpp"

#include <iostream>
#include <math.h>
#include <cassert>
#include <algorithm>

Triangle::Triangle(const point_t & vA, const point_t & vB, const point_t & vC) :
  pos_({ (vA.x + vB.x + vC.x) / 3, (vA.y + vB.y + vC.y) / 3 }),
  vA_(vA),
  vB_(vB),
  vC_(vC)
{
  const double areaTriangle = getArea();
  assert(areaTriangle >= 0.0);
}

double Triangle::getArea() const
{
  return (std::fabs(vA_.x - vC_.x) * (vB_.y - vC_.y)
      - std::fabs(vB_.x - vC_.x) * (vA_.y - vC_.y)) / 2;
}

rectangle_t Triangle::getFrameRect() const
{
  const double maxX = std::max(std::max(vA_.x, vB_.x), vC_.x);
  const double minX = std::min(std::min(vA_.x, vB_.x), vC_.x);
  const double maxY = std::max(std::max(vA_.y, vB_.y), vC_.y);
  const double minY = std::min(std::min(vA_.y, vB_.y), vC_.y);
  const double width = maxX - minX;
  const double height = maxY - minY;
  const point_t position = { minX + width / 2, minY + height / 2 };
  return { width, height, position };
}

void Triangle::print() const
{
  std::cout << "Area of triangle: " << getArea() << std::endl;
  std::cout << "Width of frame rectangle: " << getFrameRect().width
    << std::endl;
  std::cout << "Height of frame rectangle: " << getFrameRect().height
    << std::endl;
  std::cout << "Triangle's A : (" << vA_.x << ';' << vA_.y << ')'
    << std::endl;
  std::cout << "Triangle's B : (" << vB_.x << ';' << vB_.y << ')'
    << std::endl;
  std::cout << "Triangle's C : (" << vC_.x << ';' << vC_.y << ')'
    << std::endl;
  std::cout << "Triangle's center : (" << pos_.x << ';' << pos_.y << ')'
    << std::endl;
}

void Triangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
  vA_.x += dx;
  vA_.y += dy;
  vB_.x += dx;
  vB_.y += dy;
  vC_.x += dx;
  vC_.y += dy;
}

void Triangle::move(const point_t & nPos)
{
  const point_t diff = { nPos.x - pos_.x, nPos.y - pos_.y };
  move(diff.x, diff.y);
}
