#include "triangle.hpp"
#include <algorithm>
#include <cassert>
#include <cmath>

Triangle::Triangle(const point_t& a, const point_t& b, const point_t& c):
  a_{a},
  b_{b},
  c_{c}
{
  assert(getArea() > 0);
}
  
double Triangle::getArea() const
{
  return (std::abs((a_.x - c_.x) * (b_.y - c_.y) - (b_.x - c_.x) * (a_.y - c_.y)) / 2);
}

rectangle_t Triangle::getFrameRect() const
{
  double left = std::min({a_.x, b_.x, c_.x});
  double right = std::max({a_.x, b_.x, c_.x});
  double top = std::min({a_.y, b_.y, c_.y});
  double bottom = std::max({a_.y, b_.y, c_.y});
  double width = right - left;
  double height = bottom - top;
  double x0 = (left + right) / 2;
  double y0 = (top + bottom) / 2;
  return {{x0, y0}, width, height};
}

point_t Triangle::getCenter() const
{
  return {(a_.x + b_.x + c_.x) / 3, (a_.y + b_.y + c_.y) / 3};
}

void Triangle::move(const point_t& point)
{
  point_t center = getCenter();
  move(point.x - center.x, point.y - center.y);
}

void Triangle::move(double x, double y)
{
  a_.x += x;
  b_.x += x;
  c_.x += x;
  a_.y += y;
  b_.y += y;
  c_.y += y;
}
