#include "triangle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cassert>

Triangle::Triangle(const point_t &pt1, const point_t &pt2, const point_t &pt3) :
  pos_({ (pt1.x + pt2.x + pt3.x) / 3 , (pt1.y + pt2.y + pt3.y) / 3 }),
  a_(pt1),
  b_(pt2),
  c_(pt3)
  
{
  assert((getArea() !=0) && "Point of triange must be different!");
}

double Triangle::getArea() const
{
  return ((std::abs(((a_.x - c_.x) * (b_.y - c_.y)) - ((a_.y - c_.y) * (b_.x - c_.x))) / 2));
}
rectangle_t Triangle::getFrameRect() const
{
  double min_x = std::min(std::min(a_.x, b_.x), c_.x);
  double min_y = std::min(std::min(a_.y, b_.y), c_.y);
  double h = std::fabs(std::max(std::max(a_.y, b_.y), c_.y) - min_x);
  double w = std::fabs(std::max(std::max(a_.x, b_.x), c_.x) - min_y);
  return rectangle_t{ w, h,pos_ };
}
point_t Triangle::move(const point_t &point)
{
  a_.x += point.x - pos_.x;
  b_.x += point.x - pos_.x;
  c_.x += point.x - pos_.x;
  a_.y += point.y - pos_.y;
  b_.y += point.y - pos_.y;
  c_.y += point.y - pos_.y;
  pos_ = point;
  return pos_;
}
point_t Triangle::move(double dx, double dy)
{
  pos_.x += dx;
  a_.x += dx;
  b_.x += dx;
  c_.x += dx;
  pos_.y += dy;
  a_.y += dy;
  b_.y += dy;
  c_.y += dy;
  return pos_;
}
void Triangle::print() const
{
  std::cout << '\n';
  std::cout << "Triangle \n ";
  std::cout << '\n';
  std::cout << "XG= " << pos_.x << ", " << "YG=" << pos_.y << std::endl;
  std::cout << "Ax= " << a_.x << ", " << "Ay= " << a_.y << std::endl;
  std::cout << "Bx= " << b_.x << ", " << "By= " << b_.y << std::endl;
  std::cout << "Cx= " << c_.x << ", " << "Cy= " << c_.y << std::endl;
  std::cout << '\n';
}
