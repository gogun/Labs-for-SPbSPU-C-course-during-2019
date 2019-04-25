#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>

Triangle::Triangle(const point_t a, const point_t b, const point_t c):
  a_(a),
  b_(b),
  c_(c)
{
}

point_t Triangle::getCenter() const
{
  return point_t {(a_.x + b_.x + c_.x) / 3, (a_.y + b_.y + c_.y) / 3};
}

double Triangle::getArea() const
{
  const double ab = sqrt(pow(a_.x - b_.x, 2) + pow(a_.y - b_.y, 2));
  const double bc = sqrt(pow(c_.x - b_.x, 2) + pow(c_.y - b_.y, 2));
  const double ac = sqrt(pow(a_.x - c_.x, 2) + pow(a_.y - c_.y, 2));
  const double p = (ab + bc + ac) / 2;
  return sqrt(p * (p - ab) * (p - bc) * (p - ac));
}

rectangle_t Triangle::getFrameRect() const
{
  point_t min = {std::min(std::min(a_.x,b_.x),c_.x), std::min(std::min(a_.y,b_.y),c_.y)};
  point_t max = {std::max(std::max(a_.x,b_.x),c_.x), std::max(std::max(a_.y,b_.y),c_.y)};
  return rectangle_t {{(max.x + min.x) / 2, (max.y + min.y) / 2}, max.x - min.x, max.y - min.y};
}

void Triangle::move(const double dx, const double dy)
{
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
  c_.x += dx;
  c_.y += dy;
}

void Triangle::move(const point_t & pos)
{
  move(pos.x - getCenter().x, pos.y - getCenter().y);
}

void Triangle::showParams() const
{
  rectangle_t framingRect = getFrameRect();
  std::cout << "Triangle: center - {" << framingRect.pos.x << ","
      << framingRect.pos.y << "}\nWidth - " << framingRect.width
      << "\nHeight - " << framingRect.height << '\n'
      << "Area - " << getArea() << '\n';
}
