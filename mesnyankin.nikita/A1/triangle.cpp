#include "triangle.hpp"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>


Triangle::Triangle(const point_t &a, const point_t &b, const point_t &c):
  a_(a),
  b_(b),
  c_(c),
  pos_({((a.x + b.x + c.x) / 3), ((a.y + b.y + c.y) / 3)})
{
  assert((getAB() + getBC() > getCA()) && (getBC() + getCA() > getAB()) && (getAB() + getCA() > getBC()));
  assert(((getAB() != 0) && (getBC() != 0) && (getCA() != 0)));
  assert(c.y != (a.y - b.y) / (a.x - b.x) * c.x + a.y - (a.y - b.y) / (a.x - b.x) * a.x);
}

double Triangle::getArea() const
{
  double p;
  p = (getAB() + getBC() + getCA()) * 0.5;
  return sqrt(p * (p - getAB()) * (p - getBC()) * (p - getCA()));
}

void Triangle::move(const double x, const double y)
{
  a_.x += x;
  b_.x += x;
  c_.x += x;
  a_.y += y;
  b_.y += y;
  c_.y += y;
  pos_ = {((a_.x + b_.x + c_.x) / 3), ((a_.y + b_.y + c_.y) / 3)};
}

void Triangle::move(const point_t &point)
{
  pos_ = point;
  a_.x += point.x - pos_.x;
  b_.x += point.x - pos_.x;
  c_.x += point.x - pos_.x;
  a_.y += point.y - pos_.y;
  b_.y += point.y - pos_.y;
  c_.y += point.y - pos_.y;
}

point_t Triangle::getA() const
{
  return a_;
}

point_t Triangle::getB() const
{
  return b_;
}

point_t Triangle::getC() const
{
  return c_;
}

point_t Triangle::getPos() const
{
  return pos_;
}

rectangle_t Triangle::getFrameRect() const
{
  double rMinX, rMinY, rMaxX, rMaxY;
  point_t rectangle_centre;
  rMaxX = std::max({a_.x, b_.x, c_.x});
  rMaxY = std::max({a_.y, b_.y, c_.y});
  rMinX = std::min({a_.x, b_.x, c_.x});
  rMinY = std::min({a_.y, b_.y, c_.y});
  rectangle_centre.x = (rMaxX + rMinX) / 2;
  rectangle_centre.y = (rMaxY + rMinY) / 2;
  return {rectangle_centre, rMaxX - rMinX, rMaxY - rMinY};
}

double Triangle::getAB() const
{
  return std::abs(sqrt(pow((getB().x - getA().x), 2) + pow((getB().y - getA().y), 2)));
}

double Triangle::getBC() const
{
  return std::abs(sqrt(pow((getC().x - getB().x), 2) + pow((getC().y - getB().y), 2)));
}

double Triangle::getCA() const
{
  return std::abs(sqrt(pow((getA().x - getC().x), 2) + pow((getA().y - getC().y), 2)));
}
