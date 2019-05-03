#include "triangle.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>


Triangle::Triangle(const point_t &a, const point_t &b, const point_t &c):
  a_(a),
  b_(b),
  c_(c),
  pos_({((a.x + b.x + c.x) / 3), ((a.y + b.y + c.y) / 3)})
{
  assert(((getAB() != 0) && (getBC() != 0) && (getCA() != 0)));
}

double Triangle::getArea() const
{
  double p;
  p = (getAB() + getBC() + getCA()) * 0.5;
  return sqrt(p * (p - getAB()) * (p - getBC()) * (p - getCA()));
}

void Triangle::move(double x, double y)
{
  a_.x += x;
  b_.x += x;
  c_.x += x;
  a_.y += y;
  b_.y += y;
  c_.y += y;
  pos_.x += x;
  pos_.y += y;
}

void Triangle::move(const point_t &point)
{
  const double x = point.x - pos_.x;
  const double y = point.y - pos_.y;
  move(x, y);
}

void Triangle::showCoordinates() const
{
  std::cout << "x: " << getA().x << "," << getA().y << "\n";
  std::cout << "y: " << getB().x << "," << getB().y << "\n";
  std::cout << "z: " << getC().x << "," << getC().y << "\n";
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
